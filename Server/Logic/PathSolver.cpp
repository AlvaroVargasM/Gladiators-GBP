//
// Created by jondorito on 06/05/19.
//

#include "PathSolver.h"
#include <cmath>

GenericLinkedList<Zone *> *PathSolver::findPathByA_Star(IntimidationZone *grid, int x_i, int y_i, int x_f, int y_f) {
    for(int i = 0; i < grid->getN(); i++){
        for(int j = 0; j < grid->getM(); j++){
            Zone* z = grid->getZone(i, j);
            if(i > 0){
                Zone* neighbor = grid->getZone(i-1, j);
                z->addNeighbor(neighbor);
                if(j > 0){
                    Zone* neighbor = grid->getZone(i-1, j-1);
                    z->addNeighbor(neighbor);
                }if(j < grid->getM()-1){
                    Zone* neighbor = grid->getZone(i-1, j+1);
                    z->addNeighbor(neighbor);
                }
            }if(j > 0){
                Zone* neighbor = grid->getZone(i, j-1);
                z->addNeighbor(neighbor);
            }if(j < grid->getM()-1){
                Zone* neighbor = grid->getZone(i, j+1);
                z->addNeighbor(neighbor);
            }if(i < grid->getN()-1){
                Zone* neighbor = grid->getZone(i+1, j);
                z->addNeighbor(neighbor);
                if(j > 0){
                    Zone* neighbor = grid->getZone(i+1, j-1);
                    z->addNeighbor(neighbor);
                }if(j < grid->getM()-1){
                    Zone* neighbor = grid->getZone(i+1, j+1);
                    z->addNeighbor(neighbor);
                }
            }
        }
    }
    GenericLinkedList<Zone*>* openSet = new GenericLinkedList<Zone*>;
    GenericLinkedList<Zone*>* closedSet = new GenericLinkedList<Zone*>;

    int start = grid->getZone(x_i, y_i)->getId();
    int finish = grid->getZone(x_f, x_f)->getId();

    openSet->add(grid->getZoneByID(start));

    while(*openSet->getLength() > 0){
        Zone* lowest = openSet->get(0)->getData();
        int lowest_i = 0;
        for(int i = 0; i < *openSet->getLength(); i++){
            Zone* temp = openSet->get(i)->getData();
            if(temp->getF() < lowest->getF()){
                lowest = temp;
                lowest_i = i;
            }
        }

        Zone* current = lowest;

        if(current->getId() == finish){
            GenericLinkedList<Zone*>* path = new GenericLinkedList<Zone*>;
            Zone* temp = current;
            while(temp->getParent() != nullptr){
                path->add(temp);
                temp = temp->getParent();
            }
            return path;
        }

        openSet->remove(lowest_i);
        closedSet->add(current);

        GenericLinkedList<Zone*>* neighbors = current->getNeighbors();
        for(int i = 0; i < *neighbors->getLength(); i++){
            Zone* temp = neighbors->get(i)->getData();
            if(!closedSet->includes(temp)) {
                int tempG = current->getG() + 1;
                if (openSet->includes(temp)) {
                    if (tempG < temp->getG()) {
                        temp->setG(tempG);
                    }
                } else {
                    temp->setG(tempG);
                    openSet->add(temp);
                }
            }
        }
    }

}
/**
 * This function takes a node and verifies in the path list.
 * @param zone
 * @tparam Linkedlist of nodes  type zone
 *
 * @return bool
 */
bool PathSolver::visited(Zone *zone, GenericLinkedList<Zone*> *node) {
if (zone->getId()==node->get(*node->getLength())->getData()->getId()){
return true;}
}

/**
 * his function takes an intimidation zone and looks for the route to
 * reach the lower right diagonal in an efficient way using the recursive logic of
 * BackTraking

 * @param IntimidationZone
 * @param  a,b index
 *
 * @return GenericLinkedList<Zone *>
 */

GenericLinkedList<Zone*>*PathSolver::BackTrack(IntimidationZone *grid, int a, int b) {
    GenericLinkedList<Zone *> *path = new GenericLinkedList<Zone *>;


    Zone *zone = new Zone;
    zone->setTower(00);

    // condicion de parada.
    if (a== grid->getN()&& b==grid->getM()){
        return path;

    }

    if (grid->getZone(a, b + 1)->getTower() != zone->getTower() && (visited(grid->getZone(a, b), path) != true)) {
        path->add(grid->getZone(a, b + 1));
        return BackTrack(grid, a, b + 1);

    }
    else

        if (grid->getZone(a + 1, b)->getTower() != zone->getTower()){
        path->add(grid->getZone(a + 1, b));
        return BackTrack(grid, a + 1, b);

    }
        else
        path->deleteEndNode();
        return BackTrack(grid, a, b - 1);


}














