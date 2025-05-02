`timescale 1ns/1ps

`define NUM_RND_TESTS    1000

`define CLK_PERIOD     10
`define SEQ_LEN    		3

module tb_InputShiftReg();

    //driver signals
    logic i_rstn;
    logic i_pixel_clk;
    logic i_data;

    // observable signals
  	logic [`SEQ_LEN -1:0] o_transform;

    InputShiftReg #(
        .SEQ_LEN(`SEQ_LEN)
    ) dut (
        .i_rstn(i_rstn),
        .i_pixel_clk(i_pixel_clk),
        .i_data(i_data),

        .o_transform(o_transform)
    );

    // tb book keeping
    int num_test_cases = 0;

    logic[`SEQ_LEN-1:0] rnd_seq;

    // waveform vcd
    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end

    always #((`CLK_PERIOD/2)) i_pixel_clk = ~i_pixel_clk;

    initial begin
        i_rstn  <= '0;
        i_pixel_clk   <= '0;
        i_data  <= '0;
      
        reset_dut();
        assert_dut_reset();

        // randomly generate a 3 bit seqeunce
        rnd_seq = $urandom_range(0, 2**(`SEQ_LEN));
        shift_in_seq(rnd_seq);
        assert_tranform(rnd_seq);

        while (num_test_cases < `NUM_RND_TESTS) begin
            rnd_seq = $urandom_range(0, 2**`SEQ_LEN -1);
            for (int i = 0; i < `SEQ_LEN; i = i+1) begin
                if($urandom_range(0,9) == 0) begin
                    reset_dut();
                    assert_dut_reset();
                    break;
                end else begin
                    shift_single_bit(rnd_seq[(`SEQ_LEN -1) -i]);
                    if (i == `SEQ_LEN -1) begin
                        assert_tranform(rnd_seq);
                    end
                end
            end
            num_test_cases++;
        end
      $display("[SUCCESS] Module passed %d random test cases", num_test_cases);
      $finish;
    end

    task automatic reset_dut();
        i_rstn <= '0;
        repeat(2) @(negedge i_pixel_clk);
        i_rstn <= '1;
    endtask

    task automatic shift_single_bit(input logic single_bit);
        i_data <= single_bit;
        @(negedge i_pixel_clk);
    endtask 

    task automatic shift_in_seq(input logic[`SEQ_LEN-1:0] seq);
    for (int i = `SEQ_LEN -1; i >= 0; i= i - 1 ) begin
      	i_data <= seq[i];
      	@(negedge i_pixel_clk);
        end
    endtask

    task automatic assert_tranform(input logic[`SEQ_LEN-1:0] seq);
        assert (o_transform == seq) 
        else  $fatal(1, "o_transform is not the correct value @ t= %0t,\n\t expected o_transform = %d \n\t actual o_transform = %d", $time, seq, o_transform);
    endtask 

    task automatic assert_dut_reset();
        assert (o_transform == '0) 
        else   $fatal(1, "o_transform is not being reset @ t= %0t", $time);
    endtask  

endmodule
