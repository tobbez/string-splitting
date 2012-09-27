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


My results (AMD Athlon(tm) 64 X2 4200+) are:

  split1.cpp:  C++   : Saw 20000000 lines in 31 seconds.  Crunch speed: 645161
  split2.cpp:  C++   : Saw 20000000 lines in 45 seconds.  Crunch speed: 444444
  split.py:    Python: Saw 20000000 lines in 33 seconds.  Crunch Speed: 606060
  split5.py:   Python: Saw 20000000 lines in 35 seconds.  Crunch Speed: 571428
  split6.cpp:  C++   : Saw 20000000 lines in 18 seconds.  Crunch speed: 1111111

  splitc1.cpp: C++   : Saw 20000000 lines in 27 seconds.  Crunch speed: 740740
  splitc2.cpp: C++   : Saw 20000000 lines in 22 seconds.  Crunch speed: 909090
  splitc3.cpp: C++   : Saw 20000000 lines in 20 seconds.  Crunch speed: 1000000
