module TwoFFSynchronizer #(
    parameter DATA_WIDTH = 1
)(
    input logic                     i_rstn,
    input logic                     i_clk,
    input logic[DATA_WIDTH -1:0]    i_data,
    output logic[DATA_WIDTH -1:0]   o_data
);

logic [DATA_WIDTH -1:0] reg_one, reg_two;

always_ff @(posedge i_clk or negedge i_rstn) begin
    if (!i_rstn) begin
        reg_one <= '1;
        reg_two <= '1;
        o_data  <= '1;
    end else begin
        reg_one <= i_data;
        reg_two <= reg_one;
        o_data <= reg_two;
    end
end

endmodule