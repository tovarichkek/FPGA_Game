module game (
  //--------- Clock & Resets                     --------//
    input  wire           pixel_clk ,  // Pixel clock 25,2 MHz
    input  wire           rst_n     ,  // Active low synchronous reset
  //--------- Buttons                            --------//
    input  wire           button_c  ,
    input  wire           button_u  ,
    input  wire           button_d  ,
    input  wire           button_r  ,
    input  wire           button_l  ,
  //--------- Accelerometer                      --------//
    input  wire  [7:0]    accel_data_x         ,
    input  wire  [7:0]    accel_data_y         ,
    output logic [7:0]    accel_x_end_of_frame ,
    output logic [7:0]    accel_y_end_of_frame ,
  //--------- Pixcels Coordinates                --------//
    input  wire  [9:0]    h_coord   ,
    input  wire  [9:0]    v_coord   ,
  //--------- VGA outputs                        --------//
    output wire  [3:0]    red       ,  // 4-bit color output
    output wire  [3:0]    green     ,  // 4-bit color output
    output wire  [3:0]    blue      ,  // 4-bit color output
  //--------- Switches for background colour     --------//
    input  wire  [2:0]    SW        ,
  //--------- Regime                             --------//
    output wire  [1:0]    demo_regime_status
);

//------------------------- Variables                    ----------------------------//
  //----------------------- Regime control               --------------------------//
    wire              change_regime ;
    reg       [1:0]   regime_store  ;         // Two demonstration regimes
  //----------------------- Counters                     --------------------------//
    parameter         FRAMES_PER_ACTION = 2;  // Action delay
    logic     [31:0]  frames_cntr ;
    logic             end_of_frame;           // End of frame's active zone
  //----------------------- Accelerometr                 --------------------------//
    parameter     ACCEL_X_CORR = 8'd3;        // Accelerometer x correction
    parameter     ACCEL_Y_CORR = 8'd1;        // Accelerometer y correction
    wire   [7:0]  accel_data_x_corr  ;        // Accelerometer x corrected data
    wire   [7:0]  accel_data_y_corr  ;        // Accelerometer y corrected data
  //----------------------- Object (Stick)               --------------------------//
    //   0 1         X
    //  +------------->
    // 0|
    // 1|  P.<v,h>-> width
    //  |   |
    // Y|   |
    //  |   V heigh
    //  |
    //  V
    parameter     object_width  = 4  ;         // Horizontal width
    parameter     object_height = 10 ;         // Vertical height
    logic         object_draw        ;         // Is Sber Logo or demo object coordinate (with width and height)?
    logic [9:0]   object_h_coord     ;         // Object Point(P) horizontal coodrinate
    logic [9:0]   object_v_coord     ;         // Object Point(P) vertical coordinate
    logic [9:0]   object_h_speed     ;         // Horizontal Object movement speed
    logic [9:0]   object_v_speed     ;         // Vertical Object movement speed
  //----------------------- Sber logo timer              --------------------------//
    logic [31:0]  sber_logo_counter     ;      // Counter is counting how long showing Sber logo
    wire          sber_logo_active      ;      // Demonstrating Sber logo
    // Read only memory (ROM) for sber logo file
    wire  [11:0]  sber_logo_rom_out     ;
    wire  [13:0]  sber_logo_read_address;
//------------------------- End of Frame                 ----------------------------//
  // We recount game object once at the end of display counter //
  always_ff @( posedge pixel_clk ) begin
    if ( !rst_n )
      end_of_frame <= 1'b0;
    else
      end_of_frame <= (h_coord==10'd639) && (v_coord==10'd479); // 640 x 480
  end
  always_ff @( posedge pixel_clk ) begin
    if ( !rst_n )
      frames_cntr <= 0;
    else if ( frames_cntr == FRAMES_PER_ACTION )
      frames_cntr <= 0;
    else if (end_of_frame)
      frames_cntr <= frames_cntr + 1;
  end

