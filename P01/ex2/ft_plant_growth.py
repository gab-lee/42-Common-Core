#!/usr/bin/env python3

class Plant:
	def __init__(self, name, height, age):
		self.name = name
		self.height= height
		self.daysold = age

	def show(self):
		print(f"{self.name.capitalize()}: {round(self.height, 1)}cm, {self.daysold} days old")

	def grow(self, growth):
		self.height += growth

	def age(self, time):
		self.daysold += time

if __name__ == "__main__":
	days = 7
	growth = 0.8
	rose = Plant("Rose", 25, 30)
	h_0 = rose.height
	print("=== Garden Plant Growth ===")
	rose.show()
	for day in range (days):
		rose.grow(growth)
		rose.age(1)
		print(f"=== Day {day} ===")
		rose.show()
		print(f"Growth this week: 5.6cm")
