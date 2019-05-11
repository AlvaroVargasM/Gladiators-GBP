//
// Created by jonathan on 01/05/19.
//
#include "Gladiator.h"
#include "IntimidationZone.h"
#include "GenericLinkedList.h"
#include "BackTracking.h"
#include "Zone.h"




IntimidationZone* grid= new IntimidationZone(10,10);
GenericLinkedList<Zone>*path= new GenericLinkedList<Zone>;

bool BackTracking::visited(Zone *zone, GenericLinkedList<Zone> *p) {
    if (zone->getId()== path->get(*path->getLength())->getData().getId()){
        return true;
    }
}

 GenericLinkedList<Zone>* BackTracking::BackTrack(IntimidationZone *grid, int a, int b) {


    Zone*zone=new Zone;
    zone->setTower(00);

    for(int i = 0; i < grid->getN(); i++){
        for(int j = 0; j < grid->getM(); j++){

            if(grid->getZone(i,j+1)->getTower()!=zone->getTower()&& visited(grid->getZone(i,j),path)){
                BackTrack(grid,i,j+1);
                path->add(*grid->getZone(i,j+1));
            }
            else
                if(grid->getZone(i+1,j)->getTower()!=zone->getTower()){
                    BackTrack(grid,i+1,j);
                    path->add(*grid->getZone(i+1,j));
                }
                else
                    BackTrack(grid,i,j-1);
                    path->deleteEndNode();


        }
    }



 return path;

}