//------------------------- Regime control               ----------------------------//
  always @ ( posedge pixel_clk ) begin //Right now there are 2 regimes
    if ( !rst_n ) begin
      regime_store <= 2'b11;
    end
    else if (change_regime && (regime_store == 2'b10)) begin
      regime_store <= 2'b11;
    end
    else if ( change_regime ) begin
      regime_store <= regime_store - 1'b1;
    end
  end
  assign change_regime      = button_c    ;
  assign demo_regime_status = regime_store;

//------------------------- Accelerometr at the end of frame-------------------------//
  always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin
      accel_x_end_of_frame <= 8'h0000000;
      accel_y_end_of_frame <= 8'h0000000;
    end
    else if ( end_of_frame && (frames_cntr == 0) ) begin
      accel_x_end_of_frame <= accel_data_x_corr;
      accel_y_end_of_frame <= accel_data_y_corr;
    end
  end
  // Accelerometr corrections
  assign accel_data_x_corr = accel_data_x + ACCEL_X_CORR;
  assign accel_data_y_corr = accel_data_y + ACCEL_Y_CORR;
//------------------------- Object movement in 2 regimes  ----------------------------//
  assign object_v_speed = 10'd1;
  assign object_h_speed = 10'd1;
  always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin // Put object in the center
      object_h_coord <= 318;
      object_v_coord <= 235;
    end
    else if ( end_of_frame && (frames_cntr == 0) ) begin
      if (regime_store == 2'b11) begin  // Buttons regime
        if ( button_l ) begin           // Moving left
          if ( object_h_coord < object_h_speed)
            object_h_coord <= 0;
          else
            object_h_coord <= object_h_coord - object_h_speed;
        end
        else if ( button_r ) begin
          if ( object_h_coord + object_h_speed + object_width >= 639 )
            object_h_coord <= 639 - object_width;
          else
            object_h_coord <= object_h_coord + object_h_speed;
        end
        //
        if      ( button_u ) begin
          if ( object_v_coord < object_v_speed )
            object_v_coord <= 0;
          else
            object_v_coord <= object_v_coord - object_v_speed;
        end
        else if ( button_d  ) begin
          if ( object_v_coord + object_v_speed + object_height >= 479 )
            object_v_coord <= 479 - object_height;
          else
            object_v_coord <= object_v_coord + object_v_speed;
        end
      end
      else if (regime_store == 2'b10) begin  // Accelerometer regime
        if      ( !accel_data_y_corr[7] && ( accel_data_y_corr != 8'h00 )) begin
          if ( object_h_coord < object_h_speed)
            object_h_coord <= 0;
          else
            object_h_coord <= object_h_coord - object_h_speed;
        end
        else if ( accel_data_y_corr[7] && ( accel_data_y_corr != 8'h00 ) ) begin
          if ( object_h_coord + object_h_speed + object_width >= 639 )
            object_h_coord <= 639 - object_width;
          else
            object_h_coord <= object_h_coord + object_h_speed;
        end
        //
        if      ( accel_data_x_corr[7] && ( accel_data_x_corr != 8'h00 ) ) begin
          if ( object_v_coord < object_v_speed )
            object_v_coord <= 0;
          else
            object_v_coord <= object_v_coord - object_v_speed;
        end
        else if (!accel_data_x_corr[7] && ( accel_data_x_corr != 8'h00 ) )  begin
          if ( object_v_coord + object_v_speed + object_height >= 479 )
            object_v_coord <= 479 - object_height;
          else
            object_v_coord <= object_v_coord + object_v_speed;
        end
      end
    end
  end

//------------- Sber logo on reset                               -------------//
  //----------- How long to show Sber logo                       -----------//
    always @ ( posedge pixel_clk ) begin
      if      ( !rst_n )
        sber_logo_counter <= 32'b0;
      else if ( sber_logo_counter <= 32'd1_00000000 )
        sber_logo_counter <= sber_logo_counter + 1'b1;
    end
    assign sber_logo_active = ( sber_logo_counter < 32'd1_00000000 );
  //----------- SBER logo ROM                                    -----------//
    // Screen resoulution is 640x480, the logo size is 128x128. We need to put the logo in the center.
    // Logo offset = (640-128)/2=256 from the left edge; Logo v coord = (480-128)/2 = 176
    // Cause we need 1 clock for reading, we start erlier
    assign sber_logo_read_address = {4'b0, h_coord} - 14'd255 + ({4'b0, v_coord} - 14'd176)*14'd128;

    //for picture with size 128x128 we need 16384 pixel information
    sber_logo_rom sber_logo_rom (
      .addr ( sber_logo_read_address ),
      .word ( sber_logo_rom_out      )
    );
//____________________________________________________________________________//

//------------- RGB MUX outputs                                  -------------//
  always_comb begin
    if ( sber_logo_active ) begin
      object_draw = (h_coord >= 10'd256) & (h_coord < 10'd384) & (v_coord >= 10'd176) & (v_coord < 10'd304) & ~(sber_logo_rom_out[11:0]==12'h000); // Logo size is 128x128 Pixcels
    end
    else begin
      object_draw = ( h_coord >= object_h_coord ) & ( h_coord <= (object_h_coord + object_width  )) &
                    ( v_coord >= object_v_coord ) & ( v_coord <= (object_v_coord + object_height ));
    end
  end

  assign  red     = object_draw ? ( ~sber_logo_active ? 4'hf : sber_logo_rom_out[3:0]  ) : (SW[0] ? 4'h8 : 4'h0);
  assign  green   = object_draw ? ( ~sber_logo_active ? 4'hf : sber_logo_rom_out[7:4]  ) : (SW[1] ? 4'h8 : 4'h0);
  assign  blue    = object_draw ? ( ~sber_logo_active ? 4'hf : sber_logo_rom_out[11:8] ) : (SW[2] ? 4'h8 : 4'h0);
//____________________________________________________________________________//
endmodule
