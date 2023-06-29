############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FIR_VIVADO
set_top SYSTEM
add_files FIR_VIVADO/fir.cpp
add_files FIR_VIVADO/fir.h
add_files -tb FIR_VIVADO/tb_fir.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb FIR_VIVADO/tb_fir.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb FIR_VIVADO/main.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {-}
create_clock -period 10 -name default
config_export -format ip_catalog -vivado_optimization_level 2 -vivado_phys_opt place -vivado_report_level 0
set_clock_uncertainty 0
source "./FIR_VIVADO/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -tool modelsim
export_design -format ip_catalog
