from datetime import datetime   

#### CALCULO DE ODDS ####
def get_odds(api_velas):
    # RETORNA ODDS DAS ESTRATEGIAS EM 1 ATIVO
    velas = []
    for vela in api_velas:  

        # CALCULA DIRECAO DA VELA
        direcao_vela = ''
        if vela['open']<vela['close']:
            direcao_vela ='H'
        elif vela['open']==vela['close']:
            direcao_vela ='N'
        else:
            direcao_vela = 'L'
        velas += [[direcao_vela, datetime.fromtimestamp(vela['from']).strftime('%H:%M')]]
    
    # LISTA AS ODDS DAS ESTRATEGIAS
    lista =  [odds_c9(velas)]
    lista += [odds_tabelado(velas)]
    lista += [odds_milhao(velas)]
    
    return lista

def print_odds(odds):
    # IMPRIME ODDS DE 1 ATIVO
    for odd in odds:
        # NOME
        nome = '\033[95m' + odd[0] + ': \033[0m'

        # PORCENTAGEM DE ACERTO DA ESTRATEGIA
        porcentagem = ''
        if odd[2] > .9:
            porcentagem += '\033[96m'
        elif odd[2] > .8:
            porcentagem += '\033[92m'
        elif odd[2] > .7:
            porcentagem += '\033[93m'
        else:
            porcentagem += '\033[91m'
        porcentagem += str(round(odd[2]*100,1)) + '\033[95m% '

        # NEXT TARGET
        target = ' Target:'
        if odd[8] == 'H':
            target += '\033[92m'
        elif odd[8] == 'L':
            target += '\033[91m'
        target += str(odd[8])
        target += '\033[0m'

        print(nome + porcentagem + target)
    print('')

def get_odds_from_ativos(lista_api_velas):
    lista_odds_ativos = []
    for api_velas in lista_api_velas:
        odds = get_odds(api_velas)
        lista_odds_ativos += odds
        print_odds(odds)

#### CALCULO DE TARGET ####
def aplicar_estrategias_nos_ativos(lista_api_velas):
    lista_odds_ativos = get_odds_from_ativos(lista_api_velas)
    for lista_odds in lista_odds_ativos:# PARA CADA ATIVO NA LISTA
        H = 0
        L = 0
        TOTAL = 0
        for odds in lista_odds:# PARA CADA ESTRATEGIA NO ATIVO
            if odds[2] > .85:
                if odds[8] == 'H':
                    H += odds[2]
                    TOTAL += 1
                elif odds[8] == 'L':
                    L += odds[2]
                    TOTAL += 1
        if H/TOTAL > .85:
            print('ENTRAR NO H')
        elif L/TOTAL > .85:
            print('ENTRAR NO L')
        


#### ESTRATEGIAS ####
def odds_c9(velas): 
    start = False
    Hs = 0
    Ls = 0
    Ns = 0
    TargetDirection = 'X'
    TargetPosition = -1

    gale0 = 0
    gale1 = 0
    gale2 = 0
    loss = 0
    holds = 0

    for vela in velas:
        if (int(str(vela[1][3])+str(vela[1][4]))%10 != 0) and (start == False):
            continue
        start = True

        if TargetPosition != -1:
            # CHECK GALE 0
            if TargetPosition == 0:
                if vela[0] == TargetDirection:
                    gale0 += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Gale0 em ' + str(vela[1]))
                else:
                    TargetPosition = 1
        
            # CHECK GALE 1
            elif TargetPosition == 1:
                if vela[0] == TargetDirection:
                    gale1 += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Gale1 em ' + str(vela[1]))
                else:
                    TargetPosition = 2

            # CHECK GALE 2
            elif TargetPosition == 2:     
                if vela[0] == TargetDirection:
                    gale2 += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Gale2 em ' + str(vela[1]))
                else:
                    loss += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Erro em ' + str(vela[1]))

        # CONTA VELAS
        if vela[0] == 'H':
            Hs += 1
        elif vela[0] == 'L':
            Ls += 1
        elif vela[0] == 'N':
            Ns += 1
        
        if Hs+Ls+Ns == 10:
            if Ns>0:
                TargetDirection = 'X'
                TargetPosition = -1
            else:
                if Hs>Ls:
                    TargetDirection = 'H'
                    TargetPosition = 0
                if Hs<Ls:
                    TargetDirection = 'L'
                    TargetPosition = 0
                if Hs==Ls:
                    TargetDirection = 'X'
                    TargetPosition = -1
            Hs = 0
            Ls = 0
            Ns = 0
            #print(TargetDirection)

    return calc_odds("C9", gale0, gale1, gale2, loss, holds, TargetDirection)
    
