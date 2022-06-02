n = int(input()) # int() para converter o input string para inteiro
a = [] 
for x in input().split():
    a.append(int(x))

cnt = {}
mis = {}

for i in range(n):
    mis[i+1] = i+1 # i+1

dup = -1

for x in a:
    if x not in cnt: #not
        cnt[x] = 0

    cnt[x] += 1

    if cnt[x] == 2: # para comparaçoes usamos "=="
        dup = x
    else:
        print("---", x)
        mis.pop(x)
        print("-", mis)


print(dup, list(mis.values())[0])