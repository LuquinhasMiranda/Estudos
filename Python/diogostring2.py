n = int(input())
linhas = []
for i in range(0, n):
    linhas += [input()]
    
for linha in linhas:
    if linha.__len__() < 5:
        print(linha)
    else:
        count = -2
        for i in linha:
            count += 1
        print(linha[0] + str(count) + linha[linha.__len__()-1])