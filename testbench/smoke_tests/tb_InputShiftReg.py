import random
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import *

NUM_RND_TEST = 1000


async def init_dut(dut):
    dut.i_rstn.value          = 1 # active low reset
    dut.i_pixel_clk.value     = 0
    dut.i_data.value          = 0
    await FallingEdge(dut.i_pixel_clk)

async def reset_dut(dut):
    dut.i_rstn.value = 0
    await FallingEdge(dut.i_pixel_clk)
    dut.i_rstn.value = 1


async def shift_single_bit(dut, bit_val):
    dut.i_data.value = bit_val
    await FallingEdge(dut.i_pixel_clk)


@cocotb.test()
async def test_ResetState(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())
    await init_dut(dut)
    await reset_dut(dut)

    await FallingEdge(dut.i_pixel_clk)
    assert dut.o_transform.value == 0


@cocotb.test()
async def test_ShiftRegOutput(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())
    await init_dut(dut)
    await reset_dut(dut)

    for _ in range(0,NUM_RND_TEST):
        rnd_val     = random.randint(0,7)
        rnd_val_bin = [int(b) for b in f"{rnd_val:03b}"]
        for bit in rnd_val_bin:
            await shift_single_bit(dut, bit)
        assert dut.o_transform.value.integer == rnd_val

@cocotb.test()
async def test_IntermediateReset(dut):
    print("============== STARTING TEST ==============")
    cocotb.start_soon(Clock(dut.i_pixel_clk, 10, units="ns").start())
    await init_dut(dut)
    await reset_dut(dut)

    for _ in range(0,NUM_RND_TEST):
        rnd_val     = random.randint(0,7)
        rnd_val_bin = [int(b) for b in f"{rnd_val:03b}"]
        for bit_idx, bit in enumerate(rnd_val_bin):
            if random.randint(0,9) == 0:
                await reset_dut(dut)
                assert dut.o_transform.value == 0
                break
            else:
                await shift_single_bit(dut, bit)
                if bit_idx == len(rnd_val_bin) -1:
                    assert dut.o_transform.value.integer == rnd_val




