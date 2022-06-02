from datetime import datetime
from iqoptionapi.stable_api import IQ_Option
import estrategias

### FUNCOES NECESSARIAS PARA CALCULOS NA MAIN.PY ###


####################################################

print('\nFARM DE DINHEIRO AUTOMATICO')
print('\nConectando...')

api = IQ_Option('Lukinhamgiannella@gmail.com', '4Wesome12')
api.connect()

if api.check_connect():
    print('\033[92mConectado!\n\033[0m')
else:
    print('\033[91mfalha de conexao\033[0m')
    exit()

#compra = api.buy(10000,'EURUSD','put',1)
#print(compra)

lista_api_velas =  [api.get_candles('EURGBP', 60, 240, datetime.now().timestamp()-60)]
lista_api_velas += [api.get_candles('EURGBP', 60, 240, datetime.now().timestamp()-60)]
lista_api_velas += [api.get_candles('EURGBP', 60, 240, datetime.now().timestamp()-60)]
lista_api_velas += [api.get_candles('EURGBP', 60, 240, datetime.now().timestamp()-60)]
lista_api_velas += [api.get_candles('EURGBP', 60, 240, datetime.now().timestamp()-60)]

estrategias.aplicar_estrategias_nos_ativos(lista_api_velas)