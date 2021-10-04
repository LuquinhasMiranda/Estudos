NC = int(input())
NF = int(input())

for N in range(NC, NF+1):
    divisores = 0
    for I in range(2, N):
        if N%I == 0:
            divisores += 1
    if divisores == 0:
        print(N)