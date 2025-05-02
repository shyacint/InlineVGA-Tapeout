import random
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import *


H_SYNC_ACTIVE_VIDEO_WIDTH = 640
H_SYNC_SYNC_PULSE_WIDTH = 96
H_SYNC_FRONT_PORCH_WIDTH = 16
H_SYNC_BACK_PORCH_WIDTH = 48
PIXEL_ROW_MAX = H_SYNC_ACTIVE_VIDEO_WIDTH + H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_FRONT_PORCH_WIDTH + H_SYNC_BACK_PORCH_WIDTH

V_SYNC_ACTIVE_VIDEO_WIDTH = 480
V_SYNC_SYNC_PULSE_WIDTH = 2
V_SYNC_FRONT_PORCH_WIDTH = 10
V_SYNC_BACK_PORCH_WIDTH = 33
PIXEL_COL_MAX = V_SYNC_ACTIVE_VIDEO_WIDTH + V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_FRONT_PORCH_WIDTH + V_SYNC_BACK_PORCH_WIDTH

async def initial_dut(dut):
    dut.i_rstn.value                = 1
    dut.i_pixel_clk.value           = 0
    dut.i_src_active_video.value    = 0
    dut.i_buffer_empty.value        = 1
    await FallingEdge(dut.i_pixel_clk)

async def reset_dut(dut):
    dut.i_rstn.value = 0
    await FallingEdge(dut.i_pixel_clk)
    dut.i_rstn.value = 1

async def assert_hsync_over_N_cycles(dut, val, N):
    for _ in range(0,N):
        await FallingEdge(dut.i_pixel_clk)
        assert dut.o_hsync.value == val

async def assert_vsync_over_N_cycles(dut, val, N):
    for _ in range(0,N):
        await FallingEdge(dut.i_pixel_clk)
        assert dut.o_vsync.value == val


@cocotb.test()
async def test_ResetState(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())

    await initial_dut(dut)
    await reset_dut(dut)

    assert ((dut.o_pixel_buffer_we.value == 0) 
            and (dut.o_pixel_buffer_re.value == 0) 
            and (dut.o_hsync.value == 1) 
            and (dut.o_vsync.value == 1))
    
@cocotb.test()
async def test_HsyncTranstion(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())

    await initial_dut(dut)
    await reset_dut(dut)
    await FallingEdge(dut.i_pixel_clk)
    await assert_hsync_over_N_cycles(dut, 0, H_SYNC_SYNC_PULSE_WIDTH-1)
    await assert_hsync_over_N_cycles(dut, 1, H_SYNC_BACK_PORCH_WIDTH 
                                     + H_SYNC_ACTIVE_VIDEO_WIDTH
                                     + H_SYNC_FRONT_PORCH_WIDTH)

@cocotb.test()
async def test_VsyncTranstion(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())

    await initial_dut(dut)
    await reset_dut(dut)
    await FallingEdge(dut.i_pixel_clk)
    await assert_vsync_over_N_cycles(dut, 0, V_SYNC_SYNC_PULSE_WIDTH-1)
    await assert_vsync_over_N_cycles(dut, 1, V_SYNC_BACK_PORCH_WIDTH 
                                     + V_SYNC_ACTIVE_VIDEO_WIDTH
                                     + V_SYNC_FRONT_PORCH_WIDTH)

@cocotb.test()
async def test_IntermediateResetHsync(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())

    await initial_dut(dut)
    await reset_dut(dut)
    await FallingEdge(dut.i_pixel_clk)
    for _ in range(0, PIXEL_ROW_MAX):
        if random.randint(0,int(PIXEL_ROW_MAX/2)) == 0:
            reset_dut(dut)
        else:
            if dut.pixel_col.value.integer < H_SYNC_SYNC_PULSE_WIDTH:
                assert_hsync_over_N_cycles(dut, 0, 1)
            else:
                assert_hsync_over_N_cycles(dut, 1, 1)

@cocotb.test()
async def test_IntermediateResetVsync(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())

    await initial_dut(dut)
    await reset_dut(dut)
    await FallingEdge(dut.i_pixel_clk)
    for _ in range(0, PIXEL_COL_MAX):
        if random.randint(0,int(PIXEL_COL_MAX/2)) == 0:
            reset_dut(dut)
        else:
            if dut.pixel_col.value.integer < V_SYNC_SYNC_PULSE_WIDTH:
                assert_vsync_over_N_cycles(dut, 0, 1)
            else:
                assert_vsync_over_N_cycles(dut, 1, 1)   


@cocotb.test()
async def test_PixelBufferRE(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())
    await initial_dut(dut)
    await reset_dut(dut)
    dut.i_buffer_empty.value = 0
    await FallingEdge(dut.i_pixel_clk)
    
    for _ in range(0, max(PIXEL_ROW_MAX, PIXEL_COL_MAX)):
        await FallingEdge(dut.i_pixel_clk)
        if (dut.pixel_col.value.integer > (H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_BACK_PORCH_WIDTH) 
            and dut.pixel_col.value.integer < (H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_BACK_PORCH_WIDTH + H_SYNC_ACTIVE_VIDEO_WIDTH -1)
            and dut.pixel_row.value.integer > (V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_BACK_PORCH_WIDTH) 
            and dut.pixel_row.value.integer < (V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_BACK_PORCH_WIDTH + V_SYNC_ACTIVE_VIDEO_WIDTH -1)):
            assert dut.o_pixel_buffer_re.value.integer == 1

@cocotb.test()
async def test_IntermediateResetRE(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())
    await initial_dut(dut)
    await reset_dut(dut)
    dut.i_buffer_empty.value = 0
    await FallingEdge(dut.i_pixel_clk)

    for _ in range(0, max(PIXEL_ROW_MAX, PIXEL_COL_MAX)):
        if random.randint(0,int(PIXEL_ROW_MAX/2)) == 0:
            reset_dut(dut)
        else:
            await FallingEdge(dut.i_pixel_clk)
            if (dut.pixel_col.value.integer > (H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_BACK_PORCH_WIDTH) 
                and dut.pixel_col.value.integer < (H_SYNC_SYNC_PULSE_WIDTH + H_SYNC_BACK_PORCH_WIDTH + H_SYNC_ACTIVE_VIDEO_WIDTH -1)
                and dut.pixel_row.value.integer > (V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_BACK_PORCH_WIDTH) 
                and dut.pixel_row.value.integer < (V_SYNC_SYNC_PULSE_WIDTH + V_SYNC_BACK_PORCH_WIDTH + V_SYNC_ACTIVE_VIDEO_WIDTH -1)):
                assert dut.o_pixel_buffer_re.value.integer == 1
    pass