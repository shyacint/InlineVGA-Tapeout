module PixelEditor (
    input logic         i_rstn,
    input logic         i_pixel_clk,
    input logic[2:0]    i_transform,        // control signal
    input logic         i_src_active_video, // control signal
    input logic[2:0]    i_red, i_green, i_blue,

    output logic[2:0]   o_red, o_green, o_blue
);

    typedef enum logic [2:0] {
        NONE        = 3'd0,
        ISO_BLUE    = 3'd1,
        ISO_GREEN   = 3'd2,
        ISO_RED     = 3'd3,
        RGB_SWAP    = 3'd4,
        GRAY_SCALE  = 3'd5
        //TODO: add one more transform
    } Transform;

    Transform requested_transform;
  	assign requested_transform = (!i_rstn) ? NONE : i_transform;


    always_ff @(posedge i_pixel_clk or negedge i_rstn) begin
        if (!i_rstn) begin
            o_red   <= '0;
            o_green <= '0;
            o_blue  <= '0;
        end
        else begin
            if (i_src_active_video) begin
                case (requested_transform)
                    ISO_BLUE: begin
                        o_red   <= '0; 
                        o_green <= '0; 
                        o_blue  <= i_blue;
                    end
                    ISO_GREEN: begin
                        o_red   <= '0; 
                        o_green <= i_green;
                        o_blue  <= '0;
                    end
                    ISO_RED: begin
                        o_red   <= i_red;
                        o_green <= '0; 
                        o_blue  <= '0;
                    end
                    RGB_SWAP: begin
                        o_red   <= i_green; 
                        o_green <= i_blue; 
                        o_blue  <= i_red;
                    end
                    GRAY_SCALE: begin
                        o_red   <= (i_red + i_green + i_blue)/3; 
                        o_green <= (i_red + i_green + i_blue)/3; 
                        o_blue  <= (i_red + i_green + i_blue)/3;
                    end
                    default: begin
                        o_red   <= i_red; 
                        o_green <= i_green; 
                        o_blue  <= i_blue;
                    end
                endcase
            end
        end
    end

endmodule