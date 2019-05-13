//
// Created by jondorito on 03/04/19.
//

#ifndef TESTSERVER_GenericLinkedList_H
#define TESTSERVER_GenericLinkedList_H


#include <iostream>
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
    bool includes(T);
    void deleteEndNode();
private:
    GenericNode<T>* header;
    GenericNode<T>* last;
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
    this->last = nullptr;
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
    }else{
        if(this->last == nullptr){
            this->header->setNext(temp);
            this->last = temp;
        }else{
            this->last->setNext(temp);
            this->last = temp;
        }
    }
    this->length++;
    //std::cout << "Added " << data << " to the list" << std::endl;
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
    if(this->length == 1){
        this->header = nullptr;
        this->length--;
    }else{
        GenericNode<T>* temp = get(i);
        if(i == 1){
            this->header->setNext(temp->getNext());
            this->length--;
            //delete(temp);
        }if(i == 0) {
            this->header = this->header->getNext();
            this->length--;
        }else{
            get(i-1)->setNext(get(i+1));
            this->length--;
            //delete(temp);
        }
    }
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

template<class T>
bool GenericLinkedList<T>::includes(T data) {
    for(int i = 0; i < this->length; i++){
        if(data == get(i)->getData()){
            return true;
        }
    }return false;
}


template<class T>
void GenericLinkedList<T>::deleteEndNode(){
    GenericNode<T>*ptr;
    GenericNode<T>*prev;
    if ( header== nullptr)
        std::cout << "The list is empty, cant delete nack node.\n";
    else {
        ptr = header;
        while (ptr->getNext() != nullptr) {
            prev = ptr;
            ptr = ptr->getNext();
        }
        prev->setNext(nullptr);
        delete(ptr);
    }
    this->length--;
}


#endif //TESTSERVER_GenericLinkedList_H
