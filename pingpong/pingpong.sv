module pingpong (
  //--------- Clock & Resets                     --------//
    input  wire           pixel_clk ,  // Pixel clock 36 MHz
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
    input  wire  [9:0]   h_coord   ,
    input  wire  [9:0]   v_coord   ,
  //--------- VGA outputs                        --------//
    output wire  [3:0]    red       ,  // 4-bit color output
    output wire  [3:0]    green     ,  // 4-bit color output
    output wire  [3:0]    blue      ,  // 4-bit color output
  //--------- Switches for background colour     --------//
    input  wire  [8:0]    SW        ,
  //--------- Regime                             --------//
    output wire           regime_status,
    output wire  [6:0]    p1_counter,
    output wire  [6:0]    p2_counter
);

//------------------------- Variables                    ----------------------------//
  //----------------------- Regime control               --------------------------//
    wire              change_regime ;
    reg               regime_store  ;         // Two demonstration regimes
  //----------------------- Counters                     --------------------------//
    parameter         FRAMES_PER_ACTION = 2;  // Action delay
    logic     [31:0]  frames_cntr ;
    logic             end_of_frame;           // End of frame's active zone
  //----------------------- Accelerometr                 --------------------------//
    parameter     ACCEL_X_CORR = 8'd120;        // Accelerometer x correction
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
    logic         board1;
    logic         board2;
    logic         ball;

    parameter     board_width  = 100 ;        // Horizontal width
    parameter     board_height  = 20  ;         // Vertical height
    parameter     board_speed   = 20  ;         // Vertical Object movement speed

    logic [9:0]   board1_h_coord     ;         // Object Point(P) horizontal coodrinate
    logic [9:0]   board1_v_coord     ;         // Object Point(P) vertical coordinate

    logic [9:0]   board2_h_coord     ;         // Object Point(P) horizontal coodrinate
    logic [9:0]   board2_v_coord     ;         // Object Point(P) vertical coordinate


    parameter     ball_width  = 16 ;         // Horizontal width
    parameter     ball_height = 16 ;         // Vertical height
    logic [9:0]   ball_h_coord     ;         // Object Point(P) horizontal coodrinate
    logic [9:0]   ball_v_coord     ;         // Object Point(P) vertical coordinate
    parameter     ball_h_speed = 8  ;         // Horizontal Object movement speed
    parameter     ball_v_speed = 10  ;       // Vertical Object movement speed
    logic         x_direction = 1'b0 ;
    logic [1:0]   y_direction = 2'b10 ;

    logic [31:0]  rand_mod    = 32'd10  ; 
    logic [9:0]   delta_speed = 10'b0 ;

  //----------------------- Point counters               ----------------------------//
    logic  [6:0]    p1_count;
    logic  [6:0]    p2_count;
    
//------------------------- End of Frame                 ----------------------------//
  // We recount game object once at the end of display counter //
    always @( posedge pixel_clk ) begin
        if ( !rst_n )
            end_of_frame <= 1'b0;
        else
            end_of_frame <= (h_coord == 10'd799) && (v_coord == 10'd599); // 799 x 599
    end
    always @( posedge pixel_clk ) begin
        if ( !rst_n )
            frames_cntr <= 0;
        else if ( frames_cntr == FRAMES_PER_ACTION )
            frames_cntr <= 0;
        else if (end_of_frame)
            frames_cntr <= frames_cntr + 1;
    end

//------------------------- Regime control               ----------------------------//
  always @ ( posedge change_regime ) begin
          regime_store <= 1'b1 - regime_store;
  end 
  assign change_regime      = button_c    ;
  assign regime_status      = regime_store;

