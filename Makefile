CFLAGS += -std=c99 -Wall -Wextra -pedantic
OPT=2
CFLAGS += -O${OPT} -DOPT=${OPT}

OBJS=	r_control.o \
	r_global.o \
	r_mutate.o \
	r_struct.o \

all: main

main: main.o ${OBJS}
	${CC} -o $@ main.o ${OBJS}

*.o: Makefile


########################################################################
# User Targets
########################################################################

# Make a report for the current hardware: build the
# benchmarks for -O0 and -O2, then do some awk reworking
# of the output to prepare it for gnuplot.
report:
	mk_report

# Use gnuplot to convert every .rpt file to a histograph in graphs/ .
graphs:
	mk_graphs *.rpt

clean:
	rm -f *.o main

distclean: clean
	rm -f report_* graphs/*
