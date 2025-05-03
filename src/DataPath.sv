module DataPath #(
    parameter SEQ_LEN = 3,
    parameter DEPTH = 8,
    parameter DATA_WIDTH = 9
) (
    input logic         i_rstn,
    input logic         i_pixel_clk,
    input logic         i_data,
    input logic[2:0]    i_red, i_green, i_blue,

    input logic         i_src_active_video,      // control signal
    input logic         i_we, i_re,

    output logic        o_full, o_empty,
    output logic[2:0]   o_red, o_green, o_blue
);

    logic [2:0] transform_cmd;
    InputShiftReg #(SEQ_LEN) shift_reg(
        i_rstn, i_pixel_clk, i_data, 

        transform_cmd
    );

    logic[2:0]   m_red, m_green, m_blue;
    PixelEditor pxiel_editor(
        i_rstn, i_pixel_clk, transform_cmd, i_src_active_video,
        i_red, i_green, i_blue,

        m_red, m_green, m_blue
    );

    PixelBuffer #(8, 9) pixel_buffer(
        i_rstn, i_pixel_clk, m_red, m_green, m_blue, i_we, i_re,
        o_full, o_empty, o_red, o_green, o_blue
    );


endmodule