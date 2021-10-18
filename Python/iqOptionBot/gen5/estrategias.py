from classes import Estrategia

class Estrategia_c9(Estrategia):
    def __init__(self, lista_velas):
        Estrategia.__init__('C9')
        Hs = 0
        Ls = 0
        Ns = 0

        checkwin = 'X'
        
        #### ALINHAMENTO DE VELAS ####
        start = False
        for vela in lista_velas:
            if vela.minutagem != '00' and start == False:
                continue
            start = True
        #### COMECO DO CALCULO ####
        if vela.minutagem == '09': # CHAMA A COMPRA
            if Hs > Ls + Ns:
                pass
                # COMPRA HIGHER
            elif Ls > Hs + Ns:
                pass
                # COMPRA LOWER
            else:
                pass
                # HOLD
            Hs = 0
            Ls = 0
            Ns = 0

        if vela.direcao == 'H':
            Hs += 1
        elif vela.direcao == 'L':
            Ls += 1
        else:
            Ns += 1



