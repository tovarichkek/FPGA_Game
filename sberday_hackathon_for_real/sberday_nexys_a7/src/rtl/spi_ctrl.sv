module spi_ctrl (
    input  wire          clk_5mhz0d   ,
    input  wire          clk_5mhz180d ,
    input  wire          rst_n        ,
  //- Values -//
    output logic [7:0]   x_axis       ,
    output logic [7:0]   y_axis       ,
  //- PADS   -//
    input  logic         MISO         ,
    output logic         MOSI         ,
    output logic         CSN          ,
    output logic         SCLK
);
//------------- ACCEL INFO                                       -------------//
  //- Commands  -//
  localparam WRITE_REGISTER = 8'h0A;
  localparam READ_REGISTER  = 8'h0B;
  //- Addresses -//
  localparam POWER_CTL_ADDR = 8'h2D;
  localparam XDATA_ADDR     = 8'h08;
  localparam YDATA_ADDR     = 8'h09;
//------------- Variables                                        -------------//
  //- PARAMETERS -//
    parameter CNFG_WORDS_NUM = 1;
    parameter WRITE_BITS     = 16;
    parameter READ_BITS      = 16;
  //- Configuration -//
    logic [3:0] cnfg_addr_cntr ;
    logic [7:0] cnfg_addr ;
    logic [7:0] read_addr ;
    logic [7:0] cnfg_val  ;
    wire        cnfg_done ;
  //- Reading -//
    logic read_addr_cntr;
  //- FSM -//
    enum logic [3:0] {
      IDLE           ,
      TRANSMITTING   ,
      RECEIVING      ,
      UPDATE
    } spi_state, spi_nstate;
    //
    logic rx_active          ; // Receiver bit cntr incr
    logic tx_active          ; // Transmitter bit cntr incr
    logic transmit_write     ; // Use configuration address & data
    logic transmit_read      ; // Use reading address
    logic cnfg_addr_cntr_inc ; // Increment configuration words counter
    logic rx_update          ; // Increment reading loop counter & write one of the reading register
    logic receiving_start    ; // End of transmiting part in reading operation
    logic transaction_active ; // Transaction is active (for CS and SCLK)
  //- Transmiter -//
    logic [23:0] tx_data_sff ; // Trasmitter data shift register
    logic [4:0]  tx_cntr     ; // Transmitted data bit counter
    wire         tx_done     ; // Transmitter counter is 0
  //- Receiver -//
    logic [7:0]  rx_data_sff ; // Receiver data shift register
    logic [2:0]  rx_cntr     ; // Received data bit counter
    wire         rx_done     ; // Received counter is 0

//------------- Configuration address & data multiplexor         -------------//
  always_comb begin
    case (cnfg_addr_cntr)
      4'd0    : {cnfg_addr, cnfg_val} = {POWER_CTL_ADDR, 8'h02};  // Turn on measurment mode
      default : {cnfg_addr, cnfg_val} = 16'hFF00;                 // Not supported address
    endcase
  end
  always_ff @( posedge clk_5mhz0d ) begin
    if      ( !rst_n )
      cnfg_addr_cntr <= 0;
    else if ( cnfg_addr_cntr_inc )
      cnfg_addr_cntr <= cnfg_addr_cntr + 1;
  end
  assign cnfg_done = (cnfg_addr_cntr == CNFG_WORDS_NUM);          // Configuration done
//------------- Reading address mulitplexor & registers          -------------//
  always_comb begin // Multiplexor
    case (read_addr_cntr)
      1'd0    : read_addr = XDATA_ADDR;
      1'd1    : read_addr = YDATA_ADDR;
    endcase
  end
  always_ff @( posedge clk_5mhz0d ) begin // Addresses loop
    if      ( !rst_n )
      read_addr_cntr <= 0;
    else if ( rx_update )
      read_addr_cntr <= read_addr_cntr + 1;
  end
  //
  always_ff @( posedge clk_5mhz0d ) begin
    if      ( !rst_n )
      x_axis <= 0;
    else if ( rx_update && (!read_addr_cntr) )
      x_axis <= rx_data_sff;
  end

  always_ff @( posedge clk_5mhz0d ) begin
    if      ( !rst_n )
      y_axis <= 0;
    else if ( rx_update && read_addr_cntr )
      y_axis <= rx_data_sff;
  end

//------------- SPI FSM                                        -------------//
  always_ff @( posedge clk_5mhz0d ) begin
    if ( !rst_n )
      spi_state <= IDLE;
    else
      spi_state <= spi_nstate;
  end
  always_comb begin
    spi_nstate         = IDLE;
    rx_active          = 1'b0;
    tx_active          = 1'b0;
    transmit_write     = 1'b0;
    transmit_read      = 1'b0;
    receiving_start    = 1'b0;
    cnfg_addr_cntr_inc = 1'b0;
    rx_update          = 1'b0;
    transaction_active = 1'b0;
    case ( spi_state )
      IDLE: begin
        if ( cnfg_done ) begin
          transmit_read  = 1'b1;
        end
        else begin
          transmit_write = 1'b1;
        end
        spi_nstate = TRANSMITTING;
      end
      //
      TRANSMITTING: begin
        if ( tx_done ) begin
          if ( cnfg_done ) begin
            spi_nstate         = RECEIVING ;
            receiving_start    = 1'b1      ;
          end
          else begin
            spi_nstate         = IDLE      ;
            cnfg_addr_cntr_inc = 1'b1      ;
          end
        end
        else begin
          spi_nstate        = TRANSMITTING ;
          tx_active         = 1'b1         ;
        end
        transaction_active  = 1'b1         ;
      end
      //
      RECEIVING: begin
        if (rx_done ) begin
          spi_nstate       = UPDATE    ;
        end
        else begin
          spi_nstate       = RECEIVING ;
        end
        rx_active          = 1'b1      ;
        transaction_active = 1'b1      ;
      end
      UPDATE: begin
        spi_nstate = IDLE ;
        rx_update  = 1'b1 ;
      end
    endcase
  end

//------------- Transmiter                                       -------------//
  always @ ( posedge clk_5mhz0d ) begin
    if      ( transmit_write ) begin // Configuration start
      tx_data_sff <= { WRITE_REGISTER, cnfg_addr, cnfg_val };
      tx_cntr     <= 5'd23;
    end
    else if ( transmit_read  ) begin // Reading start
      tx_data_sff <= { READ_REGISTER , read_addr, 8'h00    };
      tx_cntr     <= 5'd15;
    end
    else if ( tx_active && (tx_cntr != 5'd0) ) begin // Transmitting phase
      tx_data_sff <= {tx_data_sff[22:0], 1'b0};
      tx_cntr     <= tx_cntr - 1;
    end
  end
  assign tx_done = ( tx_cntr == 5'd0 );

//------------- Receiver                                        -------------//
  always @ ( posedge clk_5mhz0d ) begin
    if      ( receiving_start ) begin
      rx_cntr     <= 5'd7;
    end
    else if ( rx_active && (rx_cntr != 5'd0) ) begin
      rx_data_sff <= {rx_data_sff, MISO};
      rx_cntr     <= rx_cntr - 1;
    end
    else if ( rx_active && (rx_cntr == 5'd0) ) begin
      rx_data_sff <= {rx_data_sff, MISO};
    end
  end
  assign rx_done = ( rx_cntr == 5'd0 );

//------------- PADS                                             -------------//
  assign SCLK = ( transaction_active ) ? clk_5mhz180d : 1'b0;
  assign CSN  = ( transaction_active ) ? 1'b0 : 1'b1;
  assign MOSI = tx_data_sff[23];

endmodule