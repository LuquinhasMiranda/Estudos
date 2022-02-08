arquivo = open(input(),'r').read()
elemento = ""
for i in range(0, arquivo.__len__()):
    if arquivo[i] == ',':
        elemento = ""
        continue
    if arquivo[i] == '\n' or arquivo[i] == '\r':
        print(elemento)
    elemento += arquivo[i]