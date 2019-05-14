//
// Created by jondorito on 06/05/19.
//

#include "PathSolver.h"
#include <cmath>
int heuristic(int x0, int y0, int x1, int y1){
    /*int p1 = static_cast<int> (pow((x1 - x0), 2));
    std::cout << "P1 = " << p1 << std::endl;
    int p2 = static_cast<int> (pow((y1 - y0), 2));
    std::cout << "P2 = " << p2 << std::endl;
    int result = static_cast<int> (pow((p1 + p2), (1/2)));
    std::cout << "Result = " << result << std::endl;*/
    int result = std::abs(x1-x0) + std::abs(y1-y0);
    return result;
}


GenericLinkedList<Zone *> *PathSolver::findPathByA_Star(IntimidationZone *grid, int x_i, int y_i, int x_f, int y_f) {
    for(int i = 0; i < grid->getN(); i++){
        for(int j = 0; j < grid->getM(); j++){
            Zone* z = grid->getZone(i, j);
            if(i > 0){
                Zone* neighbor = grid->getZone(i-1, j);
                z->addNeighbor(neighbor);
                /*if(j > 0){
                    Zone* neighbor = grid->getZone(i-1, j-1);
                    z->addNeighbor(neighbor);
                }if(j < grid->getM()-1){
                    Zone* neighbor = grid->getZone(i-1, j+1);
                    z->addNeighbor(neighbor);
                }*/
            }if(j > 0){
                Zone* neighbor = grid->getZone(i, j-1);
                z->addNeighbor(neighbor);
            }if(j < grid->getM()-1){
                Zone* neighbor = grid->getZone(i, j+1);
                z->addNeighbor(neighbor);
            }if(i < grid->getN()-1){
                Zone* neighbor = grid->getZone(i+1, j);
                z->addNeighbor(neighbor);
                /*if(j > 0){
                    Zone* neighbor = grid->getZone(i+1, j-1);
                    z->addNeighbor(neighbor);
                }if(j < grid->getM()-1){
                    Zone* neighbor = grid->getZone(i+1, j+1);
                    z->addNeighbor(neighbor);
                }*/
            }
        }
    }
    GenericLinkedList<Zone*>* openSet = new GenericLinkedList<Zone*>;
    GenericLinkedList<Zone*>* closedSet = new GenericLinkedList<Zone*>;

    int start = grid->getZone(x_i, y_i)->getId();
    int finish = grid->getZone(x_f, x_f)->getId();

    openSet->add(grid->getZoneByID(start));
    while(*openSet->getLength() > 0){
        std::cout << "Analizando..." << std::endl;
        Zone* lowest = openSet->get(0)->getData();
        int lowest_i = 0;
        for(int i = 0; i < *openSet->getLength(); i++){
            Zone* temp = openSet->get(i)->getData();
            if(temp->getF() < lowest->getF()){
                lowest = temp;
                lowest_i = i;
                std::cout << "Nuevo mejor " << lowest->getId() << std::endl;
            }
        }

        std::cout << "Viendo a nodo " << lowest->getId() << std::endl;

        Zone* current = lowest;

        grid->printGridProgress(current->getId(), finish);

        if(current->getId() == finish){
            GenericLinkedList<Zone*>* path = new GenericLinkedList<Zone*>;
            Zone* temp = current;
            while(temp->getParent() != nullptr){
                path->add(temp);
                temp = temp->getParent();
            }
            GenericLinkedList<Zone*>* reversedPath = new GenericLinkedList<Zone*>;
            for(int i = *path->getLength()-1; i >= 0; i--){
                reversedPath->add(path->get(i)->getData());
            }
            return reversedPath;
        }

        openSet->remove(lowest_i);
        closedSet->add(current);

        GenericLinkedList<Zone*>* neighbors = current->getNeighbors();
        for(int i = 0; i < *neighbors->getLength(); i++){
            Zone* temp = neighbors->get(i)->getData();
            std::cout << "Analizando vecino " << temp->getId() << std::endl;
            if(!temp->isBlocked()){
                if(!closedSet->includes(temp)) {
                    std::cout << "No esta en el closed set" << std::endl;
                    int tempG = current->getG() + 1;
                    std::cout << "linea 99" << std::endl;
                    if (openSet->includes(temp)) {
                        std::cout << "Ya esta en el open set" << std::endl;
                        if (tempG < temp->getG()) {
                            std::cout << "Tengo una mejor G" << std::endl;
                            temp->setG(tempG);
                            temp->setParent(current);
                        }
                    } else {
                        std::cout << "linea 108" << std::endl;
                        temp->setG(tempG);
                        std::cout << "Tiene una g de " << tempG << std::endl;
                        int nX = temp->getX(grid->getM());
                        int nY = temp->getY(grid->getN(), grid->getM());
                        int fX = grid->getZoneByID(finish)->getX(grid->getM());
                        int fY = grid->getZoneByID(finish)->getY(grid->getN(), grid->getM());
                        int hrtic = heuristic(nX, nY, fX, fY);
                        std::cout << "Tiene heurista de " << hrtic << std::endl;
                        temp->setH(hrtic);
                        temp->setF(tempG + hrtic);
                        std::cout << "Tiene una F de " << temp->getF() << std::endl;
                        temp->setParent(current);
                        openSet->add(temp);
                    }
                }
            }else{
                closedSet->add(temp);
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
    if(*node->getLength()==0){
        return false;
    }

    if (node->includes(zone)){
    return true;
}

}

/**
 * This function takes an intimidation zone and looks for the route to
 * reach the lower right diagonal in an efficient way using the recursive logic of
 * BackTraking

 * @param IntimidationZone
 * @param  a,b index
 *
 * @return GenericLinkedList<Zone *>
 */
GenericLinkedList<Zone *> *path = new GenericLinkedList<Zone *>;

GenericLinkedList<Zone*>*PathSolver::BackTrack(IntimidationZone *grid, int xo, int yo,int  xf,int yf) {


    Zone *zone = new Zone;
    //zone->setTower(00);

    // condicion de parada.-
    if (xo==xf && yo==yf){
        return path;

    }

    if ((grid->getZone(xo,yo + 1)->isBlocked()==false)  && (visited(grid->getZone(xo, yo), path))) {
        path->add(grid->getZone(xo,yo ));
        return BackTrack(grid, xo,yo+1,grid->getN(),grid->getM());

    }
    else

        if (grid->getZone(xo + 1, yo)->isBlocked() ==false){
            path->add(grid->getZone(xo + 1, yo));
            return BackTrack(grid, xo + 1, yo,grid->getN(),grid->getM());

    }
        else
        path->deleteEndNode();
        return BackTrack(grid, xo, yo - 1,grid->getN(),grid->getM());



}














