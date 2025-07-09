"""
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

"""

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


#_____________________________________________________________________________
