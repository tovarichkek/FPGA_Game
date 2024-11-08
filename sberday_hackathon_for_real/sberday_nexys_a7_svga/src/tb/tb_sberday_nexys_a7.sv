module tb_sberday_nexys_a7 ();
  bit               CLK100MHZ;
  bit     [15:0]    SW;
  //
  logic   [15:0]    LED;
  logic             LED16_R, LED16_G, LED16_B;
  logic             LED17_R, LED17_G, LED17_B;
  //
  logic             DP, CG, CF, CE, CD, CC, CB, CA;
  logic   [ 7:0]    AN;
  //
  bit               BTNC, BTNU, BTNL, BTNR, BTND, CPU_RESETN;
  //
  bit               ACL_MISO;
  bit     [ 1:0]    ACL_INT;
  logic             ACL_MOSI;
  logic             ACL_SCLK;
  logic             ACL_CSN;
  //
  logic   [ 3:0]    VGA_R, VGA_G, VGA_B;
  logic             VGA_HS, VGA_VS;
  
  //----------- CLK -//
    always #2
      CLK100MHZ = ~CLK100MHZ;

  //----------- Main Initial -//
    initial begin
      CPU_RESETN = 1'b1;
      #10
      CPU_RESETN = 1'b0;
      //To pass reset trough button deboucer we need 2^16 * (1/100MHz) > 65536 * 10ns = 656us
      #656000
      CPU_RESETN = 1'b1;
    end

  //-----------
    sberday_nexys_a7_svga dut (
      .*
    );

endmodule