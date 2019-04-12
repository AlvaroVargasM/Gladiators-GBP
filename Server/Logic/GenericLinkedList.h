//
// Created by jondorito on 03/04/19.
//

#ifndef TESTSERVER_GenericLinkedList_H
#define TESTSERVER_GenericLinkedList_H


#include "GenericNode.h"

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
private:
    GenericNode<T>* header;
    int length;
};

/**
 * This constructor doesn't take any parameters
 * @tparam T
 */
template <class T>
GenericLinkedList<T>::GenericLinkedList() {
    this->length = 0;
    this->header = nullptr;
}

/**
 * This  function creates a node with the data and sets it as a head
 * @tparam T
 * @param data
 */
template<class T>
void GenericLinkedList<T>::add(T data) {
    GenericNode<T>* temp = new GenericNode<T>(data);
    if(this->length == 0){
        this->header = temp;
        this->length++;
    }else{
        temp->setNext(this->header);
        this->header = temp;
        this->length++;
    }
}

/**
 * This function returns the node in index i
 * @tparam T
 * @param i
 * @return GenericNode<T>
 */
template <class T>
GenericNode<T>* GenericLinkedList<T>::get(int i) {
    if(this->length == 0){
        return nullptr;
    }
    GenericNode<T>* temp = this->header;
    for(int j = 0; j < i; j++){
        temp = temp->getNext();
    }
    return temp;
}

/**
 * This function removes the node on index i
 * @tparam T
 * @param i
 */
template <class T>
void GenericLinkedList<T>::remove(int i) {
    if(i == 1){
        this->header = nullptr;
    }

    GenericNode<T>* temp = get(i-1);
    GenericNode<T>* temp1 = get(i+1);
    temp->setNext(temp1);
}

/**
 * This function returns the head of the linkedlist
 * @tparam T
 * @return GenericNode<T>
 */
template<class T>
GenericNode<T> *GenericLinkedList<T>::getHead() {
    return this->header;
}

/**
 * This function returns the length of the linkedlist
 * @tparam T
 * @return
 */
template <class T>
int* GenericLinkedList<T>::getLength() {
    return &this->length;
}


#endif //TESTSERVER_GenericLinkedList_H
