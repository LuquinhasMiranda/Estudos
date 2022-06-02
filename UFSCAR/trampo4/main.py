n = int(input()) 

for i in range(n):
    s = str(int(input())) 

    stored = 0
    cnt = 0
    
    for c in s:
        if c == '1':
            stored += cnt
            cnt = 0
        else:
            cnt += 1

    print(stored)