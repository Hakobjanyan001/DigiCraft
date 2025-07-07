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
