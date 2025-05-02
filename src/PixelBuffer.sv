module PixelBuffer #(
    parameter DEPTH = 8,
    parameter DATA_WIDTH = 9
) (
    input logic         i_rstn,
    input logic         i_pixel_clk,
    input logic[2:0]    i_red, i_green, i_blue,
    input logic         i_we, i_re,

    output logic        o_full, o_empty,
    output logic[2:0]   o_red, o_green, o_blue
);

    logic [2:0] buffer_red   [DEPTH];
    logic [2:0] buffer_green [DEPTH];
    logic [2:0] buffer_blue  [DEPTH];

    logic [$clog2(DEPTH)-1:0] wptr, rptr;

    assign o_full   = ((((wptr + 1) % (DEPTH)) == rptr) && i_rstn);
    assign o_empty  = (wptr == rptr) || !i_rstn; 

    always_ff @(posedge i_pixel_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            wptr <= '0;
        end else begin
            if (i_we  & !o_full) begin
                buffer_red[wptr]   <= i_red;
                buffer_green[wptr] <= i_green;
                buffer_blue[wptr]  <= i_blue;
             	wptr <= (wptr + 1) % (DEPTH);
            end 
        end
    end

    always_ff @(posedge i_pixel_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            rptr <= '0;
            {o_red, o_green, o_blue} <= '0;
        end else begin
            if (i_re & !i_we & !o_empty) begin
              {o_red, o_green, o_blue} <= {buffer_red[rptr], buffer_green[rptr], buffer_blue[rptr]};
              rptr <= (rptr + 1) % (DEPTH);
            end else begin
                //during unactive video, pixel value show be equal to black
                {o_red, o_green, o_blue} <= '0;
            end
        end
    end
    
endmodule