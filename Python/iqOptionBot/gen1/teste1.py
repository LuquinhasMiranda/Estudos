from datetime import date, datetime
from iqoptionapi.stable_api import IQ_Option

api = IQ_Option('Lukinhamgiannella@gmail.com', '4Wesome12')
api.connect()

if api.check_connect():
    print('conectado\n')
else:
    print('falha de conexao')
    exit()

#compra = api.buy(10000,'EURUSD','put',1)
#print(compra)

def direcao_vela(o, c):
    if o<c:
        print('\033[92mO\033[0m')
    elif o==c:
        print('\033[96mO\033[0m')
    else:
        print('\033[91mO\033[0m')

velas = api.get_candles('EURGBP',60,10,datetime.now().timestamp()-60)
for vela in velas:
    direcao_vela(vela['open'], vela['close'])
    print(datetime.fromtimestamp(vela['from']).strftime('%Y-%m-%d %H-%M-%S'))
    print(datetime.fromtimestamp(vela['to']).strftime('%Y-%m-%d %H-%M-%S'))
