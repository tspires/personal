#!/usr/bin/python
import sys
import os
class Generator(object):
	def __init__(self,args):
		print self.generateLogo("ARTEMIS")
	def generateLogo(self,text):
		logo = os.popen("figlet {0}".format(text))
		return logo.read()

if __name__ == '__main__':
	Generator(sys.argv)
