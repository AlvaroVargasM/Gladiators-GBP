#include "genericlinkedlist.h"

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
    std::cout << "Added " << data << " to the list" << std::endl;
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
    this->length--;
    if(i == 1){
        GenericNode<T>* temp = this->header;
        this->header = this->header->getNext();
        //delete(temp);
    }else {
        GenericNode<T> *tmp = get(i);
        GenericNode<T> *temp = get(i - 1);
        if (temp != nullptr) {
            GenericNode<T> *temp1 = get(i + 1);
            temp->setNext(temp1);
        }
        //delete(tmp);
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


/**
 * This function prints the content of all of the nodes one by one
 * @tparam T
 */
template<class T>
void GenericLinkedList<T>::printList() {
    for(int i = 0; i < this->length; i++){
        std::cout << "Node data is " << this->get(i)->getData() << std::endl;
    }
}

template class GenericLinkedList<std::string>;
template class GenericLinkedList<int>;
