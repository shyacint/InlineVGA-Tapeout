module SourceMonitor #(
    parameter H_SYNC_ACTIVE_VIDEO_WIDTH = 640,
    parameter H_SYNC_SYNC_PULSE_WIDTH = 96,
    parameter H_SYNC_FRONT_PORCH_WIDTH = 16,
    parameter H_SYNC_BACK_PORCH_WIDTH = 48,

    parameter V_SYNC_ACTIVE_VIDEO_WIDTH = 480,
    parameter V_SYNC_SYNC_PULSE_WIDTH = 2,
    parameter V_SYNC_FRONT_PORCH_WIDTH = 10,
    parameter V_SYNC_BACK_PORCH_WIDTH = 33,
)(
    input logic     i_rstn,
    input logic     i_pixel_clk,
    input logic     i_src_hsync, i_src_vsync,

    output logic    o_src_active_video
);

    localparam int PIXEL_ROW_MAX = H_SYNC_ACTIVE_VIDEO_WIDTH + H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_FRONT_PORCH_WIDTH + H_SYNC_BACK_PORCH_WIDTH;
    localparam int PIXEL_COL_MAX = V_SYNC_ACTIVE_VIDEO_WIDTH + V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_FRONT_PORCH_WIDTH + V_SYNC_BACK_PORCH_WIDTH;

    logic[$clog2(PIXEL_ROW_MAX)-1: 0] pixel_row;
    logic[$clog2(PIXEL_COL_MAX)-1: 0] pixel_col;
    logic UNUSED_hsync_active_video, UNUSED_hsync;
    logic UNUSED_vsync_active_video, UNUSED_vsync;

    SyncFSM #(
        .ACTIVE_VIDEO_WIDTH(H_SYNC_ACTIVE_VIDEO_WIDTH),
        .SYNC_PULSE_WIDTH(H_SYNC_SYNC_PULSE_WIDTH),
        .FRONT_PORCH_WIDTH(H_SYNC_FRONT_PORCH_WIDTH),
        .BACK_PORCH_WIDTH(H_SYNC_BACK_PORCH_WIDTH)
    ) HSyncFSM(
        .i_rstn(i_rstn),
        .i_pixel_clk(i_pixel_clk),
        .o_pixel_idx(pixel_col),
        .o_active_video(UNUSED_hsync_active_video),
        .o_sync(UNUSED_hsync)
    );

    SyncFSM #(
        .ACTIVE_VIDEO_WIDTH(V_SYNC_ACTIVE_VIDEO_WIDTH),
        .SYNC_PULSE_WIDTH(V_SYNC_SYNC_PULSE_WIDTH),
        .FRONT_PORCH_WIDTH(V_SYNC_FRONT_PORCH_WIDTH),
        .BACK_PORCH_WIDTH(V_SYNC_BACK_PORCH_WIDTH)
    ) VSyncFSM(
        .i_rstn(i_rstn),
        .i_pixel_clk(i_pixel_clk),
        .o_pixel_idx(pixel_row),
        .o_active_video(UNUSED_vsync_active_video),
        .o_sync(UNUSED_vsync)
    );

    //TODO: makre sure to add 2FF before the input to this module
    assign o_src_active_video = (i_src_hsync & i_src_vsync) & !i_rstn;
    
endmodule