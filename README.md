These are the benchmarks used in my post,
["Comparing the Cost of Different Multiple-return Techniques in C"](1).

[1]: http://spin.atomicobject.com/2013/12/23/c-return-multiple-values/


# Dependencies

You'll need a C compiler (C99), a POSIX environment, and
[gnuplot](http://www.gnuplot.info/) for creating the graphs.

# Usage

To generate reports at -O0 and -O2 for the execution environment, use
the `make report` target. To generate graphs based on all available
processed reports (.rpt files), use `make graphs`. They will be output
in the graphs/ directory.
