//
// Created by jon on 01/05/19.
//

#ifndef GLADIATORS_GBP_BACKTRACKING_H
#define GLADIATORS_GBP_BACKTRACKING_H


class BackTracking {



public:

    GenericLinkedList<Zone >* BackTrack(IntimidationZone *grid,int a,int b );
   bool visited(Zone *zone,GenericLinkedList<Zone>*p);


};


#endif //GLADIATORS_GBP_BACKTRACKING_H
