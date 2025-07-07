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