//------------------------- Accelerometr at the end of frame-------------------------//
  always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin
      accel_x_end_of_frame <= 8'h0;
      accel_y_end_of_frame <= 8'h0;
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
  always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin // Put object in the center
      board1_h_coord <= 350;
      board1_v_coord <= 0;
      board2_h_coord <= 350;
      board2_v_coord <= 580;
    end
    else if ( end_of_frame && (frames_cntr == 0) ) begin
      if (regime_store == 1'b1) begin  // Buttons regime
        if ( button_l ) begin           // Moving left
          if ( board1_h_coord < board_speed)
            board1_h_coord <= 0;
          else
            board1_h_coord <= board1_h_coord - board_speed;
        end
        else if ( button_d ) begin
          if ( board1_h_coord + board_speed + board_width >= 10'd799 )
            board1_h_coord <= 10'd799 - board_width;
          else
            board1_h_coord <= board1_h_coord + board_speed;
        end
        //
        if      ( button_u ) begin           // Moving left
          if ( board2_h_coord < board_speed)
            board2_h_coord <= 0;
          else
            board2_h_coord <= board2_h_coord - board_speed;
        end
        else if ( button_r  ) begin
          if ( board2_h_coord + board_speed + board_width >= 10'd799 )
            board2_h_coord <= 10'd799 - board_width;
          else
            board2_h_coord <= board2_h_coord + board_speed;
        end
      end
      else if (regime_store == 1'b0) begin  // Accelerometer regime
        if      ( !accel_data_y_corr[7] && ( accel_data_y_corr != 8'h00 )) begin
          if ( board1_h_coord < board_speed)
            board1_h_coord <= 0;
          else
            board1_h_coord <= board1_h_coord - board_speed;
        end
        else if ( accel_data_y_corr[7] && ( accel_data_y_corr != 8'h00 ) ) begin
          if ( board1_h_coord + board_speed + board_width >= 10'd799 )
            board1_h_coord <= 10'd799 - board_width;
          else
            board1_h_coord <= board1_h_coord + board_speed;
        end
      end
    end
  end

  always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin 
      ball_h_coord   <= 390;
    end
    else if ( end_of_frame && (frames_cntr == 0) ) begin
    if ( x_direction ) begin
      if ( ball_h_coord < ball_h_speed + delta_speed) begin
        ball_h_coord <= 0;
        x_direction  <= ~x_direction;
      end
      else
        ball_h_coord <= ball_h_coord - ball_h_speed - delta_speed;
    end
    else begin
      if ( ball_h_coord + ball_h_speed + delta_speed + ball_width >= 10'd799 ) begin
        ball_h_coord <= 10'd799 - ball_width;
        x_direction  <= ~x_direction;
      end
      else
        ball_h_coord <= ball_h_coord + ball_h_speed + delta_speed;
    end
    end
  end

  always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin
      ball_v_coord   <= 290;
    end
    else if ( end_of_frame && (frames_cntr == 0) && regime_store ) begin
      if (y_direction[1]) begin
        if (button_u | button_d | button_l | button_r) begin
          y_direction[1] <= 1'b0;
          rand_mod <= $random;
          delta_speed[3:0] <= rand_mod[3:0];
        end
      end
      else if ( y_direction[0] ) begin    
        if ( (ball_v_coord - ball_v_speed < board_height) & (ball_h_coord + ball_width > board1_h_coord & ball_h_coord < board1_h_coord + board_width ) ) begin
          ball_v_coord <= board_height;
          y_direction[0] <= ~y_direction[0];
          rand_mod <= $random;
          delta_speed[3:0] <= rand_mod[3:0];
        end      
        else if ( ball_v_coord < ball_v_speed) begin
          // player 1 lost
          p2_count = p2_count + 1;
          $display("%d:%d", p1_count, p2_count);
          ball_v_coord <= 10'd290;
          y_direction  <= 2'b10;
        end
        else
          ball_v_coord <= ball_v_coord - ball_v_speed;
        end
      else begin
        if ( (ball_v_coord + ball_v_speed + ball_height > 10'd599 - board_height) & (ball_h_coord + ball_width > board2_h_coord & ball_h_coord < board2_h_coord + board_width )) begin
          ball_v_coord <= 10'd599 - board_height - ball_height;
          y_direction[0] <= ~y_direction[0];
          rand_mod <= $random;
          delta_speed[3:0] <= rand_mod[3:0];
        end  
        else if ( ball_v_coord + ball_v_speed + ball_height >= 10'd599 ) begin
          // player 2 lost
          p1_count <= p1_count + 1;
          $display("%d:%d", p1_count, p2_count);
          ball_v_coord <= 10'd290;
          y_direction  <= 2'b11;
        end
        else
          ball_v_coord <= ball_v_coord + ball_v_speed;
      end
    end
  end

    always @ ( posedge pixel_clk ) begin
    if ( !rst_n ) begin
      ball_v_coord   <= 290;
    end
    else if ( end_of_frame && (frames_cntr == 0) && ~regime_store) begin
      y_direction[1] <= 1'b0;
      if ( y_direction[0] ) begin    
        if ( (ball_v_coord - ball_v_speed < board_height) & (ball_h_coord + ball_width > board1_h_coord & ball_h_coord < board1_h_coord + board_width ) ) begin
          ball_v_coord   <= board_height;
          y_direction[0] <= ~y_direction[0];
        end      
        else if ( ball_v_coord < ball_v_speed) begin
          // player 1 lost
          $display("you lose");
          ball_v_coord <= 10'd590;
          y_direction  <= 2'b00;
        end
        else
          ball_v_coord <= ball_v_coord - ball_v_speed;
        end
      else begin
        if ( (ball_v_coord + ball_v_speed + ball_height > 10'd599 - board_height) & (ball_h_coord + ball_width > board2_h_coord & ball_h_coord < board2_h_coord + board_width )) begin
          ball_v_coord   <= 10'd599 - board_height - ball_height;
          y_direction[0] <= ~y_direction[0];
        end  
        else if ( ball_v_coord + ball_v_speed + ball_height >= 10'd599 ) begin
            ball_v_coord <= 10'd599 - ball_height;
            y_direction  <= 2'b01;
        end
        else
          ball_v_coord <= ball_v_coord + ball_v_speed;
      end
    end
  end

  assign p1_counter = p1_count;
  assign p2_counter = p2_count;

//------------- RGB MUX outputs                                  -------------//
  always_comb begin
    if (1'b1) begin
        board1 = (( h_coord >= board1_h_coord ) && ( h_coord <= (board1_h_coord + board_width  )) && ( v_coord >= board1_v_coord ) && ( v_coord <= (board1_v_coord + board_height ))) ;
        board2 = (( h_coord >= board2_h_coord ) && ( h_coord <= (board2_h_coord + board_width  )) && ( v_coord >= board2_v_coord ) && ( v_coord <= (board2_v_coord + board_height )) && regime_store) ;
        ball   = (( h_coord >= ball_h_coord )   && ( h_coord <= (ball_h_coord + ball_width  ))    && ( v_coord >= ball_v_coord )   && ( v_coord <= (ball_v_coord + ball_height ))) ;
    end
  end

  assign  red     = ball ? (SW[3] ? 4'hf : 4'hf) : ( (board1 | board2) ? (SW[6] ? 4'hc : 4'hf) : ( SW[0] ? 4'h8 : 4'h0 ) );
  assign  green   = ball ? (SW[4] ? 4'hf : 4'h0) : ( (board1 | board2) ? (SW[7] ? 4'hc : 4'hf) : ( SW[1] ? 4'h8 : 4'h0 ) );
  assign  blue    = ball ? (SW[5] ? 4'hf : 4'h0) : ( (board1 | board2) ? (SW[8] ? 4'hc : 4'hf) : ( SW[2] ? 4'h8 : 4'h0 ) );
//____________________________________________________________________________//
endmodule
