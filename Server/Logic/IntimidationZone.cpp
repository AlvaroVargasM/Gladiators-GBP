//
// Created by valva on 4/13/2019.
//

#include "IntimidationZone.h"

/**
 * The default constructor for the class, it will create a matrix using linked ist with linked lists
 * and Zone class objects
 */
IntimidationZone::IntimidationZone() {
    for(int i = 0;i < 10;++i) {
        GenericLinkedList<Zone> list;
        for(int i = 0;i < 10;++i) {
            Zone z;
            list.add(z);
        }
        this->zoneMatrix.add(list);
    }
}

/**
 * This method makes possible to retrieve a pointer to a specific Zone in the matrix
 * @param i which row you will be accessing
 * @param j which column wu will be accessing
 * @return the pointer to the zone yuo specified
 */
Zone *IntimidationZone::getZone(int i, int j) {
    GenericNode<GenericLinkedList<Zone>>* row = this->zoneMatrix.get(i);
    GenericLinkedList<Zone> column = row->getData();
    GenericNode<Zone>* zNode = column.get(j);
    Zone zone = zNode->getData();
    Zone* zPtr = &zone;
    return zPtr;
}
