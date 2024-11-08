module sberday_nexys_a7_svga (
  //----------- CLOCK                                            -------------//
    input   logic            CLK100MHZ ,
  //----------- Switches                                         -------------//
    input   logic  [15:0]    SW        ,
  //----------- LEDs                                             -------------//
    output  logic  [15:0]    LED       ,
    output  logic            LED16_R, LED16_G, LED16_B,
    output  logic            LED17_R, LED17_G, LED17_B,
  //----------- Seven Segments Indicators                        -------------//
    output  logic            DP, CG, CF, CE, CD, CC, CB, CA,
    output  logic  [ 7:0]    AN,
  //----------- Buttons                                          -------------//
    input   logic            BTNC      ,
    input   logic            BTNU      ,
    input   logic            BTNL      ,
    input   logic            BTNR      ,
    input   logic            BTND      ,
    input   logic            CPU_RESETN,
  //----------- ACCEL                                            -------------//
    input   wire             ACL_MISO  ,
    output  wire             ACL_MOSI  ,
    output  logic            ACL_SCLK  ,
    output  logic            ACL_CSN   ,
  //----------- VGA                                              -------------//
    output  logic  [ 3:0]    VGA_R     ,
    output  logic  [ 3:0]    VGA_G     ,
    output  logic  [ 3:0]    VGA_B     ,
    output  logic            VGA_HS    ,
    output  logic            VGA_VS
);
//------------- Signals declaration                              -------------//
  //----------- Clocks                                           -----------//
    wire          pixel_clk    ;     // 36 MHz, phase 0 degrees
    wire          clk_5mhz0d   ;     // spi_clk     5 MHz, phase 0 degrees
    wire          clk_5mhz180d ;     // spi_clk_out 5 MHz, phase 270 degrees
    wire          pll_locked   ;
    wire          pll_rst_n    ;
    wire          rst_n        ;
  //----------- VGA Controller                                   -----------//
    wire [31:0]   h_coord, v_coord;         // Pixcels Coordinates
    wire [3:0]    red, green, blue; // Pixcels Colors
    // Timing signals - don't touch these:
    wire          h_sync, v_sync;     // Horizontal & Vertical synchronization
    wire          disp_enbl;          // Image output is allowed
  //----------- Buttons state                                    -----------//
    logic         button_c, button_c_d, button_c_u;
    logic         button_u, button_u_d, button_u_u;
    logic         button_d, button_d_d, button_d_u;
    logic         button_l, button_l_d, button_l_u;
    logic         button_r, button_l_r, button_r_u;
  //----------- Seven Segments Indicators                        -----------//
    wire  [31:0]  sevseg_32bit_hex_val;
  //----------- Accelerometor                                    -----------//
    wire [7:0]     accel_data_x;     // FPGA board accelerometer X data
    wire [7:0]     accel_data_y;     // FPGA board accelerometer Y data
    wire [7:0]     accel_x_end_of_frame;
    wire [7:0]     accel_y_end_of_frame;
  //----------- Demo                                             -----------//
    wire [1:0]      demo_regime_status;

  //----------- Clock & Reset                                    -----------//
    //--------- PLL                                              ---------//
      clk_wiz_0 clk_gen (
        .clk_in1  ( CLK100MHZ       ),
        .resetn   ( pll_rst_n       ),
        .clk_out1 ( pixel_clk       ), //36 MHz
        .clk_out2 ( clk_5mhz0d      ),
        .clk_out3 ( clk_5mhz180d    ),
        .locked   ( pll_locked      )
      );

      reset_button_debouncer reset (
        .clk_100mhz   ( CLK100MHZ  ),
        .clk_5mhz     ( clk_5mhz0d ),
        .reset_button ( CPU_RESETN ),
        .pll_rst_n    ( pll_rst_n  ),
        .pll_locked   ( pll_locked ),
        .rst_n        ( rst_n      )
      );
//____________________________________________________________________________//

