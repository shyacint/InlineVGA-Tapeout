`timescale 1ns / 1ps

`define NUM_TRANSFORMS  7
`define MAX_TEST_CASES 100

module tb_PixelEditor();

    // connection defintions 
    logic         i_rstn;
    logic         i_pixel_clk;
  	logic[2:0]    i_transform;
    logic         i_src_active_video; 
  	logic[2:0]    i_red, i_green, i_blue;

  	logic[2:0]   o_red, o_green, o_blue;

    // tb objects
    int total_tests = 0;
  	logic seen;
    logic[2:0] covered[$]; 
    logic[8:0] prev_rgb;

  	logic rnd_i_rstn;
    logic rnd_i_src_active_video;
    logic[2:0] rnd_transform;
    logic[2:0] rnd_r, rnd_g, rnd_b;



    PixelEditor dut(
        .i_rstn              (i_rstn),
        .i_pixel_clk         (i_pixel_clk),
        .i_transform         (i_transform),
        .i_src_active_video  (i_src_active_video),
        .i_red               (i_red),
        .i_green             (i_green),
        .i_blue              (i_blue),
        
        .o_red               (o_red),
        .o_green             (o_green),
        .o_blue              (o_blue)
    );

    // clock generation
    always #5 i_pixel_clk = ~i_pixel_clk;

    initial begin
     	$dumpfile("dump.vcd");
		$dumpvars;
        // initial values
        i_rstn                      <= '1;  
        i_pixel_clk                 <= '0;
        i_transform                 <= '0;
        i_src_active_video          <= '0;
        {i_red, i_green, i_blue}    <=  9'b111_000_111; //magenta
      	
      	// async reset
      	#3 i_rstn <= '0;
      	repeat (2) @(posedge i_pixel_clk);

        // loop until full transform space covered 
      	while ((covered.size() < `NUM_TRANSFORMS) || (total_tests < `MAX_TEST_CASES)) begin
            // generate random stimi
          	rnd_i_rstn = $urandom();
            rnd_i_src_active_video = $urandom();
            generate_rnd_transform(rnd_transform);
            generate_rnd_rgb(rnd_r, rnd_g, rnd_b);
         	seen = transform_seen(rnd_transform, covered);
            if ((rnd_i_rstn == 1) && !seen) begin
                covered.push_back(rnd_transform);
            end
		
            i_rstn = rnd_i_rstn;
            i_src_active_video =rnd_i_src_active_video;
            i_transform <= rnd_transform;
            {i_red, i_green, i_blue} = {rnd_r, rnd_g, rnd_b};
            prev_rgb = {o_red,o_green,o_blue};

            repeat(2)@(posedge i_pixel_clk);

            // reset did not occur and in active video period
            if (rnd_i_rstn && rnd_i_src_active_video) begin 
              assert ({o_red, o_green, o_blue} == golden_model(rnd_transform,rnd_r, rnd_g, rnd_b))
                else begin
                    $display("[ERROR] Mismatch detected at time %0t", $time);
                    $display("[ERROR] Input Transform: %0d", i_transform);
                    $display("[ERROR] DUT Output     : R=%0d G=%0d B=%0d", o_red, o_green, o_blue);
                    $fatal(1, "[ERROR] Output mismatch detected. Simulation halted.");
                end
            end
            // reset did not occur and not in active video
            else if (rnd_i_rstn && !rnd_i_src_active_video) begin
                assert ({o_red, o_green, o_blue} == prev_rgb) 
                else   begin
                    $display("[ERROR] Mismatch detected at time %0t", $time);
                    $display("[ERROR] Occured during Active Video Section");
                    $display("[ERROR] DUT Output     : R=%0d G=%0d B=%0d", o_red, o_green, o_blue);
                    $fatal(1, "[ERROR] Output mismatch detected. Simulation halted.");
                end
            end
            // reset did occur
            else begin
                assert ({o_red, o_green, o_blue} == {'0, '0, '0}) 
                else begin
                    $display("[ERROR] Mismatch detected at time %0t", $time);
                    $display("[ERROR] Occured while recent was active");
                    $display("[ERROR] DUT Output     : R=%0d G=%0d B=%0d", o_red, o_green, o_blue);
                    $fatal(1, "[ERROR] Output mismatch detected. Simulation halted.");
                end
            end
            total_tests++;
        end


        $display("[SUCCESS] Full coverage achieved in total_tests = %0d", total_tests);
        $finish;
    end
endmodule

task automatic generate_rnd_transform(
    output logic [2:0] transform
);
    transform = $urandom_range(0, 7);
endtask

task automatic generate_rnd_rgb(
    output logic [2:0] r,
    output logic [2:0] g,
    output logic [2:0] b
);
    r = $urandom_range(0, 7);
    g = $urandom_range(0, 7);
    b = $urandom_range(0, 7);
endtask

// Returns true if value already exists in covered[]
function automatic bit transform_seen(
    input logic [2:0] value,
    input logic [2:0] queue[$]
);
    foreach (queue[i]) begin
        if (queue[i] == value) return 1;
    end
    return 0;
endfunction

function automatic logic[8:0] golden_model(
    input logic [2:0] transform,
    input logic [2:0] r, g, b

);

  logic [2:0] exp_r, exp_g, exp_b;

    case (transform)
        1: begin
            exp_r  = '0; 
            exp_g = '0; 
            exp_b  = b;
        end
        2: begin
            exp_r   = '0; 
            exp_g = g;
            exp_b  = '0;
        end
        3: begin
            exp_r   = r;
            exp_g = '0; 
            exp_b  = '0;
        end
        4: begin
            exp_r   = g; 
            exp_g = b; 
            exp_b  = r;
        end
        5: begin
            exp_r   = (r + g + b)/3; 
            exp_g = (r + g + b)/3; 
            exp_b  = (r + g + b)/3;
        end
        default: begin
            exp_r   = r; 
            exp_g = g; 
            exp_b  = b;
        end
    endcase

    return {exp_r, exp_g, exp_b};
endfunction
