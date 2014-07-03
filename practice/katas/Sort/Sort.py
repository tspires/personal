#!/usr/bin/python

class Main():
	def __init__(self):
		self.logo()
		lst = [1,4,6,7,8,2]
		sort = Sort()
		sort.algorithms["insertion"](lst)
	def logo(self):
		logo_file = open('logo','r')
		logo = logo_file.read()
		print logo

class Sort(object):
	def __init__(self):
		self.algorithms = {}
		self.algorithms["insertion"] = self.insertionSort
	
	def insertionSort(self,lst):
		print "Using Insertion Sort..."
		for i in range(len(lst)):
			j = i
			while j > 0 and lst[j - 1] > lst[j]:
				lst = self.switch(lst,lst[j],lst[j-1])
				j -= 1
		print lst
	def switch(self,lst,a,b):
		tmp = lst[a]
		lst[a] = lst[b]
		lst[b] = lst[a]
		return lst

	def getPos(self,lst,a):
		for pos,i in enumerate(lst):
			if i == a: return pos 
			
if __name__ == '__main__':
	app = Main()

