N = int(input())
voltas = []

for v in range(0, N):
    voltas += [int(input())]
    
minimo = 99999
for v in range(0, N):
    if voltas[v] < minimo:
        minimo = v

for v in range(0, N):
    print(minimo)
    print(voltas[v]-minimo)