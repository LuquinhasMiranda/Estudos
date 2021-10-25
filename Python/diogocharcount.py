arquivo = open(input(),'r').read()
cache = ""
count = 0
texto = ""
for i in range(0, arquivo.__len__()+1):
    if i == arquivo.__len__():
        texto += cache + str(count)
    elif arquivo[i] == cache:
        count += 1
    else:
        if cache != "":
            texto += cache + str(count)
        cache = arquivo[i]
        count = 1
print(texto)