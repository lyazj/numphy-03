#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out solve,$(BIN))
RUN +=
OUT +=

include ../Makefile.rule

solve.o solve-test.o: solve.h
solve-test: solve.o
