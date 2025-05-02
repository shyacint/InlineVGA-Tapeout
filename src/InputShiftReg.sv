module InputShiftReg #(
    parameter SEQ_LEN = 3
) (
    input logic i_rstn,
    input logic i_pixel_clk,
    input logic i_data,

    output logic[2:0] o_transform
);

    logic [SEQ_LEN -1:0] pattern;
    logic [$clog2(SEQ_LEN):0] stored_bits;


    always_ff @(posedge i_pixel_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            pattern 	    <= '0;
            stored_bits 	<= '0;
          	o_transform     <= '0;
        end else begin
            if (stored_bits == SEQ_LEN -1) begin
                o_transform <= {pattern[SEQ_LEN-2:0], i_data};
                stored_bits <= '0;
            end else begin
                stored_bits <= stored_bits + 1;
            end
            pattern <= {pattern[SEQ_LEN-2:0], i_data};
        end
    end

    
endmodule