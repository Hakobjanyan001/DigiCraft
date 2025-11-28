"""
class Animal:
    def sound(self):
        print("Animal Sound")

class Dog (Animal):
    def sound(self):
        print("Dog Sound")

class Cat (Animal):
    def sound(self):
        print("Cat Sound")

animals = [ Animal(), Dog() ]
    for animal in animals:
        animal.sound()
"""


class Animal:
    def sound(self):
        print("Animal Sound")

class Dog(Animal):
    def sound(self):
        print("Dog Sound")

class Cat(Animal):
    def sound(self):
        print("Cat Sound")

def makesound(animal: Animal):
    animal.sound()
    makesound(animal)
    makesound(Dog())
    makesound(Cat())
