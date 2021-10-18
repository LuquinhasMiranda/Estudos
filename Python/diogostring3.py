campo = input()
count = 0
for i in range(0, campo.__len__()):
    if i == campo.__len__()-1:
        if campo[i] != '.':
            count += 1
            break
    if i != 0:
        if campo[i-1] != '.':
            continue
    if campo[i] == '.':
        continue
    for j in range(i, campo.__len__()):
        if campo[j] == '.':
            count += 1
            break
print(count)
    