nVetores = int(input())
Xfinal = 0
Yfinal = 0
Zfinal = 0

for i in range(0, nVetores):
    x = int(input())
    y = int(input())
    z = int(input())
    
    Xfinal += x
    Yfinal += y
    Zfinal += z

    
if (Xfinal == 0) and (Yfinal == 0) and (Zfinal == 0):
    print("YES")
    
else:
    print("NO")
print(str(Xfinal) + "," + str(Yfinal) + "," + str(Zfinal))