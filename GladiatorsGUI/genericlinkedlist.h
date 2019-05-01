#ifndef GENERICLINKEDLIST_H
#define GENERICLINKEDLIST_H

#include "genericnode.h"
#include <iostream>


/**
 * Class use for storing any type of object
 * @tparam T
 */
template <class T>
class GenericLinkedList{
public:
    GenericLinkedList();
    void add(T);
    void remove(int);
    GenericNode<T>* get(int);
    GenericNode<T>* getHead();
    int* getLength();
    void printList();
private:
    GenericNode<T>* header;
    int length;
};



#endif // GENERICLINKEDLIST_H
