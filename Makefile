.PHONY: run clean

file ?= main.c
out := $(basename $(file)).exe
asm := $(basename $(file)).asm

run:
	gcc $(file) -o $(out)
	./$(out)
run-explain:
	gcc -Wall $(file) -o $(out)
	./$(out)
compile-asm:
	gcc -S -masm=intel $(file) -o $(asm)

clean:
	rm -f *.exe
