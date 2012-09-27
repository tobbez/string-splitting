#!/bin/bash

if [ ! -f test_data ]
then
	echo "Test data not present, generating"
	./gen_test_data.py > test_data
fi

echo "=== System info"
uname -srpom
g++ --version | head -n1
python --version
echo "=== End System info"
echo

for i in `find . -maxdepth 1 -executable -iname 'split*.py' | sort ; find . -maxdepth 1 -executable \! -iname '*.py' -iname 'split*' | sort`
do
	printf "%-16s " $i
	$i < test_data
done
