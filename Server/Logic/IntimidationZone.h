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
    GenericLinkedList<GenericLinkedList<Zone*>*>* zoneMatrix = new GenericLinkedList<GenericLinkedList<Zone*>*>;
    int n;
    int m;
public:
    IntimidationZone(int n, int m);
    Zone* getZone(int i, int j);
    Zone* getZoneByID(int id);
    void printGrid();
    int getN();
    int getM();
};


#endif //GLADIATORS_GBP_INTIMIDATIONZONE_H
