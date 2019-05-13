//
// Created by jondorito on 06/05/19.
//

#ifndef GLADIATORS_GBP_PATHSOLVER_H
#define GLADIATORS_GBP_PATHSOLVER_H


#include "GenericLinkedList.h"
#include "Zone.h"
#include "IntimidationZone.h"

class PathSolver {
public:
    static GenericLinkedList<Zone*>* findPathByA_Star(IntimidationZone* grid, int x_i, int y_i, int x_f, int y_f);

    GenericLinkedList<Zone*>* BackTrack(IntimidationZone *grid, int xo, int yo,int  xf,int yf);
    bool visited(Zone *zone,GenericLinkedList<Zone*> *p);
};


#endif //GLADIATORS_GBP_PATHSOLVER_H
