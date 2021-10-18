from datetime import date, datetime
from iqoptionapi.stable_api import IQ_Option
import estrategias
import time

#### VARIAVEIS ####
TOLERANCIA = .8

#### FUNCOES PRE COMPRA ####
def get_odds_ativo(ativo):
    # RETORNA ODDS DAS ESTRATEGIAS EM 1 ATIVO
    api_velas = api.get_candles(ativo, 60, 240, datetime.now().timestamp()-60)

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
    lista =  [estrategias.odds_c9(velas)]
    lista += [estrategias.odds_tabelado(velas)]
    lista += [estrategias.odds_milhao(velas)]
    
    return lista

def printar_odds_ativo(ativo, odds_ativo):
    print(' --= \033[95m' + str(ativo) + '\033[0m =--')
    for odd in odds_ativo:
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

def aplicar_ativo(ativo):
    odds_ativo = get_odds_ativo(ativo)
    printar_odds_ativo(ativo, odds_ativo)

    recibo = '\033[95m[' + ativo + ']\033[93m COMPRA EFETUADA: ' 

    h = 0
    l = 0
    count = 0
    for odd in odds_ativo:
        if odd[8] == 'H' and odd[2] > TOLERANCIA:
            h += odd[2]
            count += 1
        if odd[8] == 'L' and odd[2] > TOLERANCIA:
            l += odd[2]
            count += 1

    if count != 0:
        if h != 0:
            if h/count > TOLERANCIA:
                compra = api.buy(100,ativo,'call',1)
                recibo += '\033[92mBUY \033[0m'
                recibo += str(datetime.now())
                if compra[0]:
                    print(recibo)
                    
    
        if l != 0:
            if l/count > TOLERANCIA:
                compra = api.buy(100,ativo,'put',1)
                recibo += '\033[91mSELL \033[0m' 
                recibo += str(datetime.now())
                if compra[0]:
                    print(recibo)

#### FUNCOES POS COMPRA ####
def aplicar_compras():
    pass

#### LOGIN ####
api = IQ_Option('Lukinhamgiannella@gmail.com', '4Wesome12')
api.connect()

if api.check_connect():
    print('\033[92mConectado!\n\033[0m')
else:
    print('\033[91mfalha de conexao\033[0m')
    exit()

#### LOOP ####
def loop(tempo):
    print(tempo)
    
    aplicar_ativo('EURGBP-OTC')

    aplicar_compras()
    api.check_win()

cTempo = ''
while True:
    tempo = datetime.fromtimestamp(datetime.now().timestamp()).strftime('%H:%M')
    if tempo != cTempo:
        loop(tempo)
        cTempo = tempo
    else:
        time.sleep(1)