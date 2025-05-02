// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_OutputMonitor);
    __Vhier.remove(&__Vscope_OutputMonitor, &__Vscope_OutputMonitor__HSyncFSM);
    __Vhier.remove(&__Vscope_OutputMonitor, &__Vscope_OutputMonitor__VSyncFSM);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(33);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_OutputMonitor.configure(this, name(), "OutputMonitor", "OutputMonitor", "OutputMonitor", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_OutputMonitor__HSyncFSM.configure(this, name(), "OutputMonitor.HSyncFSM", "HSyncFSM", "SyncFSM", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_OutputMonitor__VSyncFSM.configure(this, name(), "OutputMonitor.VSyncFSM", "VSyncFSM", "SyncFSM", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_OutputMonitor);
    __Vhier.add(&__Vscope_OutputMonitor, &__Vscope_OutputMonitor__HSyncFSM);
    __Vhier.add(&__Vscope_OutputMonitor, &__Vscope_OutputMonitor__VSyncFSM);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_OutputMonitor.varInsert(__Vfinal,"H_SYNC_ACTIVE_VIDEO_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__H_SYNC_ACTIVE_VIDEO_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"H_SYNC_BACK_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__H_SYNC_BACK_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"H_SYNC_FRONT_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__H_SYNC_FRONT_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"H_SYNC_SYNC_PULSE_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__H_SYNC_SYNC_PULSE_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"PIXEL_COL_MAX", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__PIXEL_COL_MAX))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"PIXEL_ROW_MAX", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__PIXEL_ROW_MAX))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"V_SYNC_ACTIVE_VIDEO_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__V_SYNC_ACTIVE_VIDEO_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"V_SYNC_BACK_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__V_SYNC_BACK_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"V_SYNC_FRONT_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__V_SYNC_FRONT_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"V_SYNC_SYNC_PULSE_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__V_SYNC_SYNC_PULSE_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"hsync_active_video", &(TOP.OutputMonitor__DOT__hsync_active_video), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"i_buffer_empty", &(TOP.OutputMonitor__DOT__i_buffer_empty), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"i_pixel_clk", &(TOP.OutputMonitor__DOT__i_pixel_clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"i_rstn", &(TOP.OutputMonitor__DOT__i_rstn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"i_src_active_video", &(TOP.OutputMonitor__DOT__i_src_active_video), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"o_hsync", &(TOP.OutputMonitor__DOT__o_hsync), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"o_pixel_buffer_re", &(TOP.OutputMonitor__DOT__o_pixel_buffer_re), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"o_pixel_buffer_we", &(TOP.OutputMonitor__DOT__o_pixel_buffer_we), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"o_vsync", &(TOP.OutputMonitor__DOT__o_vsync), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"output_active_video", &(TOP.OutputMonitor__DOT__output_active_video), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"pixel_col", &(TOP.OutputMonitor__DOT__pixel_col), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"pixel_row", &(TOP.OutputMonitor__DOT__pixel_row), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_OutputMonitor.varInsert(__Vfinal,"vsync_active_video", &(TOP.OutputMonitor__DOT__vsync_active_video), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"ACTIVE_VIDEO_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__ACTIVE_VIDEO_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"BACK_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__BACK_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"FRONT_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__FRONT_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"PIXEL_IDX_MAX", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__PIXEL_IDX_MAX))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"SYNC_END_DISPLAY", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__SYNC_END_DISPLAY))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"SYNC_PULSE_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__SYNC_PULSE_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"SYNC_START_DISPLAY", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__HSyncFSM__DOT__SYNC_START_DISPLAY))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"cur_state", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__cur_state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"i_pixel_clk", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__i_pixel_clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"i_rstn", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__i_rstn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"next_state", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__next_state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"o_active_video", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__o_active_video), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"o_pixel_idx", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__o_pixel_idx), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"o_sync", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__o_sync), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__HSyncFSM.varInsert(__Vfinal,"pixel_idx", &(TOP.OutputMonitor__DOT__HSyncFSM__DOT__pixel_idx), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"ACTIVE_VIDEO_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__ACTIVE_VIDEO_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"BACK_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__BACK_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"FRONT_PORCH_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__FRONT_PORCH_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"PIXEL_IDX_MAX", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__PIXEL_IDX_MAX))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"SYNC_END_DISPLAY", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__SYNC_END_DISPLAY))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"SYNC_PULSE_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__SYNC_PULSE_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"SYNC_START_DISPLAY", const_cast<void*>(static_cast<const void*>(&(TOP.OutputMonitor__DOT__VSyncFSM__DOT__SYNC_START_DISPLAY))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"cur_state", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__cur_state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"i_pixel_clk", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__i_pixel_clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"i_rstn", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__i_rstn), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"next_state", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__next_state), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"o_active_video", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__o_active_video), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"o_pixel_idx", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__o_pixel_idx), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"o_sync", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__o_sync), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_OutputMonitor__VSyncFSM.varInsert(__Vfinal,"pixel_idx", &(TOP.OutputMonitor__DOT__VSyncFSM__DOT__pixel_idx), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,0,1 ,9,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_buffer_empty", &(TOP.i_buffer_empty), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_pixel_clk", &(TOP.i_pixel_clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_rstn", &(TOP.i_rstn), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_src_active_video", &(TOP.i_src_active_video), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"o_hsync", &(TOP.o_hsync), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"o_pixel_buffer_re", &(TOP.o_pixel_buffer_re), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"o_pixel_buffer_we", &(TOP.o_pixel_buffer_we), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"o_vsync", &(TOP.o_vsync), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
    }
}
