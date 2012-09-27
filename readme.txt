A collection of C++ benchmarks of string splitting, most of which were collected from:
http://stackoverflow.com/questions/9378500/why-is-splitting-a-string-slower-in-c-than-python

splitc{1,2,3}.cpp were written by me, the others were taken from the
Stack Overflow.

You can use the provided Makefile to compile all the programs, and
run_tests.bash to run all the test cases.

I have also included a script to generate test data (gen_test_data.py).
It generates 2,000,000 lines (827MiB) of data on standard output.
Generate a test file with:
./gen_test_data.py > test_data


My results are:

$ ./run_all.bash
=== System info
Linux 3.4.4-gentoo x86_64 AMD Athlon(tm) 64 X2 Dual Core Processor 4200+ GNU/Linux
g++ (Gentoo 4.6.3 p1.3, pie-0.5.1) 4.6.3
Python 2.7.3
=== End System info

./split.py       Python: Saw 20000000 lines in 25 seconds.  Crunch Speed: 800000
./split5.py      Python: Saw 20000000 lines in 28 seconds.  Crunch Speed: 714285
./split1         C++   : Saw 20000000 lines in 26 seconds.  Crunch speed: 769230
./split2         C++   : Saw 20000000 lines in 39 seconds.  Crunch speed: 512820
./split6         C++   : Saw 20000000 lines in 11 seconds.  Crunch speed: 1818181
./split7         C++   : Saw 20000000 lines in 3 seconds.  Crunch speed: 6666666
./splitc1        C++   : Saw 20000000 lines in 17 seconds.  Crunch speed: 1176470
./splitc2        C++   : Saw 20000000 lines in 16 seconds.  Crunch speed: 1250000
./splitc3        C++   : Saw 20000000 lines in 13 seconds.  Crunch speed: 1538461

