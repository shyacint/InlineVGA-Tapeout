TOPLEVEL_LANG = verilog
SIM = verilator

EXTRA_ARGS += --trace --trace-structs -Wno-fatal

VERILOG_SOURCES = \
    ../src/SyncFSM.sv \
    ../src/OutputMonitor.sv

TOPLEVEL = OutputMonitor
MODULE = tb_OutputMonitor

include $(shell cocotb-config --makefiles)/Makefile.sim
