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
Ubuntu 15.10
Linux 4.2.0-19-generic x86_64 GNU/Linux
Intel(R) Core(TM) i7-4700MQ CPU @ 2.40GHz
g++ (GCC) 5.2.0
Python 2.7.10
=== End System info

./split5.py        Python: Saw 20000000 lines (60000000 words/806116396 chars) in 16.0 seconds.  Crunch Speed: 1248867.0
pypy ./split5.py   Python: Saw 20000000 lines (60000000 words/806116396 chars) in 3.9 seconds.  Crunch Speed: 5188371.6
./split.py         Python: Saw 20000000 lines (60000000 words/806116396 chars) in 15.2 seconds.  Crunch Speed: 1314968.6
pypy ./split.py    Python: Saw 20000000 lines (60000000 words/806116396 chars) in 3.4 seconds.  Crunch Speed: 5827597.5
./split1           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 5.1 seconds.  Crunch speed: 3916771.3
./split2           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 11.6 seconds.  Crunch speed: 1718342.1
./split3           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 2.6 seconds.  Crunch speed: 7670585
./split6           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 1.6 seconds.  Crunch speed: 12465878.2
./split7           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 1.4 seconds.  Crunch speed: 14098300.6
./split8           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 12.9 seconds.  Crunch speed: 1547788.4
./split9           C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 15.0 seconds.  Crunch speed: 1335624.9
./splitc1          C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 4.8 seconds.  Crunch speed: 4136194.0
./splitc2          C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 5.1 seconds.  Crunch speed: 3933352.2
./splitc3          C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 4.3 seconds.  Crunch speed: 4653897.3
./split_subparser  C++   : Saw 20000000 lines (60000000 words/806116396 chars) in 1.2 seconds.  Crunch speed: 16071186.4
