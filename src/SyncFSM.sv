// Code your design here
module SyncFSM#(
    parameter ACTIVE_VIDEO_WIDTH  = 640, // 480 - vertical
    parameter SYNC_PULSE_WIDTH = 96,   // 2
    parameter FRONT_PORCH_WIDTH = 16,  // 10
    parameter BACK_PORCH_WIDTH = 48    // 29
)(
    input logic     i_rstn,
    input logic     i_pixel_clk,

  	output logic[$clog2(SYNC_PULSE_WIDTH + BACK_PORCH_WIDTH + ACTIVE_VIDEO_WIDTH + FRONT_PORCH_WIDTH) -1: 0]    o_pixel_idx,
    output logic    o_active_video,
    output logic    o_sync
);

    localparam int SYNC_START_DISPLAY     = SYNC_PULSE_WIDTH + BACK_PORCH_WIDTH;
    localparam int SYNC_END_DISPLAY       = SYNC_PULSE_WIDTH + BACK_PORCH_WIDTH + ACTIVE_VIDEO_WIDTH - 1;
    localparam int PIXEL_IDX_MAX = SYNC_PULSE_WIDTH + BACK_PORCH_WIDTH + ACTIVE_VIDEO_WIDTH + FRONT_PORCH_WIDTH - 1;

    logic [$clog2(PIXEL_IDX_MAX + 1) -1: 0] pixel_idx;

    typedef enum {IDLE, SYNC_PULSE, BACK_PORCH, ACTIVE_VIDEO, FRONT_PORCH, ERROR} State;
    State cur_state, next_state;

    always_ff @(posedge i_pixel_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            cur_state       <= IDLE;
            pixel_idx       <= '0;
        end
        else begin
            cur_state <= next_state;
            if (pixel_idx == PIXEL_IDX_MAX) begin
                pixel_idx <= 0;
            end else if (cur_state != IDLE) begin
                pixel_idx <= pixel_idx + 1;
            end
        end
    end

    always_comb begin
        case (cur_state)
            IDLE: begin
                next_state <= (i_rstn)? SYNC_PULSE: IDLE;
            end
            SYNC_PULSE: begin
                next_state <= (pixel_idx < SYNC_PULSE_WIDTH -1) ? SYNC_PULSE : BACK_PORCH;
            end
            BACK_PORCH: begin
                next_state <= (pixel_idx < SYNC_START_DISPLAY) ? BACK_PORCH : ACTIVE_VIDEO;
            end
            ACTIVE_VIDEO:begin
                next_state <= (pixel_idx < SYNC_END_DISPLAY) ? ACTIVE_VIDEO : FRONT_PORCH;
            end
            FRONT_PORCH:begin
                next_state <= (pixel_idx < PIXEL_IDX_MAX) ? FRONT_PORCH : SYNC_PULSE;
            end
            default: begin
                next_state <= ERROR;
            end
        endcase
    end

    assign o_pixel_idx = (!i_rstn)? '0: pixel_idx;
    assign o_sync = (cur_state != SYNC_PULSE);
    assign o_active_video = (cur_state == ACTIVE_VIDEO) && i_rstn;
endmodule