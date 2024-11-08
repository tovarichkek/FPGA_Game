// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmain.h for the primary calling header

#ifndef VERILATED_VMAIN___024ROOT_H_
#define VERILATED_VMAIN___024ROOT_H_  // guard

#include "verilated.h"


class Vmain__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmain___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(pixel_clk,0,0);
    VL_IN8(button_c,0,0);
    VL_IN8(sim_rst,0,0);
    VL_IN8(button_u,0,0);
    VL_IN8(button_d,0,0);
    VL_IN8(button_r,0,0);
    VL_IN8(button_l,0,0);
    VL_IN8(accel_data_x,7,0);
    VL_IN8(accel_data_y,7,0);
    VL_IN8(sw0,0,0);
    VL_IN8(sw1,0,0);
    VL_IN8(sw2,0,0);
    VL_IN8(sw3,0,0);
    VL_IN8(sw4,0,0);
    VL_IN8(sw5,0,0);
    VL_IN8(sw6,0,0);
    VL_IN8(sw7,0,0);
    VL_IN8(sw8,0,0);
    VL_OUT8(sdl_de,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    CData/*0:0*/ test_game__DOT__disp_enbl;
    CData/*0:0*/ test_game__DOT__game__DOT__regime_store;
    CData/*0:0*/ test_game__DOT__game__DOT__end_of_frame;
    CData/*0:0*/ test_game__DOT__game__DOT__ball;
    CData/*0:0*/ test_game__DOT__game__DOT__x_direction;
    CData/*1:0*/ test_game__DOT__game__DOT__y_direction;
    CData/*6:0*/ test_game__DOT__game__DOT__p1_count;
    CData/*6:0*/ test_game__DOT__game__DOT__p2_count;
    CData/*0:0*/ test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0;
    CData/*0:0*/ __Vdly__test_game__DOT__game__DOT__regime_store;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pixel_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__button_c__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(sdl_sx,10,0);
    VL_OUT16(sdl_sy,9,0);
    SData/*9:0*/ test_game__DOT__game__DOT__board1_h_coord;
    SData/*9:0*/ test_game__DOT__game__DOT__board1_v_coord;
    SData/*9:0*/ test_game__DOT__game__DOT__board2_h_coord;
    SData/*9:0*/ test_game__DOT__game__DOT__board2_v_coord;
    SData/*9:0*/ test_game__DOT__game__DOT__ball_h_coord;
    SData/*9:0*/ test_game__DOT__game__DOT__ball_v_coord;
    SData/*9:0*/ test_game__DOT__game__DOT__delta_speed;
    SData/*10:0*/ test_game__DOT__display_ctrl__DOT__h_count;
    SData/*9:0*/ test_game__DOT__display_ctrl__DOT__v_count;
    IData/*31:0*/ test_game__DOT__game__DOT__frames_cntr;
    IData/*31:0*/ test_game__DOT__game__DOT__rand_mod;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmain__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmain___024root(Vmain__Syms* symsp, const char* v__name);
    ~Vmain___024root();
    VL_UNCOPYABLE(Vmain___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
