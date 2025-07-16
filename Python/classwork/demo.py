"""
num = int(input("grir qanaky Studenti: "))
result = 0

def stugum(gnahatakan):
    if gnahatakan < 50:
      print("fail")
    elif gnahatakan < 101:
      print("pass")
    else:
      print("gnahatakany 0ic 100 mijakayqum")

for i in range(num):
    anun = input("Studenti anun: ")
    gnahatakan = int(input("Studenti gnahatakan: "))
    result += gnahatakan
    stugum(gnahatakan)
gumar = result/num
print(gumar)    
________________________________________________________


class Warke:

#Ctr
    def __init__(self, Id, name, age):
        self._Id = Id
        self._name = name
        self._age = age

#Str/gtr
    def setId(self, Id):
        self._Id = Id

    def getId(self):
        return self._Id
        
    def setName(self, name):
        self._name = name

    def getName(self):
        return self._name
                 
    def setAge(self, age):
        self._age = age

    def getAge(self):
        return self._age

class Employee(Warke):
    def __init__(self, Id, name, age, salary):
        super().__init__(Id, name, age)
        self._salary = salary
    
    def setSalary(self, salary):
        self._salary = salary

    def getSalary(self):
        return self._salary
   

em = Employee(888, "Karen", 24, 300000)
print(em.getSalary())


class Shape:
    def area(self):
        print("Unnown")

class Circle(Shape):
    def area(self):
        print("Circle area")

class Square(Shape):
    def area(self):
        print("Square area")

class Rectengle(Shape):
    def area(self):
        print("Rectengle area")


shape = [Shape(), Circle(), Rectengle()]
for Area in shape:
    Area.area()
"""

num1 = input("arajin argument: ")
def arr(num1):
    if type(num1) == str:
        print("str")
    elif num1 == int(num1):
        print("int")
    elif num1 == bool(num1):
        print("bool")
    elif num1 == float(num1):
        print("float")
    else:
        print("list,set,tuple")

