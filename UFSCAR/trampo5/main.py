dic = {}

for _ in range(4): 
    name = input()
    phone = input()
    price = int(input())
    if phone not in dic:  
        dic[phone] = [price]     
    else:                        
        dic[phone].append(price) 
name = ""
price = 999999999
c = -9999
for phone in dic.keys():
    curp = min(dic[phone])
    curc = len(dic[phone])
    if curc > c:   
        c = curc
        price = curp
        name = phone
    elif curc == c and curp < price: 
        c = curc
        price = curp
        name = phone
print(name)