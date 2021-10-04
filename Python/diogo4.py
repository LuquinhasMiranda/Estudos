nVoltas = int(input())
voltas = []

for i in range(0, nVoltas):
    voltas += [int(input())]

MAX = 0
for i in range(0, nVoltas):
    mMAX = 0
    for j in range(i, nVoltas):
        if voltas[i] == voltas[j]:
            mMAX += 1
        else:
            break
    if mMAX > MAX:
        MAX = mMAX
print(MAX)