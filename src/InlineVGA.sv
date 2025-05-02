`default_nettype none

module InlineVGA(
    input logic         i_rstn,
    input logic         i_clk,
    input logic         i_hsync, i_vsync,
    input logic[2:0]    i_red, i_green, i_blue,
    input logic         i_cmd_bit,

    output logic        o_hsync, o_vsync, 
    output logic[2:0]   o_red, o_green, o_blue,
    output logic        o_error
);

    localparam int H_SYNC_ACTIVE_VIDEO_WIDTH = 640;
    localparam int H_SYNC_SYNC_PULSE_WIDTH = 96;
    localparam int H_SYNC_FRONT_PORCH_WIDTH = 16;
    localparam int H_SYNC_BACK_PORCH_WIDTH = 48;

    localparam int V_SYNC_ACTIVE_VIDEO_WIDTH = 480;
    localparam int V_SYNC_SYNC_PULSE_WIDTH = 2;
    localparam int V_SYNC_FRONT_PORCH_WIDTH = 10;
    localparam int V_SYNC_BACK_PORCH_WIDTH = 33;

    //it is the size of the max(vsync non-active video cycles , hsycn non-active video cycles)
    localparam int BUFFER_DEPTH = H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_FRONT_PORCH_WIDTH + H_SYNC_BACK_PORCH_WIDTH;
    
    logic         stable_i_hsync, stable_i_vsync;
    logic[2:0]    stable_i_red, stable_i_green, stable_i_blue;
    logic         stable_i_cmd_bit;

    TwoFFSynchronizer #(1) src_hsync(i_rstn, i_clk, i_hsync, stable_i_hsync);
    TwoFFSynchronizer #(1) src_vsync(i_rstn, i_clk, i_vsync, stable_i_vsync);

    TwoFFSynchronizer #(3) src_red(i_rstn, i_clk, i_red, stable_i_red);
    TwoFFSynchronizer #(3) src_green(i_rstn, i_clk, i_green, stable_i_green);
    TwoFFSynchronizer #(3) src_blue(i_rstn, i_clk, i_blue, stable_i_blue);

    TwoFFSynchronizer #(1) src_cmd_bit(i_rstn, i_clk, i_cmd_bit, stable_i_cmd_bit);


    // tells system when to start vga processing
    logic system_rstn;
    SystemEnable system_enable(i_rstn, i_clk, stable_i_vsync, system_rstn);

    // Front half
    logic src_active_video;
    SourceMonitor #(
        H_SYNC_ACTIVE_VIDEO_WIDTH, H_SYNC_SYNC_PULSE_WIDTH, H_SYNC_FRONT_PORCH_WIDTH, H_SYNC_BACK_PORCH_WIDTH,
        V_SYNC_ACTIVE_VIDEO_WIDTH, V_SYNC_SYNC_PULSE_WIDTH, V_SYNC_FRONT_PORCH_WIDTH, V_SYNC_BACK_PORCH_WIDTH     
    )src_monitor(system_rstn, i_clk, stable_i_hsync, stable_i_vsync, src_active_video);


    logic [2:0] transform_cmd;
    InputShiftReg #(3) shift_reg(system_rstn, i_clk, stable_i_cmd_bit, transform_cmd);


    logic[2:0] edited_red, edited_green, edited_blue;
    PixelEditor pixel_editor(
        system_rstn, i_clk, transform_cmd, src_active_video,
        stable_i_red, stable_i_green, stable_i_blue,

        edited_red, edited_green, edited_blue
    );

    
    logic    buffer_empty;
    logic    pixel_buffer_we, pixel_buffer_re;
    OutputMonitor #(
        H_SYNC_ACTIVE_VIDEO_WIDTH, H_SYNC_SYNC_PULSE_WIDTH, H_SYNC_FRONT_PORCH_WIDTH, H_SYNC_BACK_PORCH_WIDTH,
        V_SYNC_ACTIVE_VIDEO_WIDTH, V_SYNC_SYNC_PULSE_WIDTH, V_SYNC_FRONT_PORCH_WIDTH, V_SYNC_BACK_PORCH_WIDTH
    ) output_monitor(
        system_rstn, i_clk, 
        
        src_active_video, buffer_empty, 
        pixel_buffer_we, pixel_buffer_re, o_hsync, o_vsync
    );


    PixelBuffer #(BUFFER_DEPTH, 9) pixel_buffer(
        system_rstn, i_clk, edited_red, edited_green, edited_blue,

        pixel_buffer_we, pixel_buffer_re, o_error, buffer_empty,
        o_red, o_green, o_blue,
    );
                    
endmodule