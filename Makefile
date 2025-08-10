.PHONY: run clean

file ?= main.c
out := $(basename $(file)).exe
asm := $(basename $(file)).asm

run:
	gcc -fdiagnostics-color=always $(file) -o $(out)
	./$(out)
run-explain:
	gcc -fdiagnostics-color=always -Wall $(file) -o $(out)
	./$(out)
compile-asm:
	gcc -S -masm=intel $(file) -o $(asm)

clean:
	rm -f **/*.exe
	rm -f **/*.asm
