// Code your testbench here
// or browse Examples
`timescale 1ns/1ps

`define MAX_NUM_TESTS   100
`define CLK_PERIOD     10

module tb_SystemEnable();

    // driver signals
    logic     i_rstn;
    logic     i_clk;     
    logic     i_src_vsync;    

    // observable signals
    logic    o_enable;
  
  	//tb book keeping
  	int num_test_cases = 0;

    SystemEnable dut (
        .i_rstn(i_rstn),
        .i_clk(i_clk),
        .i_src_vsync(i_src_vsync),

        .o_enable(o_enable)
    );

    always #((`CLK_PERIOD/2)) i_clk = ~i_clk;

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end

    initial begin
        // initial values
        i_rstn	  <= '1;
        i_clk       <= '0;
        i_src_vsync <= '1;

        reset_dut();
        assert_dut_reset();
        
        // turn on pixel clk
        sync_pulse_vsync();
      
        while(num_test_cases < `MAX_NUM_TESTS) begin
            if ($urandom_range(0,10) == 0) begin
                reset_dut();
                assert_dut_reset();
            end else begin
                if($urandom_range(0,1) == 0) begin
                    sync_pulse_vsync();
                end else begin
                async_pulse_vsync($urandom_range(0, `CLK_PERIOD));
                end
                assert_enable();
            end
            num_test_cases++;
        end
      
      $display("[SUCCESS] Test cases passed. Pixel Clock now verified!");
      $finish();
    end

    task automatic reset_dut();
        i_rstn <= '0;
        repeat(2) @(posedge i_clk);
        i_rstn <= '1;
    endtask 

    task automatic sync_pulse_vsync();
        i_src_vsync <= '0;
        @ (posedge i_clk);
        i_src_vsync <= '1;
      repeat(3) @ (posedge i_clk);
    endtask

    task automatic async_pulse_vsync(int pulse_width_ns);
        #(pulse_width_ns) i_src_vsync = '0;
        @ (posedge i_clk);
        i_src_vsync <= '1;
        repeat(3) @ (posedge i_clk);
    endtask  

    task automatic assert_dut_reset();
        assert (o_enable == 0) 
        else $fatal(1,"[ERROR] o_enable is not resetting properly @ t= %0t", $time);
    endtask 

    task automatic assert_enable();
        repeat(3) @(negedge i_clk)
        assert (o_enable == 1) 
        else $fatal(1,"[ERROR] o_enable vsync falling edge not detected @ t= %0t", $time);  
    endtask

endmodule