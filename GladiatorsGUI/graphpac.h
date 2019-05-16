#ifndef GRAPHPAC_H
#define GRAPHPAC_H

#include "genericlinkedlist.h"

/**
 * @brief The GraphPac class Class that manages a set of ten linked lists. Used for ghraps creation.
 */
class GraphPac
{
public:
    /**
     * @brief GraphPac Default constructor.
     */
    GraphPac();

    /**
      * @brief add Adds an integer into a given list.
      * @param num Identification number of the list.
      * @param data Integer to add to the list.
      */
     void add(int num, int data);

     /**
      * @brief get Returns one of the lists.
      * @param index List identification.
      * @return A linked list.
      */
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
