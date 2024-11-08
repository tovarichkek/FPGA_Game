// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMAIN_H_
#define _VMAIN_H_  // guard

#include "verilated_heavy.h"

//==========

class Vmain__Syms;

//----------

VL_MODULE(Vmain) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
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
    VL_IN8(sw9,0,0);
    VL_OUT8(sdl_de,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    VL_OUT16(sdl_sx,10,0);
    VL_OUT16(sdl_sy,9,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ test_game__DOT__disp_enbl;
    CData/*0:0*/ test_game__DOT__game__DOT__regime_store;
    CData/*0:0*/ test_game__DOT__game__DOT__end_of_frame;
    CData/*0:0*/ test_game__DOT__game__DOT__object_draw;
    CData/*0:0*/ test_game__DOT__game__DOT__board1;
    CData/*0:0*/ test_game__DOT__game__DOT__board2;
    CData/*0:0*/ test_game__DOT__game__DOT__ball;
    CData/*0:0*/ test_game__DOT__game__DOT__x_direction;
    CData/*1:0*/ test_game__DOT__game__DOT__y_direction;
    CData/*7:0*/ test_game__DOT__game__DOT__p1_count;
    CData/*7:0*/ test_game__DOT__game__DOT__p2_count;
    SData/*11:0*/ test_game__DOT__game__DOT__logo_rom_out;
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
    IData/*16:0*/ test_game__DOT__game__DOT__logo_read_address;
    IData/*31:0*/ test_game__DOT__game__DOT__rand_mod;
    SData/*11:0*/ test_game__DOT__game__DOT__logo_rom__DOT__rom[128000];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vdly__test_game__DOT__game__DOT__regime_store;
    CData/*0:0*/ __Vclklast__TOP__button_c;
    CData/*0:0*/ __Vclklast__TOP__pixel_clk;
    SData/*9:0*/ test_game__DOT____Vcellinp__game__SW;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmain__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmain);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmain(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmain();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmain__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmain__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmain__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vmain__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__6(Vmain__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmain__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__8(Vmain__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vmain__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vmain__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vmain__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
