a = []
count = 0

while True:
    i = int(input())
    if i < 0:
        break
    else:
        a += [i]
        count += 1
        
if count%2==0:
    print((a[int(count/2)-1]+a[int(count/2)])/2)
else:
    print(a[int((count/2)-.5)])
