#ifndef DATASTRUCTURESLIB_H_INCLUDED
#define DATASTRUCTURESLIB_H_INCLUDED

namespace DataStructureLib {

class LinkedList {
    struct Node;
    public:
        LinkedList();
        struct Node* head;
        void Add(int valor_add);
        void Ler();
    };


}

#endif // DATASTRUCTURESLIB_H_INCLUDED
