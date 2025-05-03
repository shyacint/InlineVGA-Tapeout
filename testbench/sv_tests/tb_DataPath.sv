`timescale 1ns/1ps

`define NUM_RND_TESTS           1
`define CLK_PERIOD              10

`define PARAM_SEQ_LEN    		3
`define PARAM_BUFFER_DEPTH      8
`define PARAM_BUFFER_DATA_WIDTH 9


module tb_DataPath();

    // drivers
    logic           i_rstn;
    logic           i_pixel_clk;
    logic           i_data;
    logic[2:0]      i_red, i_green, i_blue;

    logic           i_src_active_video;      // control signal
    logic           i_we, i_re;

    // observable 
    logic           o_full, o_empty;
    logic[2:0]      o_red, o_green, o_blue;

    DataPath #(
        `PARAM_SEQ_LEN, `PARAM_BUFFER_DEPTH, `PARAM_BUFFER_DATA_WIDTH
    ) dut(
        i_rstn, i_pixel_clk, i_data, i_red, i_green, i_blue,
        i_src_active_video, i_we, i_re,

        o_full, o_empty, o_red, o_green, o_blue
    );

    // tb book keeping
    int num_test_cases = 0;
    int golden_model_size = 0;
    logic [`PARAM_BUFFER_DATA_WIDTH -1:0] golden_model_queue[$:`PARAM_BUFFER_DEPTH];

    logic rnd_rstn;
    logic rnd_we, rnd_re;
    logic[2:0] rnd_r, rnd_g, rnd_b;
    logic [2:0] golden_r, golden_g, golden_b;

    initial begin
        // vcd generation
        $dumpfile("dump.vcd");
        $dumpvars;
    end

    initial i_pixel_clk = 0;
    always #(`CLK_PERIOD/2) i_pixel_clk = ~i_pixel_clk;
    initial begin
        init_dut();
        reset_dut();
        assert_reset_dut();

        init_dut();

    while (num_test_cases < `NUM_RND_TESTS) begin
        generate_rnd_rgb(rnd_r, rnd_g, rnd_b);
        set_cmd_and_rgb(0, rnd_r, rnd_g, rnd_b);
        enable_buffer_write();
        read_from_buffer();
        assert_buffer_output(rnd_r, rnd_g, rnd_b);
        num_test_cases++;
    end
        
        repeat(4) @(negedge i_pixel_clk);

      	$finish();
    end

    task automatic reset_dut();
        @(negedge i_pixel_clk);
        i_rstn <= '0;
        @(negedge i_pixel_clk);
        golden_model_queue.delete();
        i_rstn <= '1;
    endtask

    task automatic assert_reset_dut();
      @(posedge i_pixel_clk);
      		assert(o_full == '0) else print_state("o_full not resetting...");
            assert(o_empty == '1) else print_state("o_empty not resetting...");
            assert({o_red, o_green, o_blue} == '0) else print_state("o_rgb not resetting...");
    endtask

    task automatic init_dut();
        @(negedge i_pixel_clk);
        i_rstn <= '1;
        i_data <= '0;
        {i_red, i_green, i_blue} <= {9'b101_101_101};

        i_src_active_video <= '1;      // control signal
        i_we <= '0; 
        i_re <= '0;

        @(posedge i_pixel_clk);
    endtask

    task automatic set_cmd_and_rgb(input logic[2:0] cmd, r, g, b);
        for (int i = `PARAM_SEQ_LEN -1; i >= 0; i= i - 1 ) begin
            @(negedge i_pixel_clk);
            i_data <= cmd[i];
            if (i == 0) begin
                {i_red, i_green, i_blue} <= {r, g, b};
                golden_model_queue.push_back({r, g, b});
            end
        end
        @(negedge i_pixel_clk);
    endtask

    task automatic enable_buffer_write();
        i_we <= '1;
        @(negedge i_pixel_clk);
        i_we <= '0;
    endtask

    task automatic read_from_buffer();
        i_re <= '1;
        @(negedge i_pixel_clk);
        i_re <= '0;        
    endtask 

    task automatic assert_buffer_output(input logic[2:0] exp_r, exp_g, exp_b);
        @(posedge i_pixel_clk);
        assert ({o_red, o_green, o_blue} == golden_model_queue.pop_front())
        else print_state("o_rgb not what was expected...");
    endtask

    task automatic print_state(string label = "STATE DUMP");
        $fatal("[%0t] %s | clk=%b rstn=%b we=%b re=%b data=%b -> full=%b empty=%b R=%0b G=%0b B=%0b",
        $time, label, i_pixel_clk, i_rstn, i_we, i_re, i_data,
        o_full, o_empty, o_red, o_green, o_blue);
    endtask

    task automatic generate_rnd_rgb(output logic [2:0] r, output logic [2:0] g, output logic [2:0] b);
        r = $urandom_range(0, 7);
        g = $urandom_range(0, 7);
        b = $urandom_range(0, 7);
    endtask

    function automatic logic[8:0] golden_model_tranform(
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

endmodule