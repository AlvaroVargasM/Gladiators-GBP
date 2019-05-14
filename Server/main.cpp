//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"

int main () {
    IntimidationZone* intimidationZone = new IntimidationZone(4, 4);
    //intimidationZone->getZoneByID(5)->setBlocked(true);
    //intimidationZone->getZoneByID(6)->setBlocked(true);
    //intimidationZone->getZoneByID(7)->setBlocked(true);
    //intimidationZone->getZoneByID(11)->setBlocked(true);

    PathSolver* solver = new PathSolver;
    GenericLinkedList<Zone*>* list = solver->BackTrack(intimidationZone, 0, 0, 3,2);
    for(int i = 0; i < *list->getLength(); i++){
        std::cout << list->get(i)->getData()->getId() << std::endl;
    }
    std::cout << solver->getA_starTime() << std::endl;
  //  Server::start();
}
