#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int data;
    struct no *prox;
} no;

no *CriarLista() {
    no *lista = malloc(sizeof(no));
    lista->prox = NULL;
    return lista;
}

void Adicionar(no *lista, int num) {
    no *novo = (no*) malloc(sizeof(no));
    no *p;

    novo->data = num;
    novo->prox = NULL;

    for (p = lista; p->prox != NULL; p = p->prox);

    p->prox = novo;
}

void Remover(no *lista) {
    if (lista->prox == NULL) return;
    no *p1 = lista->prox;
    no *p2 = p1->prox;
    lista->prox = p2;
    free(p1);
}

void Limpar(no *lista) {
    while (lista->prox != NULL) Remover(lista);
    free(lista);
}

int CalcularSaida(no *n, no *m) {
    no *a = CriarLista();

    no *clientes = m->prox,
       *atendentes = n->prox,
       *atendimentos = a->prox;

    while (atendentes != NULL) {
        Adicionar(a, 0);
        atendentes = atendentes->prox;
    }
    
    int segundos = 0;
    while (m->prox != NULL) {
        atendimentos = a->prox;
        atendentes = n->prox;

        int menor = 999;
        while (atendentes != NULL) {            
            if (atendimentos->data == 0 && m->prox != NULL) {
                atendimentos->data = atendentes->data*clientes->data;
                Remover(m);
                clientes = m->prox;
            }
            if (atendimentos->data < menor) menor = atendimentos->data;
            
            atendimentos = atendimentos->prox;
            atendentes = atendentes->prox;
        }
        segundos += menor;

        atendimentos = a->prox;
        while (atendimentos != NULL) {
            atendimentos->data = atendimentos->data - menor;
            atendimentos = atendimentos->prox;
        }
    }

    int maior = -1;
    atendimentos = a->prox;
    while (atendimentos != NULL) {
        if (atendimentos->data > maior) maior = atendimentos->data;
        atendimentos = atendimentos->prox;
    }
    segundos += maior;

    Limpar(m);
    Limpar(n);
    Limpar(a);

    return segundos;
}

int main () {
    int N, M;
    scanf(" %d %d", &N, &M);

    no *atendentes = CriarLista(),
       *clientes  = CriarLista();

    for (int i = 0; i < N; i++) {
        int num;
        scanf(" %d", &num);
        Adicionar(atendentes, num);
    }

    for (int i = 0; i < M; i++) {
        int num;
        scanf(" %d", &num);
        Adicionar(clientes, num);
    }

    printf("%d", CalcularSaida(atendentes, clientes));
}