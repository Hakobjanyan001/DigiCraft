# comment -> for run python3 demo,py
print("result`",5, sep="", end="")
print(" new", " \" ", )


# sep="" -> argumentneri heravorutyuny kam inch dnen ""-i mej da klini argumentneri mejtexum
# end="" -> hajord tox vorpesi chancni mius printy ayl sharunaki

num1 = input("greq argument: ")
print(num1)


# if _______________________________________________________________________
age = int(input("Age: "))
if age > 18:
    print("18+")
elif age < 10:
    print("18-")
else:
    print("Else")

# loop_____________________________________________________________________
for i in range(10):
    print(i)

for i in "Hello":
    print(i)


x = 0
while x < 10:
    print("x:", x)
    x += 1

# funkcia _______________________________________________________

def sayHello():
    print("Hello")

sayHello()

#___________________________________________

def sayHello(name):
    print("Hello", name)

sayHello("Karen")

#_______________________________________
def sayHello(name):
    print(f"Hello {name}")

sayHello("Karen")

#____________________________________
def sayHello(name="Karen"):
    print("Hello", name)

sayHello()



# Data Structura_____________________________________________________________
# 4 Himnakan ev  Global  kanteyner______________________________________________



# 1 List vory hamapatasxanum e C++ akan Vektorin
arr = [ "1", "2", "3", 1, 2, 3, 7.5, 4.3, True]
arr.append("4") # verjic kavelacni inch argument uzenq
arr[2] = False
print(arr[8])
print(len(arr)) # ktpi kanteyneri argumentneri qanaky
for x in arr:
    print(x)
print(4 in arr) # kanteyneryi mej 4 tivy kmanga ev ete gtni True kta ete chgtni False ktpi



# 2 Tuple vory nuyn C++i pearnern en
mytuple = [ ("Karen", 24) , ("X", 11) ]
print(mytuple[0]) # sa ktpi mytuple-i meji ("Karen", 24)
print(mytuple[1]) # sa ktpi mytuple-i meji ("X", 11)
for x,y in mytuple:
    print(x)
    print(y)


#____________________________________________________________
# unpucing                                                  |
cords = (0,100)                                            #|
print(cords[1]) # sa ktpi cords-i meji 100y                 | 
print(cords[0]) # sa ktpi cords-i meji 0                    |
                                                           #|
x,y = cords                                                #|
print(x) #sa ktpi cords[0]->0                               |
print(y) #sa ktpi cords[1]->100                             |
#_____________________________________________________________



# 3 Set ________________________________________________________
arr = {1, 2, 6}  # Sety chi toxnum krknvi kanenyeri mej 
arr.add(2) # sa petqa avelacni 2-tivy arr-i mej
print(arr) # qani vor Set-ova mi hat 2 ktpi 

x = {1, 2, 3}
y = {3, 4, 5}
print( x | y) # miavoruma x ev y Setery stacvuma {1, 2, 3, 4, 5}
print( x & y) # hatuma x ev y Setery aysinqn mnuma {3}
print( x - y) # x Setic hanuma y Sety mnuma {4, 5}



# 4 MAP___________________________________________________________________
person = {"name" : "Karen", "age" : 24} # key->"name", value->"Karen"
print(person["name"]) # sa ktpi Karen
print(person["age"]) # sa ktpi 24
person["city"] = "Vanadzor"
print(person["city"])

for key, value in person.items(): # items() funkcian key + value anum u miasin vekalum vor ashxati aranc key chi kara value tpi
    print(key)
    print(value)


# Class ________________________________________________

class Person:
    def __init__(self, name, age):  # self -> C++ thish-> (__init__ Python constructor)
        self.name = name
        self.age = age
    def sayHello(self)
        print(f"Hello {self.name}")

ps = Person("Karen", 21)
ps.sayHello()



#inheritance jarangutyun ____________________________________________

class Student(Person):
    def __init__(self, name, age, grade):
        super().__init__(name, age)
        self.grade = grade
    def sayHello(self)
        print(f"hello {self._age}")

st = Student("Karen", 24, 300000)
st.sayHallo()




#Run time Polimorfizm _________________________________________________
class Animal:
    def sound(self):
        print("Animal Sound")

class Dog(Animal):
    def sound(self):
        print("Dog Sound")

animals = [Animal(), Dog()]
for animal in animals:
    animal.sound()

#dinamik polimorfizm ______________________________________________

class Animal:
    def sound(self):
        print("Animal Sound")

class Dog(Animal):
    def sound(self):
        print("Dog Sound")

class Cat(Animal):
    def sound(self):
        print("Cat Sound")

def makeSound(animal: Animal): # (animal: Animal) asuma vor animaly Anymel typna u ov jarangela Animalic nra hamar ogtagorci makeSound funkcian, animal-ov cucenq talis vor sax  Animal tipi obyektner ti stana typery stugi
    animal.sound()

#def makeSound(animal): #angrafget greladezev
#    animal.sound()

makeSound(Animal())
makeSound(Dog())
makeSound(Cat())


#built-in Polimorfizm _________________________________________________________
print(len("A" + "B")) 
print(len("8" + str(10)))


#GLOBAL________________________________________________________________________
x = 100

def change():
    global x # sa nuyn verevi x-na poxancum u 2 print(x)->nel ktpi 200
    x = 200
    print(x)

change()
print(x)


#MATCH C++-i switch() case: ->e ___________________________________________________
day = 1
month = 3
match day:
    case 1 | 11 | 111 if month == 3: #kashxati ete (1 kam 11 kam 111) ev amisne 3 a
        print("Monday")
    case 2:
        print("Ereqsh")
    case 3:
        print("Choreq")
    case 4:
        print("Hingsh")
    case _:
        print("Urbat")


#TYPE-> stuguma popoxakany ira tipi het ____________________________________
x = 100
isInt = isinstance(x, int)
print(isInt)

if isInt:
    print("integer")


#LAMBDA-> C++ i lambda ____________________________________________________
def f(): # funkcia vory generacnume mek ayl funkcia
    return lambda x: x * x

res = f()
print(res(10)) # -> ktpi 100

#______________________________
l = lambda a, b: a + b # -> sa sarquma lambda funkcia anuny -> "l" chi ogtagorcvum
print(l(10,20))

#_____________________________
def f(n): #-> f(n) = f(2) kam f(3)
    return lambda x: x * n #-> x = doubler(10) kam tripler(10)
doubler = f(2)  # 2 * 10
tripler = f(3)  # 3 * 10
print(doubler(10))
print(tripler(10))

