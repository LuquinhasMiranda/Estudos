n = int(input())

for i in range(n):
    s = input()

    stored = 0
    cnt = 0
        
    comeco = False
    for c in s:
        
        if comeco == False:    # 
            if c == '1':       # 
                comeco = True  # O PROGRAMA ESTAVA CONSIDERANDO QUE O PRIMEIRO CARACTER SERIA "1", DEVE-SE
            if c == '0':       # CONSIDERAR QUE DEVEMOS ACHAR O PRIMEIRO "1" IGNORANDO OS "0" INICIAIS
                continue       #
        
        if c == '1': # PARA COMPARACAO USA-SE "==" E PARA ATRIBUICAO USA-SE "=", NESTE CASO DEVERIA SER "=="
            stored += cnt
            cnt = 0
        else:
            cnt += 1

    print(stored)