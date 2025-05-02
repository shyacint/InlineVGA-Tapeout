// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(i_rstn,0,0);
    VL_IN8(i_pixel_clk,0,0);
    VL_IN8(i_src_active_video,0,0);
    VL_IN8(i_buffer_empty,0,0);
    VL_OUT8(o_pixel_buffer_we,0,0);
    VL_OUT8(o_pixel_buffer_re,0,0);
    VL_OUT8(o_hsync,0,0);
    VL_OUT8(o_vsync,0,0);
    CData/*0:0*/ OutputMonitor__DOT__i_rstn;
    CData/*0:0*/ OutputMonitor__DOT__i_pixel_clk;
    CData/*0:0*/ OutputMonitor__DOT__i_src_active_video;
    CData/*0:0*/ OutputMonitor__DOT__i_buffer_empty;
    CData/*0:0*/ OutputMonitor__DOT__o_pixel_buffer_we;
    CData/*0:0*/ OutputMonitor__DOT__o_pixel_buffer_re;
    CData/*0:0*/ OutputMonitor__DOT__o_hsync;
    CData/*0:0*/ OutputMonitor__DOT__o_vsync;
    CData/*0:0*/ OutputMonitor__DOT__hsync_active_video;
    CData/*0:0*/ OutputMonitor__DOT__vsync_active_video;
    CData/*0:0*/ OutputMonitor__DOT__output_active_video;
    CData/*0:0*/ OutputMonitor__DOT__HSyncFSM__DOT__i_rstn;
    CData/*0:0*/ OutputMonitor__DOT__HSyncFSM__DOT__i_pixel_clk;
    CData/*0:0*/ OutputMonitor__DOT__HSyncFSM__DOT__o_active_video;
    CData/*0:0*/ OutputMonitor__DOT__HSyncFSM__DOT__o_sync;
    CData/*0:0*/ OutputMonitor__DOT__VSyncFSM__DOT__i_rstn;
    CData/*0:0*/ OutputMonitor__DOT__VSyncFSM__DOT__i_pixel_clk;
    CData/*0:0*/ OutputMonitor__DOT__VSyncFSM__DOT__o_active_video;
    CData/*0:0*/ OutputMonitor__DOT__VSyncFSM__DOT__o_sync;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_pixel_clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i_rstn__0;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ OutputMonitor__DOT__pixel_row;
    SData/*9:0*/ OutputMonitor__DOT__pixel_col;
    SData/*9:0*/ OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx;
    SData/*9:0*/ OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx;
    SData/*9:0*/ OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx;
    SData/*9:0*/ OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx;
    IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__cur_state;
    IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__next_state;
    IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__cur_state;
    IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__next_state;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ OutputMonitor__DOT__H_SYNC_ACTIVE_VIDEO_WIDTH = 0x00000280U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__H_SYNC_SYNC_PULSE_WIDTH = 0x00000060U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__H_SYNC_FRONT_PORCH_WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__H_SYNC_BACK_PORCH_WIDTH = 0x00000030U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__PIXEL_ROW_MAX = 0x00000320U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__V_SYNC_ACTIVE_VIDEO_WIDTH = 0x000001e0U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__V_SYNC_SYNC_PULSE_WIDTH = 2U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__V_SYNC_FRONT_PORCH_WIDTH = 0x0000000aU;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__V_SYNC_BACK_PORCH_WIDTH = 0x00000021U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__PIXEL_COL_MAX = 0x0000020dU;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__ACTIVE_VIDEO_WIDTH = 0x00000280U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__SYNC_PULSE_WIDTH = 0x00000060U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__FRONT_PORCH_WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__BACK_PORCH_WIDTH = 0x00000030U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__SYNC_START_DISPLAY = 0x00000090U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__SYNC_END_DISPLAY = 0x0000030fU;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__HSyncFSM__DOT__PIXEL_IDX_MAX = 0x0000031fU;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__ACTIVE_VIDEO_WIDTH = 0x000001e0U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__SYNC_PULSE_WIDTH = 2U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__FRONT_PORCH_WIDTH = 0x0000000aU;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__BACK_PORCH_WIDTH = 0x00000021U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__SYNC_START_DISPLAY = 0x00000023U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__SYNC_END_DISPLAY = 0x00000202U;
    static constexpr IData/*31:0*/ OutputMonitor__DOT__VSyncFSM__DOT__PIXEL_IDX_MAX = 0x0000020cU;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
