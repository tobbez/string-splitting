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
Linux 3.13.0-57-generic x86_64 GNU/Linux
Intel(R) Core(TM) i7-2720QM CPU @ 2.20GHz
g++ (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4
Python 2.7.6
=== End System info

./split5.py        Python: Saw 20000000 lines (60000000 words/806116396 chars) in 31.2 seconds.  Crunch Speed: 641052.9
./split.py         Python: Saw 20000000 lines (60000000 words/806116396 chars) in 30.6 seconds.  Crunch Speed: 654202.5
./split1           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 15.5 seconds.  Crunch speed: 1293952.3
./split2           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 25.7 seconds.  Crunch speed: 776855.9
./split6           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 3.1 seconds.  Crunch speed: 6493252.9
./split7           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 3.0 seconds.  Crunch speed: 6652254.0
./split8           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 48.0 seconds.  Crunch speed: 416639.5
./split9           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 27.9 seconds.  Crunch speed: 715600.7
./splitc1          C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 12.8 seconds.  Crunch speed: 1566162.6
./splitc2          C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 11.2 seconds.  Crunch speed: 1784909.5
./splitc3          C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 10.1 seconds.  Crunch speed: 1979358.4
./split_subparser  C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 2.3 seconds.  Crunch speed: 8742942.4

