#include <iostream>
#include "DataStructuresLib.h"

using namespace DataStructureLib;

struct node {
    int x = NULL;
    struct node* next = NULL;
};

int main()
{
    LinkedList ll = LinkedList();
    ll.Add(1);
    ll.Add(2);
    ll.Add(3);
    ll.Add(4);
    ll.Add(5);
    ll.Add(5);
    ll.Add(4);
    ll.Add(3);
    ll.Add(2);
    ll.Add(1);
    ll.Ler();

    return 0;
}
