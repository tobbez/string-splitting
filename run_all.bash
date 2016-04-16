#!/bin/bash

if [ ! -f test_data ]
then
	echo "Test data not present, generating"
	./gen_test_data.py > test_data
fi

echo "=== System info"
type lsb_release &> /dev/null && echo $(lsb_release -sir | tr '\n' ' ')
uname -srom
grep '^model name' /proc/cpuinfo | head -n1 | cut -c 14-
g++ --version | head -n1
python --version
echo "=== End System info"
echo
# warming up file
wc test_data
for i in `find . -maxdepth 1 -executable -iname 'split*.py' | sort ; find . -maxdepth 1 -executable \! -iname '*.py' -iname 'split*' | sort`
do
	printf "%-18s " $i
	$i < test_data
done
