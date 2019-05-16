//
// Created by jondorito on 22/04/19.
//

#ifndef GENERICNODE_H
#define GENERICNODE_H

template<class T>
/**
 * @brief The GenericNode class GenericNode class for the GenericLinkedList.
 */
class GenericNode
{
public:
    /**
     * Generic Node constructor
     * @tparam T
     * @param data
     */
    GenericNode(T);

    /**
     * Return a data on an existing node
     * @tparam T
     * @return T
     */
    T getData();

    /**
     * Returns the node next to this one
     * @tparam T
     * @return GenericNode<T>*
     */
    GenericNode<T>* getNext();

    /**
     * Sets a pointer to a newly created node with is going to be the next
     * @tparam T
     * @param next
     */
    void setNext(GenericNode<T>*);
private:
    GenericNode* next;
    T data;
};

#endif // GENERICNODE_H
