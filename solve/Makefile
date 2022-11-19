#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out solve,$(BIN))
RUN += func-plot solve-plot zero-plot
OUT += func-plot.pdf solve-plot.pdf zero-plot.pdf

include ../Makefile.rule

solve.o solve-test.o solve-equ.o: solve.h
solve-test solve-equ: solve.o
solve-plot.run: solve-equ.out
