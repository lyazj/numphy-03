#!/usr/bin/env -S make -f

include ../Makefile.conf

# CFLAGS := $(subst -O3,-Og,$(CFLAGS))
BIN := $(filter-out intg,$(BIN))
RUN += intg-plot
OUT += intg-plot.pdf

include ../Makefile.rule

intg.o intg-test.o intg-smp.o: intg.h
intg-test intg-smp: intg.o
intg-plot.run: intg-smp.out
