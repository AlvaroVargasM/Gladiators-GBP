//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"

int main () {
    /*IntimidationZone* intimidationZone = new IntimidationZone(25, 25);
    intimidationZone->getZoneByID(7)->setBlocked(true);
    intimidationZone->getZoneByID(14)->setBlocked(true);
    intimidationZone->getZoneByID(37)->setBlocked(true);
    intimidationZone->getZoneByID(7)->setBlocked(true);
    intimidationZone->getZoneByID(42)->setBlocked(true);
    intimidationZone->getZoneByID(27)->setBlocked(true);
    intimidationZone->getZoneByID(11)->setBlocked(true);
    intimidationZone->getZoneByID(18)->setBlocked(true);
    intimidationZone->getZoneByID(54)->setBlocked(true);
    intimidationZone->getZoneByID(3)->setBlocked(true);
    PathSolver* solver = new PathSolver;
    GenericLinkedList<Zone*>* list = solver->findPathByA_Star(intimidationZone, 0, 0, 24,24);
    for(int i = 0; i < *list->getLength(); i++){
        std::cout << list->get(i)->getData()->getId() << std::endl;
    }
    std::cout << solver->getA_starTime() << std::endl;*/
    Server::start();
}
