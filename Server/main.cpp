//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"

int main () {
    Game g;
    //g.getTowers();
    //std::cout << g.calculateSteps();
    // Server::start();
    PathSolver *pathSolver;
    IntimidationZone *intimidationZone = new IntimidationZone(10, 10);

  //  intimidationZone->getZoneByID(2)->setBlocked(true);
    intimidationZone->getZoneByID(1)->setBlocked(true);
    intimidationZone->getZoneByID(4)->setBlocked(true);
    intimidationZone->getZoneByID(9)->setBlocked(true);
    intimidationZone->getZoneByID(8)->setBlocked(true);
    intimidationZone->getZoneByID(11)->setBlocked(true);




    //intimidationZone->getZoneByID(5)->setBlocked(true);

     GenericLinkedList<Zone*>*list= pathSolver->BackTrack(intimidationZone,0,0,9,9);
    for(int i = 0; i < *list->getLength(); i++){

        std:: cout<<list->get(i)->getData()->getId()<<"\n";

    }










}



