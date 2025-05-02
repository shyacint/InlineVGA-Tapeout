module SystemEnable (
    input logic     i_rstn,
    input logic     i_clk,      
    input logic     i_synchronized_vsync,

    output logic    o_enable
);

    logic clk_running;
    logic prev_synchronized_vsync;

    always_ff @(posedge i_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            prev_synchronized_vsync <= '0;
        end else begin
            prev_synchronized_vsync <= i_synchronized_vsync;
        end
    end

    always_ff @(posedge i_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            clk_running <= '0;
        end else if (!clk_running && prev_synchronized_vsync && !i_synchronized_vsync) begin
            clk_running <= '1;
        end
    end

    assign o_enable = i_rstn & clk_running; 
endmodule