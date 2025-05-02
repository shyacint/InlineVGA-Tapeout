// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.i_rstn));
    bufp->chgBit(oldp+1,(vlSelfRef.i_pixel_clk));
    bufp->chgBit(oldp+2,(vlSelfRef.i_src_active_video));
    bufp->chgBit(oldp+3,(vlSelfRef.i_buffer_empty));
    bufp->chgBit(oldp+4,(vlSelfRef.o_pixel_buffer_we));
    bufp->chgBit(oldp+5,(vlSelfRef.o_pixel_buffer_re));
    bufp->chgBit(oldp+6,(vlSelfRef.o_hsync));
    bufp->chgBit(oldp+7,(vlSelfRef.o_vsync));
    bufp->chgBit(oldp+8,(vlSelfRef.OutputMonitor__DOT__i_rstn));
    bufp->chgBit(oldp+9,(vlSelfRef.OutputMonitor__DOT__i_pixel_clk));
    bufp->chgBit(oldp+10,(vlSelfRef.OutputMonitor__DOT__i_src_active_video));
    bufp->chgBit(oldp+11,(vlSelfRef.OutputMonitor__DOT__i_buffer_empty));
    bufp->chgBit(oldp+12,(vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_we));
    bufp->chgBit(oldp+13,(vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_re));
    bufp->chgBit(oldp+14,(vlSelfRef.OutputMonitor__DOT__o_hsync));
    bufp->chgBit(oldp+15,(vlSelfRef.OutputMonitor__DOT__o_vsync));
    bufp->chgBit(oldp+16,(vlSelfRef.OutputMonitor__DOT__hsync_active_video));
    bufp->chgBit(oldp+17,(vlSelfRef.OutputMonitor__DOT__vsync_active_video));
    bufp->chgSData(oldp+18,(vlSelfRef.OutputMonitor__DOT__pixel_row),10);
    bufp->chgSData(oldp+19,(vlSelfRef.OutputMonitor__DOT__pixel_col),10);
    bufp->chgBit(oldp+20,(vlSelfRef.OutputMonitor__DOT__output_active_video));
    bufp->chgBit(oldp+21,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__i_rstn));
    bufp->chgBit(oldp+22,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__i_pixel_clk));
    bufp->chgSData(oldp+23,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx),10);
    bufp->chgBit(oldp+24,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video));
    bufp->chgBit(oldp+25,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync));
    bufp->chgSData(oldp+26,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx),10);
    bufp->chgIData(oldp+27,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state),32);
    bufp->chgIData(oldp+28,(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__next_state),32);
    bufp->chgBit(oldp+29,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__i_rstn));
    bufp->chgBit(oldp+30,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__i_pixel_clk));
    bufp->chgSData(oldp+31,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx),10);
    bufp->chgBit(oldp+32,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video));
    bufp->chgBit(oldp+33,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync));
    bufp->chgSData(oldp+34,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx),10);
    bufp->chgIData(oldp+35,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state),32);
    bufp->chgIData(oldp+36,(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__next_state),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
