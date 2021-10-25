arquivo = open(input(),'r').read()
linhas = 1
princesa = 0
cavaleiro = 0
dragao = 0

for i in range(0, arquivo.__len__()):
    if (arquivo[i] == '\n'):
        linhas += 1
    if arquivo[i] == 'P':
        princesa = linhas/2
    if arquivo[i] == 'C':
        cavaleiro = linhas/2
    if arquivo[i] == 'D':
        dragao = linhas/2
princesa = int(((linhas+1)/2) - princesa)
cavaleiro = int(((linhas+1)/2) - cavaleiro)
dragao = int(((linhas+1)/2) - dragao)

print("Princesa no andar " + str(princesa))
print("Cavaleiro no andar " + str(cavaleiro))
print("Dragão no andar " + str(dragao))

while cavaleiro <= princesa or cavaleiro <= princesa:
    cavaleiro += 1
    dragao += 2
    
if cavaleiro >= dragao:
    print("Quero ver descerem u.u")
else:
    print("Mais um pro lanche!")