N = int(input())
lista = []

for i in range(0, N):
    lista += [int(input())]
    
for num in range(0, N):
    for num2 in range(num, N):
        if num!=num2:
            if lista[num]==lista[num2]:
                print(True)
                exit()
print(False)