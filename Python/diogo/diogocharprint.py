arquivo = open(input(),'r').read()
texto = ''
num = ''
char = ''
for i in arquivo:
    if i == '\n':
        texto += char*int(num)
        char = ''
        texto += '\n'
    elif i in ['0','1','2','3','4','5','6','7','8','9']:
        num += i
    else:
        if char != '':
            texto += char
            char = i
        elif num != '':
            texto += char*int(num)
        char = i
        num = ''
texto += char*int(num)
char = ''
print(texto)