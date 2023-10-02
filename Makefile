myrv.json: firmware au.v lu.v cu.v alu.v decoder.v immdecoder.v furv.v rom.v ram.v uart.v top.v build.ys
	yosys build.ys
	# yosys -p "read_verilog au.v lu.v cu.v alu.v decoder.v immdecoder.v furv.v rom.v ram.v uart.v top.v; proc; synth_gowin -json myrv.json";

pnrmyrv.json: myrv.json tangnano9k.cst
	nextpnr-gowin --json $< --write $@ --device GW1NR-LV9QN88PC6/I5 --family GW1N-9C --cst tangnano9k.cst --router router2 --freq 24 --placer-heap-timingweight 30 --detailed-timing-report

himbaechel-pnrmyrv.json: myrv.json tangnano9k.cst
	nextpnr-himbaechel --json $< --write $@ --device GW1NR-LV9QN88PC6/I5 --vopt family=GW1N-9C --vopt cst=tangnano9k.cst --router router2 --placer-heap-timingweight 30

myrv.fs: pnrmyrv.json
	gowin_pack -d GW1N-9C -o myrv.fs pnrmyrv.json

himbaechel-myrv.fs: himbaechel-pnrmyrv.json
	gowin_pack -d GW1N-9C -o himbaechel-myrv.fs himbaechel-pnrmyrv.json

count.o: count.c
	riscv32-none-elf-gcc -c -nostdlib -ffreestanding -O1 -march=rv32i -mabi=ilp32 -fno-unroll-loops -o count.o count.c 

crt0.o: crt0.s
	riscv32-none-elf-gcc -c -march=rv32i -mabi=ilp32 -o crt0.o crt0.s

count.elf: crt0.o count.o memory.x
	riscv32-none-elf-ld -e _start --gc-sections -T memory.x -static crt0.o count.o -o count.elf 	

count.bin: count.elf
	riscv32-none-elf-objdump -D count.elf; riscv32-none-elf-objcopy -O binary count.elf count.bin 

firmware: count.bin
	{ echo @00000000 ; { hexdump -v -e '1/1 "%02x "' count.bin; yes '00 ' | tr -d '\n'; } | head -c 768; } > firmware

furv.cpp: count.bin au.v lu.v cu.v alu.v decoder.v immdecoder.v furv.v
	yosys -q -l cxxrtl.log -p "read_verilog au.v lu.v cu.v alu.v decoder.v immdecoder.v furv.v; hierarchy -top furv;; proc;; splitnets w:*EN* ;; flatten;; opt;; wreduce;; opt -fine -full;; wreduce;; opt_clean -purge;; write_cxxrtl furv.cpp"

sim: sim.cpp furv.cpp
	g++ -O3 -std=c++14 -I `yosys-config --datdir`/include sim.cpp -o sim

.PHONY: clean

clean:
	rm -f myrv.json pnrmyrv.json myrv.fs himbaechel-pnrmyrv.json himbaechel-myrv.fs
