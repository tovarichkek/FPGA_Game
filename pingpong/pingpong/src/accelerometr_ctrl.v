module accelerometr_ctrl (
  //-------------------- CLOCK        ----------------//
    input             spi_clk           ,  //  5 MHz, phase   0 degrees
    input             spi_clk_out       ,  //  5 MHz, phase 180 degrees
  //-------------------- ARSTn        ----------------//
    input             arst_n            ,
  //-------------------- Coordinates  ----------------//
    output  [7:0]     accel_data_x      ,
    output  [7:0]     accel_data_y      ,
  //-------------------- Accelerometer ports ---------//
    output            ACL_CSN           ,
    output            ACL_SCLK          ,
    input             ACL_MISO          ,
    output            ACL_MOSI
);

    spi_ctrl (
      .rst_n        ( arst_n       ),
      .clk_5mhz0d   ( spi_clk      ),
      .clk_5mhz180d ( spi_clk_out  ),
      //
      .x_axis       ( accel_data_x ),
      .y_axis       ( accel_data_y ),
      //
      .MISO         ( ACL_MISO     ),
      .MOSI         ( ACL_MOSI     ),
      .CSN          ( ACL_CSN      ),
      .SCLK         ( ACL_SCLK     )
    );

endmodule