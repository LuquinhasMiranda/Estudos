from datetime import date, datetime
from iqoptionapi.stable_api import IQ_Option
from classes import Vela, Estrategia_c9

#### FUNCOES ####
def converter_para_velas(ativo):
    lista = []
    api_velas = api.get_candles(ativo, 60, 240, datetime.now().timestamp()-60)
    for api_vela in api_velas:
        vela = Vela(ativo, datetime.fromtimestamp(api_vela['from']).strftime('%H:%M'), api_vela['open'], api_vela['close'])
        lista += [vela]
    return lista

#### START ####
api = IQ_Option('Lukinhamgiannella@gmail.com', '4Wesome12')
api.connect()
if api.check_connect():
    print('\033[92mConectado!\n\033[0m')
else:
    print('\033[91mfalha de conexao\033[0m')
    exit()

lista_velas = converter_para_velas('EURUSD-OTC')
for vela in lista_velas:
    vela.printar()

Estrategia_c9(lista_velas).printar()