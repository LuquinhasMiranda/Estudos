#include "DataStructuresLib.h"
#include <stdio.h>
#include <stdlib.h>

namespace DataStructureLib {

struct LinkedList::Node{
    int valor;
    struct Node* next;
};

LinkedList::LinkedList() {
    head = (struct Node*) malloc(sizeof(struct Node));
    head->valor = NULL;
    head->next = NULL;
}

void LinkedList::Add(int valor_add){
    struct Node* p = head;
    while (p->next != NULL) p = p->next;

    struct Node* novo = (struct Node*) malloc(sizeof(struct Node));
    novo->valor = valor_add;
    novo->next = NULL;
    p->next = novo;
}

void LinkedList::Ler() {
    struct Node* p = head;
    while (true) {
        p = p->next;
        printf("%d ", p->valor);
        if (p->next == NULL) break;
    }
}

}
