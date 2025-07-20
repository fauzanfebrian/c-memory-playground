.PHONY: run clean

file ?= main.c
out := $(basename $(file)).exe

run:
	gcc $(file) -o $(out)
	./$(out)

clean:
	rm -f *.exe
