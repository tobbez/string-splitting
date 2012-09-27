#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright (c) 2012, Torbjörn Lönnemark <tobbez@ryara.net>
#
from __future__ import print_function                                            
import string
import random
import sys

# shouldn't matter much, but we want to generate the same data every time
random.seed(42)

chars = list(string.ascii_lowercase)
for i in xrange(1,20000001):
    random.shuffle(chars)
    s1 = ''.join(chars[:6])
    s2 = ''.join(chars[6:16])
    print ("{0} {1}.{2}.{3}.{4} {5}".format(s2, random.randint(1,255), random.randint(1,255), random.randint(1,255), random.randint(1,255), s1 + '.' + s2))
    if i % 10000 == 0:
        sys.stderr.write("\r{0}".format(i))
        sys.stderr.flush()

sys.stderr.write("\n")
