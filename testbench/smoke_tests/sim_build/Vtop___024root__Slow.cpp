// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__H_SYNC_ACTIVE_VIDEO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__H_SYNC_SYNC_PULSE_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__H_SYNC_FRONT_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__H_SYNC_BACK_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__PIXEL_ROW_MAX;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__V_SYNC_ACTIVE_VIDEO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__V_SYNC_SYNC_PULSE_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__V_SYNC_FRONT_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__V_SYNC_BACK_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__PIXEL_COL_MAX;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__ACTIVE_VIDEO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__SYNC_PULSE_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__FRONT_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__BACK_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__SYNC_START_DISPLAY;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__SYNC_END_DISPLAY;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__HSyncFSM__DOT__PIXEL_IDX_MAX;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__ACTIVE_VIDEO_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__SYNC_PULSE_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__FRONT_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__BACK_PORCH_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__SYNC_START_DISPLAY;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__SYNC_END_DISPLAY;
constexpr IData/*31:0*/ Vtop___024root::OutputMonitor__DOT__VSyncFSM__DOT__PIXEL_IDX_MAX;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
