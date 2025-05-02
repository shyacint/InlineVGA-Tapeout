module OutputMonitor #(
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
    input logic     i_src_active_video,
    input logic     i_buffer_empty,

    output logic    o_pixel_buffer_we, o_pixel_buffer_re,
    output logic    o_hsync, o_vsync
);

    localparam int PIXEL_ROW_MAX = H_SYNC_ACTIVE_VIDEO_WIDTH + H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_FRONT_PORCH_WIDTH + H_SYNC_BACK_PORCH_WIDTH;
    localparam int PIXEL_COL_MAX = V_SYNC_ACTIVE_VIDEO_WIDTH + V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_FRONT_PORCH_WIDTH + V_SYNC_BACK_PORCH_WIDTH;


    logic hsync_active_video, vsync_active_video;
    logic[$clog2(PIXEL_ROW_MAX)-1: 0] pixel_row;
    logic[$clog2(PIXEL_COL_MAX)-1: 0] pixel_col;
    logic output_active_video;

    SyncFSM #(
        .ACTIVE_VIDEO_WIDTH(H_SYNC_ACTIVE_VIDEO_WIDTH),
        .SYNC_PULSE_WIDTH(H_SYNC_SYNC_PULSE_WIDTH),
        .FRONT_PORCH_WIDTH(H_SYNC_FRONT_PORCH_WIDTH),
        .BACK_PORCH_WIDTH(H_SYNC_BACK_PORCH_WIDTH)
    ) HSyncFSM(
        .i_rstn(i_rstn),
        .i_pixel_clk(i_pixel_clk),
        .o_pixel_idx(pixel_col),
        .o_active_video(hsync_active_video),
        .o_sync(o_hsync)
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
        .o_active_video(vsync_active_video),
        .o_sync(o_vsync)
    );

    assign output_active_video = (hsync_active_video & vsync_active_video) & i_rstn;
    assign o_pixel_buffer_we = i_src_active_video & i_rstn;
    assign o_pixel_buffer_re = !i_buffer_empty & output_active_video & i_rstn;

endmodule