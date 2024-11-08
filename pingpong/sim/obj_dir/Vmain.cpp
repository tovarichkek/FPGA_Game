// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmain__pch.h"

//============================================================
// Constructors

Vmain::Vmain(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmain__Syms(contextp(), _vcname__, this)}
    , pixel_clk{vlSymsp->TOP.pixel_clk}
    , sim_rst{vlSymsp->TOP.sim_rst}
    , button_c{vlSymsp->TOP.button_c}
    , button_u{vlSymsp->TOP.button_u}
    , button_d{vlSymsp->TOP.button_d}
    , button_r{vlSymsp->TOP.button_r}
    , button_l{vlSymsp->TOP.button_l}
    , accel_data_x{vlSymsp->TOP.accel_data_x}
    , accel_data_y{vlSymsp->TOP.accel_data_y}
    , sw0{vlSymsp->TOP.sw0}
    , sw1{vlSymsp->TOP.sw1}
    , sw2{vlSymsp->TOP.sw2}
    , sw3{vlSymsp->TOP.sw3}
    , sw4{vlSymsp->TOP.sw4}
    , sw5{vlSymsp->TOP.sw5}
    , sw6{vlSymsp->TOP.sw6}
    , sw7{vlSymsp->TOP.sw7}
    , sw8{vlSymsp->TOP.sw8}
    , sdl_de{vlSymsp->TOP.sdl_de}
    , sdl_r{vlSymsp->TOP.sdl_r}
    , sdl_g{vlSymsp->TOP.sdl_g}
    , sdl_b{vlSymsp->TOP.sdl_b}
    , sdl_sx{vlSymsp->TOP.sdl_sx}
    , sdl_sy{vlSymsp->TOP.sdl_sy}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmain::Vmain(const char* _vcname__)
    : Vmain(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmain::~Vmain() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmain___024root___eval_debug_assertions(Vmain___024root* vlSelf);
#endif  // VL_DEBUG
void Vmain___024root___eval_static(Vmain___024root* vlSelf);
void Vmain___024root___eval_initial(Vmain___024root* vlSelf);
void Vmain___024root___eval_settle(Vmain___024root* vlSelf);
void Vmain___024root___eval(Vmain___024root* vlSelf);

void Vmain::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmain::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmain___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmain___024root___eval_static(&(vlSymsp->TOP));
        Vmain___024root___eval_initial(&(vlSymsp->TOP));
        Vmain___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmain___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmain::eventsPending() { return false; }

uint64_t Vmain::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmain::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmain___024root___eval_final(Vmain___024root* vlSelf);

VL_ATTR_COLD void Vmain::final() {
    Vmain___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmain::hierName() const { return vlSymsp->name(); }
const char* Vmain::modelName() const { return "Vmain"; }
unsigned Vmain::threads() const { return 1; }
void Vmain::prepareClone() const { contextp()->prepareClone(); }
void Vmain::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vmain::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmain::trace()' called on model that was Verilated without --trace option");
}
