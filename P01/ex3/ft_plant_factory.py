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

class Garden:
	def __init__(self)
		self

if __name__ == "__main__":
	plants = []
	plants += [Plant("rose", 25.0, 30)]
	plants += [Plant("oak", 200.0, 365)]
	plants += [Plant("cactus", 5.0, 90)]
	plants += [Plant("sunflower", 80.0, 45)]
	plants += [Plant("fern", 15.0, 1200)]
	print("=== Plant Factory Output ===")
	for plant in plants:
		print("Created")
		plant.show()