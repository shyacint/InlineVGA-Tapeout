// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.OutputMonitor__DOT__i_src_active_video 
        = vlSelfRef.i_src_active_video;
    vlSelfRef.OutputMonitor__DOT__i_buffer_empty = vlSelfRef.i_buffer_empty;
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__next_state 
        = ((0U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
            ? ((IData)(vlSelfRef.i_rstn) ? 1U : 0U)
            : ((1U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                ? ((0x5fU > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                    ? 1U : 2U) : ((2U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                                   ? ((0x90U > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                                       ? 2U : 3U) : 
                                  ((3U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                                    ? ((0x30fU > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                                        ? 3U : 4U) : 
                                   ((4U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                                     ? ((0x31fU > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                                         ? 4U : 1U)
                                     : 5U)))));
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__next_state 
        = ((0U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
            ? ((IData)(vlSelfRef.i_rstn) ? 1U : 0U)
            : ((1U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                ? ((1U > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                    ? 1U : 2U) : ((2U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                                   ? ((0x23U > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                                       ? 2U : 3U) : 
                                  ((3U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                                    ? ((0x202U > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                                        ? 3U : 4U) : 
                                   ((4U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                                     ? ((0x20cU > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                                         ? 4U : 1U)
                                     : 5U)))));
    if (vlSelfRef.i_rstn) {
        vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_we 
            = vlSelfRef.i_src_active_video;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx 
            = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx 
            = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
        vlSelfRef.OutputMonitor__DOT__i_rstn = 1U;
    } else {
        vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_we = 0U;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx = 0U;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx = 0U;
        vlSelfRef.OutputMonitor__DOT__i_rstn = 0U;
    }
    vlSelfRef.OutputMonitor__DOT__i_pixel_clk = vlSelfRef.i_pixel_clk;
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync 
        = (1U != vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state);
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync 
        = (1U != vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state);
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video 
        = ((3U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state) 
           & (IData)(vlSelfRef.i_rstn));
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video 
        = ((3U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state) 
           & (IData)(vlSelfRef.i_rstn));
    vlSelfRef.o_pixel_buffer_we = vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_we;
    vlSelfRef.OutputMonitor__DOT__pixel_col = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx;
    vlSelfRef.OutputMonitor__DOT__pixel_row = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx;
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__i_rstn 
        = vlSelfRef.OutputMonitor__DOT__i_rstn;
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__i_rstn 
        = vlSelfRef.OutputMonitor__DOT__i_rstn;
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__i_pixel_clk 
        = vlSelfRef.OutputMonitor__DOT__i_pixel_clk;
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__i_pixel_clk 
        = vlSelfRef.OutputMonitor__DOT__i_pixel_clk;
    vlSelfRef.o_hsync = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__o_hsync = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync;
    vlSelfRef.o_vsync = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__o_vsync = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__hsync_active_video 
        = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video;
    vlSelfRef.OutputMonitor__DOT__vsync_active_video 
        = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video;
    vlSelfRef.OutputMonitor__DOT__output_active_video 
        = ((IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video) 
           & ((IData)(vlSelfRef.i_rstn) & (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video)));
    vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_re 
        = ((~ (IData)(vlSelfRef.i_buffer_empty)) & 
           ((IData)(vlSelfRef.OutputMonitor__DOT__output_active_video) 
            & (IData)(vlSelfRef.i_rstn)));
    vlSelfRef.o_pixel_buffer_re = vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_re;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
    __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx = 0;
    SData/*9:0*/ __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
    __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx = 0;
    // Body
    __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx 
        = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
    __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx 
        = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
    if (vlSelfRef.i_rstn) {
        if ((0x31fU == (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))) {
            __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx = 0U;
        } else if ((0U != vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)) {
            __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx)));
        }
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx 
            = __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
        if ((0x20cU == (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))) {
            __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx = 0U;
        } else if ((0U != vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)) {
            __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx)));
        }
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx 
            = __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx 
            = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state 
            = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__next_state;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx 
            = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state 
            = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__next_state;
    } else {
        __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx = 0U;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx 
            = __Vdly__OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
        __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx = 0U;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx 
            = __Vdly__OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx = 0U;
        vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state = 0U;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx = 0U;
        vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state = 0U;
    }
    vlSelfRef.OutputMonitor__DOT__pixel_col = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx;
    vlSelfRef.OutputMonitor__DOT__pixel_row = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx;
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__next_state 
        = ((0U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
            ? ((IData)(vlSelfRef.i_rstn) ? 1U : 0U)
            : ((1U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                ? ((0x5fU > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                    ? 1U : 2U) : ((2U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                                   ? ((0x90U > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                                       ? 2U : 3U) : 
                                  ((3U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                                    ? ((0x30fU > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                                        ? 3U : 4U) : 
                                   ((4U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state)
                                     ? ((0x31fU > (IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx))
                                         ? 4U : 1U)
                                     : 5U)))));
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync 
        = (1U != vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state);
    vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video 
        = ((3U == vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__cur_state) 
           & (IData)(vlSelfRef.i_rstn));
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__next_state 
        = ((0U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
            ? ((IData)(vlSelfRef.i_rstn) ? 1U : 0U)
            : ((1U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                ? ((1U > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                    ? 1U : 2U) : ((2U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                                   ? ((0x23U > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                                       ? 2U : 3U) : 
                                  ((3U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                                    ? ((0x202U > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                                        ? 3U : 4U) : 
                                   ((4U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state)
                                     ? ((0x20cU > (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx))
                                         ? 4U : 1U)
                                     : 5U)))));
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync 
        = (1U != vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state);
    vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video 
        = ((3U == vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__cur_state) 
           & (IData)(vlSelfRef.i_rstn));
    vlSelfRef.o_hsync = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__o_hsync = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__hsync_active_video 
        = vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video;
    vlSelfRef.o_vsync = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__o_vsync = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_sync;
    vlSelfRef.OutputMonitor__DOT__vsync_active_video 
        = vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video;
    vlSelfRef.OutputMonitor__DOT__output_active_video 
        = ((IData)(vlSelfRef.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video) 
           & ((IData)(vlSelfRef.i_rstn) & (IData)(vlSelfRef.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video)));
    vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_re 
        = ((~ (IData)(vlSelfRef.i_buffer_empty)) & 
           ((IData)(vlSelfRef.OutputMonitor__DOT__output_active_video) 
            & (IData)(vlSelfRef.i_rstn)));
    vlSelfRef.o_pixel_buffer_re = vlSelfRef.OutputMonitor__DOT__o_pixel_buffer_re;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../src/OutputMonitor.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../src/OutputMonitor.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../src/OutputMonitor.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.i_rstn & 0xfeU)))) {
        Verilated::overWidthError("i_rstn");}
    if (VL_UNLIKELY(((vlSelfRef.i_pixel_clk & 0xfeU)))) {
        Verilated::overWidthError("i_pixel_clk");}
    if (VL_UNLIKELY(((vlSelfRef.i_src_active_video 
                      & 0xfeU)))) {
        Verilated::overWidthError("i_src_active_video");}
    if (VL_UNLIKELY(((vlSelfRef.i_buffer_empty & 0xfeU)))) {
        Verilated::overWidthError("i_buffer_empty");}
}
#endif  // VL_DEBUG
