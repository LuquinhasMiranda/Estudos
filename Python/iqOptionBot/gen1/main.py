from datetime import datetime
from iqoptionapi.stable_api import IQ_Option
import estrategias

### FUNCOES NECESSARIAS PARA CALCULOS NA MAIN.PY ###
def direcao_vela(o, c):
    if o<c:
        return 'H'
    elif o==c:
        return 'N'
    else:
        return 'L'

def scan_ativo( ativo, segundosvela, nvelas):
    api_velas = api.get_candles(ativo, segundosvela, nvelas, datetime.now().timestamp()-60)
    velas = []
    for vela in api_velas:  
        velas += [[direcao_vela(vela['open'], vela['close']), datetime.fromtimestamp(vela['from']).strftime('%H:%M')]]
    print('--\033[95m ' + ativo + ' \033[0m--')
    lista = estrategias.get_odds(velas)
    estrategias.print_odds(lista)
    return lista

print('\nFARM DE DINHEIRO AUTOMATICO')
print('\nConectando...')

api = IQ_Option('Lukinhamgiannella@gmail.com', '4Wesome12')
api.connect()

if api.check_connect():
    print('Conectado!\n')
else:
    print('falha de conexao')
    exit()

#compra = api.buy(10000,'EURUSD','put',1)
#print(compra)

calcular_lista =  [scan_ativo('EURGBP', 60, 240)]
calcular_lista += [scan_ativo('AUDUSD', 60, 240)]
calcular_lista += [scan_ativo('EURUSD', 60, 240)]
calcular_lista += [scan_ativo('EURNZD', 60, 240)]
calcular_lista += [scan_ativo('EURGBP', 60, 240)]

#print(calcular_lista)