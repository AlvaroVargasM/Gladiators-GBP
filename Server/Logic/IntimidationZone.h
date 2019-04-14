//
// Created by valva on 4/13/2019.
//

#ifndef GLADIATORS_GBP_INTIMIDATIONZONE_H
#define GLADIATORS_GBP_INTIMIDATIONZONE_H


#include "GenericLinkedList.h"
#include "GenericNode.h"
#include "Zone.h"

/**
 * This a class for the game matrix, it has a linked of linked lists for representing the board.
 */
class IntimidationZone {
private:
    GenericLinkedList<GenericLinkedList<Zone>> zoneMatrix;

public:
    IntimidationZone();

    Zone* getZone(int i, int j);
};


#endif //GLADIATORS_GBP_INTIMIDATIONZONE_H
