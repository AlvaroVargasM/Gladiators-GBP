//
// Created by jondorito on 22/04/19.
//

#ifndef GENERICNODE_H
#define GENERICNODE_H

/**
 * GenericNode class for the GenericLinkedList
 * @tparam T
 */
template<class T>
class GenericNode
{
public:
    GenericNode(T);
    T getData();
    GenericNode<T>* getNext();
    void setNext(GenericNode<T>*);

private:
    GenericNode* next;
    T data;
};

#endif // GENERICNODE_H
