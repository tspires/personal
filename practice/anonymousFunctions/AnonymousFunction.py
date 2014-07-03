#!/usr/bin/python
import sys

def main():
	data = open(sys.argv[1],'r')
	fn = lambda x : x**2
	iter(fn,data)

def iter(fn,data):
	for i in data:
		print fn(int(i))




if __name__ == '__main__':
	main()
