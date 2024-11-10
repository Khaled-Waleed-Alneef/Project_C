FILENAME="" 


assemble: assembler.c acode.c
	@gcc -c assembler.c acode.c
	@gcc -o assembler assembler.o acode.o
	@./assembler $(FILENAME)

simulate: simulator.c ALU.c decoder.c fetch.c loader.c mux.c 
	@gcc -c simulator.c ALU.c decoder.c fetch.c loader.c mux.c
	@gcc -o simulator simulator.o ALU.o decoder.o fetch.o loader.o mux.o
	@./simulator $(FILENAME)

all:	assemble simulate

clean: 
	@rm -f simulator simulator.o ALU.o decoder.o fetch.o loader.o mux.o assembler.o acode.o assembler $(FILENAME).bin

help: 
	@echo "make assemble FILENAME=<your_file>: To Compile and Run The Assembler Code"
	@echo "make simulate FILENAME=<your_file>: To Start Simulating Your File"
	@echo "make all FILENAME=<your_file>: To Compile and Run The Assembler Code and Start Simulating Your File"
	@echo "make cleanFILENAME=<your_file>: To Remove Compiled and Executable Files and Your Result File e.g(fibonacci.bin)"
	@echo "#NOTE: Do NOT Add Any Extension e.g (.bin) to FILENAME"

	
