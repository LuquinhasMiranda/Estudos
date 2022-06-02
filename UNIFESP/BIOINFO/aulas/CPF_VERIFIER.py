CPF_RAW = input()


d1 = 0
for i in range(0,9):
    d1 += int(CPF_RAW[i]) * (10-i)

d1 = d1%11
if d1 < 2:
    d1 = 0
else:
    d1 = 11 - d1


d2 = 0
for i in range(0,9):
    d2 += int(CPF_RAW[i]) * (11-i)
d2 += d1 * 2

d2 = d2%11
if d2 < 2:
    d2 = 0
else:
    d2 = 11 - d2
    
    
if (str(d1)==CPF_RAW[9]) and (str(d2)==CPF_RAW[10]):
    print("VALIDO")
else:
    print("INVALIDO")