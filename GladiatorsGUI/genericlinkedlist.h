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
    /**
     * This constructor doesn't take any parameters
     * @tparam T
     */
    GenericLinkedList();

    /**
     * This  function creates a node with the data and sets it as a head
     * @tparam T
     * @param data
     */
    void add(T);

    /**
     * This function removes the node on index i
     * @tparam T
     * @param i
     */
    void remove(int);

    /**
     * This function returns the node in index i
     * @tparam T
     * @param i
     * @return GenericNode<T>
     */
    GenericNode<T>* get(int);

    /**
     * This function returns the head of the linkedlist
     * @tparam T
     * @return GenericNode<T>
     */
    GenericNode<T>* getHead();

    /**
     * This function returns the length of the linkedlist
     * @tparam T
     * @return
     */
    int getLength();

    /**
     * This function prints the content of all of the nodes one by one
     * @tparam T
     */
    void printList();
private:
    GenericNode<T>* header;
    GenericNode<T>* last;
    int length;
};



#endif // GENERICLINKEDLIST_H
