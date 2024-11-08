// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain__pch.h"
#include "Vmain__Syms.h"
#include "Vmain___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__act(Vmain___024root* vlSelf);
#endif  // VL_DEBUG

void Vmain___024root___eval_triggers__act(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.pixel_clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pixel_clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.button_c) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__button_c__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__pixel_clk__0 = vlSelfRef.pixel_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__button_c__0 = vlSelfRef.button_c;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmain___024root___dump_triggers__act(vlSelf);
    }
#endif
}
