#!/usr/bin/python

class Main():
	def __init__(self):
		self.logo()
		cashier = Cashier()
		try:
			while ( True ):
				try:
					cashier.printLeast(raw_input("Please enter a value: "))
				except KeyboardInterrupt:
					raise
		except KeyboardInterrupt:
			print("Terminated...")

	def logo(self):
		logo_file = open('logo','r')
		logo = logo_file.read()
		print logo

class Cashier():
	
	def printLeast(self,value):
		coins = []
		coins.append(Coin(25,'Quarter'))
                coins.append(Coin(10,'Dime'))
                coins.append(Coin(5,'Nickel'))
                coins.append(Coin(1,'Penny'))
		remaining = value
		while remaining > 0:
			for coin in coins:
				print coin.value 
class Coin():
	def __init__(self, value, name):
		self.value = value
		self.name = name

if __name__ == '__main__':
	app = Main()

