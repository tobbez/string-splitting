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
    dummy = line.split()
    numWords += len(dummy)
    for s in dummy:
        numChars += len(s)
    count += 1

delta_sec = float(time.time() - start_time)
print("Python: Saw {0} lines ({1} words/{2} chars) in {:3.1f} seconds.".format(count, numWords, numChars, delta_sec), end='')
if delta_sec > 0:
    lps = count/delta_sec
    print("  Crunch Speed: {:0.1f}".format(lps))
else:
    print('')
