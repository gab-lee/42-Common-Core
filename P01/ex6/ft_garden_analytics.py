#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self._name = name
        self._height= height
        self._days = age

    @staticmethod
    def isOlderOneYear (age: int) -> bool:
            if (age > 365):
                return (True)
            return (False)
    
    @classmethod
    def createUnknownPlant(cls):
        return cls(name="unknown plant", height = 0, age = 0)
    
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

    def get_name(self) -> str:
                return (self._name)
    
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

class Flower(Plant):
    def __init__(self, name, height_cm, age_days, color):
        super().__init__(name, height_cm, age_days)
        self._color = color
        self._bloom = 0
    def bloom(self) -> None:
        self._bloom = 1
        print(f"[asking the {self.get_name()} to bloom]")
    def show(self) -> None:
        super().show()
        print(f" Color: {self._color}")
        if (self._bloom == 1):
            print(f" {self.get_name()} is blooming beautifully!")
        else:
            print(f" {self.get_name()} has not bloomed yet")

class Seed(Flower):
     def __init__(self, name, height_cm, age_days, color):
             super().__init__(name, height_cm, age_days)
if __name__ == "__main__":
    pass