//------------- IO Pads assertions                               -------------//
  //----------- Debouncers for Buttons                           -----------//
    button_debouncer dbns_center (
      .clk         ( pixel_clk  ),
      .arst_n      ( rst_n      ),
      .sw_i        ( BTNC       ),
      .sw_state_o  ( button_c   ),
      .sw_down_o   ( button_c_d ),
      .sw_up_o     ( button_c_u )
    );
    button_debouncer dbns_up (
      .clk         ( pixel_clk  ),
      .arst_n      ( rst_n      ),
      .sw_i        ( BTNU       ),
      .sw_state_o  ( button_u   ),
      .sw_down_o   ( button_u_d ),
      .sw_up_o     ( button_u_u )
    );
    button_debouncer dbns_left (
      .clk         ( pixel_clk  ),
      .arst_n      ( rst_n      ),
      .sw_i        ( BTNL       ),
      .sw_state_o  ( button_l   ),
      .sw_down_o   ( button_l_d ),
      .sw_up_o     ( button_l_u )
    );
    button_debouncer dbns_right (
      .clk         ( pixel_clk  ),
      .arst_n      ( rst_n      ),
      .sw_i        ( BTNR       ),
      .sw_state_o  ( button_r   ),
      .sw_down_o   ( button_r_d ),
      .sw_up_o     ( button_r_u )
    );
    button_debouncer dbns_down (
      .clk         ( pixel_clk  ),
      .arst_n      ( rst_n      ),
      .sw_i        ( BTND       ),
      .sw_state_o  ( button_d   ),
      .sw_down_o   ( button_d_d ),
      .sw_up_o     ( button_d_u )
    );
  //----------- LEDs                                             -----------//
      assign LED [15:8] = SW[15:8];
      assign LED [7:3] = {button_u, button_l, button_r, button_d, button_c};
      assign LED [1:0] = demo_regime_status;
      //RGB
      assign {LED16_R, LED16_G, LED16_B} = 3'b000;
      assign {LED17_R, LED17_G, LED17_B} = 3'b000;
  //----------- Seven Segments Indicators                        -----------//
    // refresh frequency of about 1 KHz to 60Hz we need to devide by 8 //
    reg [12:0] digital_clock_divider;
    always_ff @( posedge clk_5mhz0d ) begin
      if ( !rst_n )
        digital_clock_divider <= 0;
      else
        digital_clock_divider <= digital_clock_divider + 1;
    end
    sevseg_ctrl seven_segments_controller (
      .clk                    ( digital_clock_divider [12]   ),
      .arst_n                 ( rst_n                        ),
      .sevseg_32bit_hex_val   ( sevseg_32bit_hex_val         ),
      .seg_active_n           ( {CG, CF, CE, CD, CC, CB, CA} ),
      .don_active_n           ( DP                           ),
      .anodes                 ( AN                           )
    );
    assign sevseg_32bit_hex_val = {8'b0, accel_x_end_of_frame, 8'b0, accel_y_end_of_frame}; //32'hDEADBEEF;
  //----------- Accelerometer                                    -----------//
    accelerometr_ctrl accelerometr_ctrl (
      //Clocks & Resets
        .spi_clk            ( clk_5mhz0d    ),  //  5 MHz, phase   0 degrees
        .spi_clk_out        ( clk_5mhz180d  ),  //  5 MHz, phase 270 degrees
        .arst_n             ( rst_n         ),
      //Accelerometer values
        .accel_data_x       ( accel_data_x  ),
        .accel_data_y       ( accel_data_y  ),
      //Accelerometer IOs
        .ACL_CSN            ( ACL_CSN       ),
        .ACL_SCLK           ( ACL_SCLK      ),
        .ACL_MISO           ( ACL_MISO      ),
        .ACL_MOSI           ( ACL_MOSI      )
    );
//____________________________________________________________________________//

//------------- Demo module                                      -------------//
  game game_demo (
    //--------------------- Clock & Reset                ----------------------------//
      .pixel_clk              ( pixel_clk          ),
      .rst_n                  ( rst_n              ),
    //--------------------- Accelerometer                ----------------------------//
      .accel_data_x           ( accel_data_x         ),
      .accel_data_y           ( accel_data_y         ),
      .accel_x_end_of_frame   ( accel_x_end_of_frame ),
      .accel_y_end_of_frame   ( accel_y_end_of_frame ),
    //--------------------- Buttons                      ----------------------------//
      .button_c               ( button_c           ),
      .button_u               ( button_u           ),
      .button_d               ( button_d           ),
      .button_r               ( button_r           ),
      .button_l               ( button_l           ),
    //--------------------- Pixcels Coordinates          ----------------------------//
      .h_coord                ( h_coord[10:0]      ),  // only bottom 11 bits needed to count to 800
      .v_coord                ( v_coord[ 9:0]      ),  // only bottom 10 bits needed to count to 600
    //--------------------- VGA outputs from demo        ----------------------------//
      .red                    ( red                ),  // 4-bit color output
      .green                  ( green              ),  // 4-bit color output
      .blue                   ( blue               ),  // 4-bit color output
    //--------------------- Switches for demo            ----------------------------//
      .SW                     ( SW [2:0]           ),  // We are using switches to change background
    //--------------------- Demo regime status           ----------------------------//
      .demo_regime_status     ( demo_regime_status )   // Red led on the board which show REGIME
  );
//____________________________________________________________________________//

//------------- VGA controller                                   -------------//
    display_ctrl display_ctrl (
      .pixel_clk  ( pixel_clk ), // Pixel clock 25.2MHz
      .rst_n      ( rst_n     ), // Active low synchronous reset
      .h_sync     ( h_sync    ), // horizontal sync signal
      .v_sync     ( v_sync    ), // vertical sync signal
      .disp_enbl  ( disp_enbl ), // display enable (0 = all colors must be blank)
      .h_coord    ( h_coord   ), // horizontal pixel coordinate
      .v_coord    ( v_coord   )  // vertical pixel coordinate
    );

    //--------- VGA reg                                         -----------//
      always @(posedge pixel_clk) begin
        if (disp_enbl == 1'b1) begin
          VGA_R <= red  ;
          VGA_B <= blue ;
          VGA_G <= green;
        end
        else begin
          VGA_R <= 4'd0;
          VGA_B <= 4'd0;
          VGA_G <= 4'd0;
        end
          VGA_HS <= h_sync;
          VGA_VS <= v_sync;
      end
//____________________________________________________________________________//

endmodule
