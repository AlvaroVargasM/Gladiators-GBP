#ifndef GRAPHPAC_H
#define GRAPHPAC_H

#include "genericlinkedlist.h"

class GraphPac
{
public:
    GraphPac();
     void add(int num, std::string);
     GenericLinkedList<std::string>* get(int index);
private:
    GenericLinkedList<std::string>* gen1 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen2 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen3 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen4 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen5 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen6 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen7 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen8 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen9 = new GenericLinkedList<std::string>;
    GenericLinkedList<std::string>* gen10 = new GenericLinkedList<std::string>;
};

#endif // GRAPHPAC_H
