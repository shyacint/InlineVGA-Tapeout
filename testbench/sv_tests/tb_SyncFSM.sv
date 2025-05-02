`timescale 1ns/1ps

`define CLK_PERIOD           10

`define ACTIVE_VIDEO_WIDTH   640
`define SYNC_PULSE_WIDTH     96
`define FRONT_PORCH_WIDTH    16
`define BACK_PORCH_WIDTH     48
`define TOTAL_PIXEL_WIDTH (`ACTIVE_VIDEO_WIDTH + `BACK_PORCH_WIDTH + `SYNC_PULSE_WIDTH + `FRONT_PORCH_WIDTH)
`define NUM_LINES           2   
module tb_SyncFSM();

    // driver signals 
    logic i_rstn;
    logic i_pixel_clk;

    // signals of interest
    logic [$clog2(`TOTAL_PIXEL_WIDTH) : 0] o_pixel_idx;
    logic o_active_video;
    logic o_sync;

    SyncFSM #(
      .ACTIVE_VIDEO_WIDTH   (`ACTIVE_VIDEO_WIDTH),
      .SYNC_PULSE_WIDTH     (`SYNC_PULSE_WIDTH),
      .FRONT_PORCH_WIDTH    (`FRONT_PORCH_WIDTH),
      .BACK_PORCH_WIDTH     (`BACK_PORCH_WIDTH)
    ) dut (
        .i_rstn             (i_rstn),
        .i_pixel_clk        (i_pixel_clk),
        .o_pixel_idx        (o_pixel_idx),
      .o_active_video     (o_active_video),
        .o_sync             (o_sync)
    );

    // tb book keeping
    int cc_passed = 0;

    always #(`CLK_PERIOD/2) i_pixel_clk=~i_pixel_clk;

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars;
    end

    initial begin
        i_rstn			<= '1;
        i_pixel_clk     <= '0;
        @(posedge i_pixel_clk);
    
        reset_dut();
        assert_dut_reset();

        reset_dut();
      while (cc_passed <= `TOTAL_PIXEL_WIDTH * `NUM_LINES) begin
           if ($urandom_range(0, 2*`TOTAL_PIXEL_WIDTH) == 0) begin
            reset_dut();
            assert_dut_reset();
            cc_passed = 1;
           end else begin
            @(posedge i_pixel_clk);
            if (cc_passed > `SYNC_PULSE_WIDTH +  `BACK_PORCH_WIDTH 
                && cc_passed < `SYNC_PULSE_WIDTH +  `BACK_PORCH_WIDTH + `ACTIVE_VIDEO_WIDTH) begin
              assert_video_idx_sync(cc_passed % `TOTAL_PIXEL_WIDTH);
            end else begin
              assert_pixel_idx(cc_passed % `TOTAL_PIXEL_WIDTH);
            end
            cc_passed++;
           end
        end

      repeat(10) @(posedge i_pixel_clk);
        $display("Testbench finished with no errors");
        $finish();
    end

    task automatic reset_dut();
        i_rstn <= '0;
        @(negedge i_pixel_clk);
        i_rstn <= '1;
        @(posedge i_pixel_clk);
        cc_passed = 1;
    endtask //automatic

    task automatic assert_dut_reset();
    assert(o_pixel_idx == '0)
        else $display("[ERROR] o_pixel_idx did not reset proper @ t = %0t", $time);
    assert(o_active_video == '0)
        else $fatal(1,"[ERROR] o_active_video did not reset proper @ t = %0t", $time);
    endtask //automatic assert_dut_reset  

    task automatic assert_video_idx_sync(int cycles_passed);
        @(negedge i_pixel_clk) begin
            assert (o_active_video == '1)
            else $display("[ERROR] o_active_vido is incorrect @ t= %0t", $time);
            assert (o_pixel_idx == cycles_passed)
            else $display("[ERROR] o_pixel_idx does not match clock cycles passed @ t= %0t", $time);
            assert (o_sync == '1)
            else $fatal(1, "[ERROR] sync signal does not match vga timing specs @ t= %0t, cc_passed = %d", $time, cc_passed);
        end
    endtask

    task automatic assert_pixel_idx(int cycles_passed);
        @(negedge i_pixel_clk) assert (o_pixel_idx == cycles_passed)
        else $fatal(1, "[ERROR] o_pixel_idx does not match clock cycles passed @ t= %0t", $time);
    endtask //automatic
  
endmodule