from datetime import datetime
from iqoptionapi.stable_api import IQ_Option
import estrategias

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

def direcao_vela(o, c):
    if o<c:
        return 'H'
    elif o==c:
        return 'N'
    else:
        return 'L'

api_velas = api.get_candles('EURGBP',60,240,datetime.now().timestamp()-60)
velas = []
for vela in api_velas:  
    velas += [[direcao_vela(vela['open'], vela['close']), datetime.fromtimestamp(vela['from']).strftime('%H:%M')]]
odds = estrategias.get_odds(velas) 

print(odds[0])
print(odds[1])
print(odds[2])
