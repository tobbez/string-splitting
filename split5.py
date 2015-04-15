#!/usr/bin/env python

# http://stackoverflow.com/q/9378500/106471

from __future__ import print_function                                            
import time
import sys

count = 0
start_time = time.time()
dummy = None
numWords = 0
numChars = 0

for line in sys.stdin:
    dummy = []
    dummy = line.split()
    numWords += len(dummy)
    for s in dummy:
        numChars += len(s)
    count += 1

delta_sec = int(time.time() - start_time)
print("Python: Saw {0} lines ({1} words/{2} chars) in {3} seconds.".format(count, numWords, numChars, delta_sec), end='')
if delta_sec > 0:
    lps = int(count/delta_sec)
    print("  Crunch Speed: {0}".format(lps))
else:
    print('')
