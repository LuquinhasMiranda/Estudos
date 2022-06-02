/* 
    Lucas Miranda Giannella 
    RA: 159324
    Turma: I
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char carta;
    struct no *prox;
} no;

no *CriarListaCircular() {
    no *p1 = (no *) malloc(sizeof(no));

    p1->prox = NULL;

    return p1;
}

int CartaParaInt(char carta) {
    switch (carta)
    {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'J':
        return 10;
    case 'Q':
        return 11;
    case 'K':
        return 12;
    default:
        return 0;
    }
}

void Adicionar(no *lista, char nova_carta) {
    no *p1 = lista->prox;
    no *p2 = lista;
    no *p3 = (no*) malloc(sizeof(no));
    
    p3->carta = nova_carta;

    if (p1 == NULL) {
        p2->prox = p3;
        p3->prox = p3;
    }

    else if (p1 == p1->prox) {
        p3->prox = p1;
        p1->prox = p3;
        if (CartaParaInt(p3->carta) <= CartaParaInt(p1->carta)) p2->prox = p1;
        else p2->prox = p3;
    }

    else {
        p2 = p1;
        p1 = p1->prox;
        
        while(p2 != p1 && CartaParaInt(p3->carta) <= CartaParaInt(p1->carta)) p1 = p1->prox;

        p2 = p1;
        p1 = p1->prox;
        p3->prox = p1;
        p2->prox = p3;
    }
    
}

void Limpar(no *lista) {
    no *p1 = lista->prox;
    no *p2;

    while(p1 != NULL) {
        p2 = p1;
        p1 = p1->prox;
        free(p2);
    }

    free(lista);
}

void printar(no *lista) {
    no *p1 = lista->prox;
    no *p2;
    if (p1 == NULL) return;
    
    p2 = p1;
    p1 = p1->prox;
        
    while(p2 != p1) {
        printf("Carta: %c\n", p1->carta);
        p1 = p1->prox;
    }
}


int main() {
    no* ordem = CriarListaCircular();
    Adicionar(ordem, '2');
    Adicionar(ordem, '3');
    Adicionar(ordem, '4');
    printar(ordem);
    Limpar(ordem);
}