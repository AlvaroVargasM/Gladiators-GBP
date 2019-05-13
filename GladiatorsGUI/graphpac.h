#ifndef GRAPHPAC_H
#define GRAPHPAC_H

#include "genericlinkedlist.h"

class GraphPac
{
public:
    GraphPac();
     void add(int num, int data);
     GenericLinkedList<int> get(int index);
private:
    GenericLinkedList<int> gen1 = GenericLinkedList<int>();
    GenericLinkedList<int> gen2 = GenericLinkedList<int>();
    GenericLinkedList<int> gen3 = GenericLinkedList<int>();
    GenericLinkedList<int> gen4 = GenericLinkedList<int>();
    GenericLinkedList<int> gen5 = GenericLinkedList<int>();
    GenericLinkedList<int> gen6 = GenericLinkedList<int>();
    GenericLinkedList<int> gen7 = GenericLinkedList<int>();
    GenericLinkedList<int> gen8 = GenericLinkedList<int>();
    GenericLinkedList<int> gen9 =  GenericLinkedList<int>();
    GenericLinkedList<int> gen10 = GenericLinkedList<int>();
};

#endif // GRAPHPAC_H
