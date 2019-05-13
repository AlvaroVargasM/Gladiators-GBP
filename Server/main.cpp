//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"

int main () {
    IntimidationZone* intimidationZone = new IntimidationZone(10, 10);
    intimidationZone->getZoneByID(79)->setBlocked(true);
    intimidationZone->getZoneByID(45)->setBlocked(true);
    intimidationZone->getZoneByID(37)->setBlocked(true);
    intimidationZone->getZoneByID(7)->setBlocked(true);
    intimidationZone->getZoneByID(42)->setBlocked(true);
    intimidationZone->getZoneByID(27)->setBlocked(true);
    intimidationZone->getZoneByID(11)->setBlocked(true);
    intimidationZone->getZoneByID(18)->setBlocked(true);
    intimidationZone->getZoneByID(54)->setBlocked(true);
    intimidationZone->getZoneByID(3)->setBlocked(true);
    GenericLinkedList<Zone*>* list = PathSolver::findPathByA_Star(intimidationZone, 0, 0, 9, 9);
    for(int i = 0; i < *list->getLength(); i++){
        std::cout << list->get(i)->getData()->getId() << std::endl;
    }
}
