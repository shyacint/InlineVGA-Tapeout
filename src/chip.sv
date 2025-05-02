`default_nettype none

module my_chip (
    input logic [11:0] io_in, // Inputs to your chip
    output logic [11:0] io_out, // Outputs from your chip
    input logic clock,
    input logic reset // Important: Reset is ACTIVE-HIGH
);
    
InlineVGA inline_vga(
    .i_rstn(!reset), // designed for active low
    .i_clk(clock),
    .i_hsync(io_in[11]),
    .i_vsync(io_in[10]),
    .i_red(io_in[9:7]),
    .i_green(io_in[6:4]),
    .i_blue(io_in[3:1]),
    .i_cmd_bit(io_in[0]),

    .o_hsync(io_out[11]), 
    .o_vsync(io_out[10]), 
    .o_red(io_out[9:7]),
    .o_green(io_out[6:4]).
    .o_blue(io_out[3:1]),
    .o_error(io_out[0])
);

endmodule
