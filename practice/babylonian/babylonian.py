#!/usr/bin/python
import math
import sys
import os
import datetime

def roughestimate(x):
	d = len(str(x))
	if d % 2 == 0:
		n = (d - 2) / 2
		return 6*(10**n)
	else:
		n = (d - 1) / 2 
		return 2*(10**2)

def computesqrt(x):
	start = datetime.datetime.now()
	x0 = float(roughestimate(x))
	xn = x0
	x = float(x)
	while 1:
		x0 = xn
		xn = 0.5 * (xn + x / xn)
		if (int(x0*1000) - int(xn*1000))==0:
			end = datetime.datetime.now()
			delta = start - end
			print delta.microseconds
			return xn
print computesqrt(625)
