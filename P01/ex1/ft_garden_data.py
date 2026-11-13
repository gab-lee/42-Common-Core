#!/usr/bin/env python3

class Plant:
	def __init__(self, name, height, age):
		self.name = name
		self.height= height
		self.age = age

	def show(self):
		print(f"{self.name}.capitalize(): {self.height}cm, {self.age} days old")

class Garden:
    def __init__(self):
        self.plants = []

    def add(self, plant):
        self.plants.append(plant)

    def show(self):
        for plant in self.plants:
                plant.show()
                
if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    g = Garden()
    g.add(Plant("rose", 25.0, 30))
    g.add(Plant("sunflower", 80, 45))
    g.add(Plant("cactus", 15, 120))
    g.show()
	
