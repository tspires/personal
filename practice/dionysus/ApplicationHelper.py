#!/usr/bin/python
from subprocess import Popen, PIPE

logo = open('logo','r').read()

def figlet(text):
	p = Popen(['figlet',text], stdout=PIPE, stderr=PIPE, stdin=PIPE)
	fig = p.stdout.read()
	return fig
