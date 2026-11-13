#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height= height
        self._days = age

    def set_height(self, height: float) -> None:
        if (height < 0):
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
            return
        self._height = height
        print(f"Height updated: {height}cm")

    def set_age(self, age: int) -> None:
        if (age < 0):
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
            return
        self._days = age
        print(f"Age updated: {age}cm")

    def get_height(self) -> int:
            return (round(self._height, 1))
    
    def get_age(self) -> int:
            return (self._days)

    def show(self):
        print(f"{self._name.capitalize()}: {self.get_height()}cm, {self.get_age()} days old")

    def grow(self, len):
        self.height += len

    def age(self, time):
        self.days += time

if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose = Plant("rose", 25.0, 30)
    print("Plant created: ", end = "")
    rose.show()
    rose.set_height(25)
    rose.set_age(30)
    rose.set_height(-1)
    rose.set_age(-2)
    print("Current state: ", end = "")
    rose.show()
    

