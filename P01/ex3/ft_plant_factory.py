#!/usr/bin/env python3

class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height= height
        self.days = age

    def show(self):
        print(f"{self.name.capitalize()}: {round(self.height, 1)}cm, {self.days} days old")

    def grow(self, len):
        self.height += len

    def age(self, time):
        self.days += time

class Garden:
    def __init__(self):
        self.plants = []

    def add(self, plant):
        self.plants.append(plant)

    def show(self):
        for plant in self.plants:
                plant.show()

if __name__ == "__main__":
    g = Garden()
    g.add(Plant("rose", 25.0, 30))
    g.add(Plant("oak", 200.0, 365))
    g.add(Plant("cactus", 5.0, 90))
    g.add(Plant("sunflower", 80.0, 45))
    g.add(Plant("fern", 15.0, 1200))
    print("=== Plant Factory Output ===")
    g.show()