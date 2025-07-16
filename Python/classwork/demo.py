"""
num1 = int(input("greq arajin argument: "))
num2 = int(input("greq erkrord argument: "))
operator = str(input("greq operator: "))

def calculator(num1, num2, argument):
    if operator == "+":
        return(num1+num2) 
    elif operator == "-":
        return(num1 - num2) 
    elif operator == "/":
        return(num1 / num2) 
    elif argument == "*":
        return(num1 * num2) 
    else:
        print("Unnown")

calculator(num1, num2, operator)



import random
goldenNum = random.randint(1,10)
while True:
    num1 = int(input("greq tiv: "))
    if goldenNum != num1:
        print("noric porceq")
    else:
        print("duq gtaq mtapahvac tivy")
        break


List = []

while True:
    print("For Add enther 1")
    print("For View enther 2")
    print("For Exit enther 3")
    aa = str(input("Enther Yor answer: "))
    if aa == "1":
        task = str(input("Enther your tasky: "))
        List.append(task)
    elif aa == "2":
        print(List)
    elif aa == "3":
        break
    else:
        print("unnown")

"""

        
List = []

while True:
    print("For Add enther 1")
    print("For View enther 2")
    print("For Search enther 3")
    print("For Delete enther 4")
    print("For Update enther 5")
    print("For Exit enther 6")
    aa = str(input("Enther Yor answer: "))
    if aa == "1":
        name = str(input("Enther name: ")), str(input("Enther phone number: "))
        List.append(name)
    elif aa == "2":
        print(List)
    elif aa == "3":
        for x,y in List:
            name1 = str(input("enher name: "))
            if x == name1:
                print(x, y)
    elif aa == "4":
        delet = str(input("write your name for delete: "))
        for x,y in list:
            x == delet
            List.remove(x,y)
    elif aa == "6":
        break
    else:
        print("unnown")
