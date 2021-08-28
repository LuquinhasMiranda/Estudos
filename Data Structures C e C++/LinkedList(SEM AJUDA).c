#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *next;
};

int main () {
    struct no no1;
    no1.numero = 1;
    struct no no2;
    no2.numero = 2;
    no1.next = &no2;
    struct no no3;
    no3.numero = 3;
    no2.next = &no3;
    struct no no4;
    no4.numero = 4;
    no3.next = &no4;
    no4.next = NULL;

    struct no *ponteiro = &no1;
    int stop = 0;
    while (1) {
        printf(" %i", ponteiro->numero);
        if (ponteiro->next == NULL) break;
        ponteiro = ponteiro->next;
    }
}
