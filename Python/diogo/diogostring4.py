frase = input()
count = 0
for i in range(0, int(frase.__len__())):
    if frase[i] == frase[frase.__len__()-1-i]:
        count += 1
print(count)
if count >= frase.__len__()-2:
    print('SIM')

elif count >= frase.__len__()-3:
    print('SIM') 
    
else:
    print('NAO')
