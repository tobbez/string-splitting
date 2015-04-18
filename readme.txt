A collection of C++ benchmarks of string splitting, most of which were collected from:
http://stackoverflow.com/questions/9378500/why-is-splitting-a-string-slower-in-c-than-python

Most of the implementations are taken from the Stack Overflow question, and
some new ones have been added since.

Please keep in mind that this is a micro-benchmark, so the results may not be
representative for your use case.

You can use the provided Makefile to compile all the programs, and
run_tests.bash to run all the test cases.

A script to generate test data, gen_test_data.py, is included. It will
automatically be executed by run_all.bash if the test_data file is not
present. It generates 2,000,000 lines (827MiB) of data.


## Contributing
Additional (significantly different) implementations are welcome. As are
improvements to existing ones.

When contributing, make sure to follow these guidelines for commit messages:
https://gist.githubusercontent.com/tobbez/55686ef79bf0b593d90a/raw/789e64318fd91ac598eb814320cec3f25543a7c3/good-commit-messages.txt


## My results

$ ./run_all.bash
=== System info
Linux 3.11.6-gentoo x86_64 GNU/Linux
AMD Athlon(tm) 64 X2 Dual Core Processor 4200+
g++ (Gentoo 4.8.4 p1.0, pie-0.6.1) 4.8.4
Python 2.7.9
=== End System info

./split.py       Python: Saw 20000000 lines (60000000 words/806116396 chars) in 67.9 seconds.  Crunch Speed: 294678.4
./split5.py      Python: Saw 20000000 lines (60000000 words/806116396 chars) in 71.1 seconds.  Crunch Speed: 281322.7
./split1         C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 26.4 seconds.  Crunch speed: 757283.8
./split2         C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 39.2 seconds.  Crunch speed: 510188.1
./split6         C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 5.7 seconds.  Crunch speed: 3530481.5
./split7         C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 5.4 seconds.  Crunch speed: 3732061.1
./split8         C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 73.0 seconds.  Crunch speed: 273980.9
./split9         C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 45.0 seconds.  Crunch speed: 444797.6
./splitc1        C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 21.1 seconds.  Crunch speed: 947928.4
./splitc2        C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 17.6 seconds.  Crunch speed: 1136069.2
./splitc3        C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 14.3 seconds.  Crunch speed: 1397227.3
