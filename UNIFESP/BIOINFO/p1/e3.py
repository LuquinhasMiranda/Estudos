def fatorial(num):
    if num == 0:
        return 1
    aux = num
    while aux > 1:
        aux -= 1
        num = num * aux
    return num

def isdivby4(num):
    if num%4 == 0:
        return True
    else:
        return False

def Euler(num):
    total = 0
    for i in range(30):
        print(i)
        total += (num**i)/fatorial(num)
    return total

print(Euler(4))