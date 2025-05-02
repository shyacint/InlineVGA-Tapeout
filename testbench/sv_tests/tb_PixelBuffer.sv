`timescale 1ns / 1ps

// tb related constants
`define MAX_NUM_TEST 1000    

// dut related constants
`define BUFFER_DEPTH 8
`define BUFFER_DATA_WIDTH 9

module tb_PixelBuffer ();

  // stimulus signals 
  logic i_rstn;
  logic i_pixel_clk;
  logic [2:0] i_red, i_green, i_blue;
  logic i_we, i_re;

  // observation signals
  logic o_full, o_empty;
  logic [2:0] o_red, o_green, o_blue;

  // tb book-keeping
  int num_test_case = 0;
  int golden_model_size = 0;
  logic [`BUFFER_DATA_WIDTH -1:0] golden_model[$:`BUFFER_DEPTH];

  logic rnd_rstn;
  logic rnd_we, rnd_re;
  logic [2:0] rnd_r, rnd_g, rnd_b;

  logic [2:0] golden_r, golden_g, golden_b;

  PixelBuffer #(
      .DEPTH(`BUFFER_DEPTH),
      .DATA_WIDTH(`BUFFER_DATA_WIDTH)
  ) dut (
      .i_rstn(i_rstn),
      .i_pixel_clk(i_pixel_clk),
      .i_red(i_red),
      .i_green(i_green),
      .i_blue(i_blue),
      .i_we(i_we),
      .i_re(i_re),

      .o_full (o_full),
      .o_empty(o_empty),
      .o_red  (o_red),
      .o_green(o_green),
      .o_blue (o_blue)
  );

  // clk gen
  always #5 i_pixel_clk = ~i_pixel_clk;

  initial begin
    // vcd generation
    $dumpfile("dump.vcd");
    $dumpvars;

    // initial values
    i_pixel_clk              <= '0;
    i_rstn                   <= '1;
    {i_red, i_green, i_blue} <= '1;
    i_we                     <= '1;
    i_re                     <= '1;

    reset_dut();

    assert ({o_red, o_green, o_blue} == '0)
    else begin
      $display("[ERROR] Mismatch detected at time %0t", $time);
      $fatal(1, "[ERROR] Async reset failure");
    end

    assert ((o_empty == '1) && (golden_model.size() == 0))
    else begin
      $display("[ERROR] Mismatch detected at time %0t", $time);
      $fatal(1, "[ERROR] o_empty not detected...");
    end

    //confirm fifo
    i_rstn = '1;
    generate_rnd_rgb(rnd_r, rnd_g, rnd_b);
    write_to_buffer(rnd_r,rnd_g,rnd_b);
    read_from_buffer(golden_r, golden_g, golden_b);
    assert ({o_red, o_green, o_blue} == {golden_r, golden_g, golden_b})
    else begin
      $display("[ERROR] Mismatch detected at time %0t", $time);
      $display("[ERROR] Actual   r= %d, g= %d, b=%d", o_red, o_green, o_blue);
      $display("[ERROR] Expected r= %d, g= %d, b=%d", golden_r, golden_g, golden_b);
      repeat(2) @(posedge i_pixel_clk);
      $fatal(1, "[ERROR] FIFO is not FIFO'ing...");
    end

    // confirm full - minus one since we leave last spot unoccupied
    reset_dut();
    for (int i = 0; i < `BUFFER_DEPTH -1; i = i + 1) begin
      generate_rnd_rgb(rnd_r, rnd_g, rnd_b);
      write_to_buffer(rnd_r,rnd_g,rnd_b);
    end
    assert_buffer_full();
	
    // minus two because after first read the buffer should not be full = DEPTH -1
    for (int i = `BUFFER_DEPTH - 2; i >= 0 ; i = i - 1) begin
      read_from_buffer(golden_r, golden_g, golden_b);
      assert ((golden_model.size() == i))
      else begin
        $display("[ERROR] Mismatch detected at time %0t", $time);
        $fatal(1,"[ERROR] Golden Model size =  %d", golden_model.size());
      end
    end
    assert_buffer_empty();
  
    reset_dut();

    while (num_test_case < `MAX_NUM_TEST) begin
      @(posedge i_pixel_clk);
      // generate test stimi for cc
      if ($urandom_range(0,10* `BUFFER_DEPTH) == 0) begin
        reset_dut();
        assert (o_full == '0)
        else begin
          $display("[ERROR] Mismatch detected at time %0t", $time);
          $fatal(1, "[ERROR] o_full did not reset");
        end
        assert_buffer_empty();
      end else begin
        generate_rnd_enables(rnd_we, rnd_re);

        if (rnd_we) begin
          if (!o_full) begin
            generate_rnd_rgb(rnd_r, rnd_g, rnd_b);
            write_to_buffer_with_enables(rnd_we, rnd_re, rnd_r,rnd_g,rnd_b);
          end else begin
            assert_buffer_full();
          end
        end else if (!rnd_we && rnd_re) begin
          //print_dut_state();
          if (!o_empty) begin
            read_from_buffer_with_enables(rnd_we, rnd_re, golden_r, golden_g, golden_b);
            assert ({o_red, o_green, o_blue} == {golden_r, golden_g, golden_b})
            else begin
              $display("[ERROR] Mismatch detected at time %0t", $time);
              print_dut_state();
              $fatal(1, "[ERROR] Not the expected RBG output...");
            end
          end else begin
            assert_buffer_empty();
          end
        end else begin
          // idle
          @(negedge i_pixel_clk);
          	assert ({o_red, o_green, o_blue} == '0)
          else begin
            $display("[ERROR] Mismatch detected at time %0t", $time);
            print_dut_state();
            $fatal(1, "[ERROR] During inactive periods the output should be black...");
          end
        end
      end
      num_test_case++;
    end
    $display("[SUCCESS] Full coverage achieved in total_tests = %0d", num_test_case);
    $finish;
  end
  
  
task automatic reset_dut();
  i_rstn   = '0; // async reset
  i_we      <= '0;
  i_re      <= '0;
  golden_model.delete();
  golden_model_size = golden_model.size();
  @(posedge i_pixel_clk);
  i_rstn <= 1;
  repeat(2) @(posedge i_pixel_clk);
endtask

task automatic write_to_buffer(input logic [2:0] r, input logic [2:0] g, input logic [2:0] b);
  i_we <= '1;
  i_re <= '0;
  {i_red, i_green, i_blue} <= {r, g, b};
  @(posedge i_pixel_clk);
  i_we <= '0;
  i_re <= '0;
  golden_model.push_back({r, g, b});
  golden_model_size = golden_model.size();
endtask


task automatic write_to_buffer_with_enables(input logic we, input logic re, input logic [2:0] r, input logic [2:0] g, input logic [2:0] b);
  i_we <= we;
  i_re <= re;
  {i_red, i_green, i_blue} <= {r, g, b};
  @(posedge i_pixel_clk);
  i_we <= '0;
  i_re <= '0;
  golden_model.push_back({r, g, b});
  golden_model_size = golden_model.size();
endtask

task automatic read_from_buffer(output logic[2:0] golden_r, output logic[2:0] golden_g, output logic[2:0] golden_b);
  i_we <= '0;
  i_re <= '1;
  @(posedge i_pixel_clk);
  i_we <= '0;
  i_re <= '0;
  {golden_r,golden_g, golden_b} = golden_model.pop_front();
  golden_model_size = golden_model.size();
  @(negedge i_pixel_clk);
  // could assert here
endtask

task automatic read_from_buffer_with_enables(input logic we, input logic re,output logic[2:0] golden_r, output logic[2:0] golden_g, output logic[2:0] golden_b);
  i_we <= we;
  i_re <= re;
  @(posedge i_pixel_clk);
  i_we <= '0;
  i_re <= '0;
  {golden_r, golden_g, golden_b} = golden_model.pop_front();
  golden_model_size = golden_model.size();
  @(negedge i_pixel_clk);
	// could assert here
endtask

task automatic generate_rnd_enables(
    output logic rnd_we,
    output logic rnd_re
);
    rnd_we = $urandom_range(0, 1);
    rnd_re = $urandom_range(0, 1);
endtask
  
    
task automatic assert_buffer_full();
  @(negedge i_pixel_clk);
  assert ((o_full == '1) && (golden_model.size() == `BUFFER_DEPTH -1))
  else begin
    $display("[ERROR] Mismatch detected at time %0t", $time);
    @(posedge i_pixel_clk);
    $fatal(1, "[ERROR] o_full not detected ...");
  end
endtask
  
  task automatic assert_buffer_empty();
    @(negedge i_pixel_clk);
    assert ((o_empty == '1) && (golden_model.size() == 0))
      else begin
        $display("[ERROR] Mismatch detected at time %0t", $time);
        print_dut_state();
        $fatal(1, "[ERROR] o_empty not asserting correctly ...");
      end
  endtask

  task automatic print_dut_state();
    $display("[ERROR] Control: i_we= %d, i_re= %d", i_we, i_re);
    $display("[ERROR] Status: o_empty= %d, o_full= %d, golden_model_size= %d", o_empty, o_full, golden_model_size);
    $display("[ERROR] RGB: o_red= %d, o_green= %d, o_blue= %d", o_red, o_green, o_blue);
    @ (posedge i_pixel_clk);
  endtask
  
endmodule

task automatic generate_rnd_rgb(output logic [2:0] r, output logic [2:0] g, output logic [2:0] b);
  r = $urandom_range(0, 7);
  g = $urandom_range(0, 7);
  b = $urandom_range(0, 7);
endtask

