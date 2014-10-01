#!/usr/bin/python

import random 
import sys
   

if len(sys.argv) != 3:
    print sys.argv[0] + " total range"
    sys.exit(0)

t = int(sys.argv[1])
r = int(sys.argv[2])
print t
for i in [random.randint(1, r) for i in range(t)]:
    print i