def odds_tabelado(velas):
    TargetDirection = 'X'
    TargetPosition = -1

    gale0 = 0
    gale1 = 0
    gale2 = 0
    erros = 0
    holds = 0
    
    tabelado_lista = []

    start = False
    for vela in velas:
        if (int(vela[1][4])%5 != 0) and (start == False):
            continue
        start = True

        if tabelado_lista.__len__() == 4 and TargetDirection == 'X':
            if tabelado_lista == ['H','H','L','L']:
                TargetPosition = 0
                TargetDirection = 'L'    
            elif tabelado_lista == ['L','H','L','H']:
                TargetPosition = 0
                TargetDirection = 'L'
            elif tabelado_lista == ['L','H','H','L']:
                TargetPosition = 0
                TargetDirection = 'H'
            elif tabelado_lista == ['H','H','H','L']:
                TargetPosition = 0
                TargetDirection = 'L'
            else:
                TargetPosition = -1
                TargetDirection = 'X'
            tabelado_lista = [tabelado_lista[1],tabelado_lista[2],tabelado_lista[3],vela[0]]
        else:
            tabelado_lista += [vela[0]]

        # CHECK GALE 0
        if TargetPosition == 0:
            if vela[0] == TargetDirection:
                gale0 += 1
                TargetPosition = -1
                TargetDirection = 'X'
                tabelado_lista = []
            else:
                TargetPosition = 1
        
        # CHECK GALE 1
        elif TargetPosition == 1:
            if vela[0] == TargetDirection:
                gale1 += 1
                TargetPosition = -1
                TargetDirection = 'X'
                tabelado_lista = []
            else:
                TargetPosition = 2

        # CHECK GALE 2
        elif TargetPosition == 2:     
            if vela[0] == TargetDirection:
                gale2 += 1
                TargetPosition = -1
                TargetDirection = 'X'
                tabelado_lista = []
            else:
                erros += 1
                TargetPosition = -1
                TargetDirection = 'X'
                tabelado_lista = []

    return calc_odds("Tabelado", gale0, gale1, gale2, erros, holds, TargetDirection)

def odds_milhao(velas):
    start = False
    Hs = 0
    Ls = 0
    Ns = 0
    TargetDirection = 'X'
    TargetPosition = -1

    gale0 = 0
    gale1 = 0
    gale2 = 0
    loss = 0
    holds = 0

    for vela in velas:
        if (int(str(vela[1][4]))%5 != 0) and (start == False):
            continue
        start = True

        if TargetPosition != -1:
            # CHECK GALE 0
            if TargetPosition == 0:
                if vela[0] == TargetDirection:
                    gale0 += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Gale0 em ' + str(vela[1]))
                else:
                    TargetPosition = 1
        
            # CHECK GALE 1
            elif TargetPosition == 1:
                if vela[0] == TargetDirection:
                    gale1 += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Gale1 em ' + str(vela[1]))
                else:
                    TargetPosition = 2

            # CHECK GALE 2
            elif TargetPosition == 2:     
                if vela[0] == TargetDirection:
                    gale2 += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Gale2 em ' + str(vela[1]))
                else:
                    loss += 1
                    TargetPosition = -1
                    TargetDirection = 'X'
                    #print('Erro em ' + str(vela[1]))

        # CONTA VELAS
        if vela[0] == 'H':
            Hs += 1
        elif vela[0] == 'L':
            Ls += 1
        elif vela[0] == 'N':
            Ns += 1
        
        if Hs+Ls+Ns == 5:
            if Ns>0:
                TargetDirection = 'X'
                TargetPosition = -1
            else:
                if Hs>Ls:
                    TargetDirection = 'H'
                    TargetPosition = 0
                if Hs<Ls:
                    TargetDirection = 'L'
                    TargetPosition = 0
                if Hs==Ls:
                    TargetDirection = 'X'
                    TargetPosition = -1
            Hs = 0
            Ls = 0
            Ns = 0
            #print(TargetDirection)

    return calc_odds("Milhao", gale0, gale1, gale2, loss, holds, TargetDirection)

def calc_odds(string, gale0, gale1, gale2, loss, holds, target):
    # CALCULA O RETORNO DAS ESTRATEGIAS ACIMA
    acertos = gale0+gale1+gale2
    entradas = acertos + loss
    total = entradas + holds

    if entradas != 0:
        # %ACERTO
        if acertos == 0:
            acerto_odd = 0
        else:
            acerto_odd = acertos/entradas
        # %GALE0
        if gale0 == 0:
            gale0_odd = 0
        else:
            gale0_odd = gale0/entradas
        # %GALE1
        if gale1 == 0:
            gale1_odd = 0
        else:
            gale1_odd = gale1/entradas
        # %GALE2
        if gale2 == 0:
            gale2_odd = 0
        else:
            gale2_odd = gale2/entradas
        # %LOSS
        if loss == 0:
            loss_odd = 0
        else:
            loss_odd = loss/entradas
        # %HOLD
        if holds == 0:
            hold_odd = 0
        else:
            hold_odd = holds/(entradas+holds)
    else:
        acerto_odd = 0
        gale0_odd = 0
        gale1_odd = 0
        gale2_odd = 0
        erros_odd = 0
        hold_odd = 1

    return string, total, acerto_odd, gale0_odd, gale1_odd, gale2_odd, loss_odd, hold_odd, target