arquivo = open(input(), 'r')
matriz = arquivo.read().split('\n')
horizontal = False
for linha in matriz:
    if 'wally' in linha:
        print(f'{matriz.index(linha) + 1} {linha.find("wally") + 1} horizontal')
        horizontal = True
 
for i in range(len(matriz)):
    if horizontal:
       break
    for j in range(len(matriz[i])):
        if matriz[i][j] == 'w':
            if matriz[i+1][j] == 'a' and matriz[i+2][j] == 'l' and matriz[i+3][j] == 'l' and matriz[i+4][j] == 'y':
                print(i + 1, j + 1, 'vertical')
                horizontal = True
                break
arquivo.close()