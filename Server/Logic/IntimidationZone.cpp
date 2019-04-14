//
// Created by valva on 4/13/2019.
//

#include "IntimidationZone.h"

IntimidationZone::IntimidationZone() {
    for(int i = 0;i < 10;++i) {
        GenericLinkedList<Zone> list;
        for(int i = 0;i < 10;++i) {
            Zone z;
            list.add(z);
        }
        this->zoneMatrix.add(list);
    }
}

Zone *IntimidationZone::getZone(int i, int j) {
    GenericNode<GenericLinkedList<Zone>>* row = this->zoneMatrix.get(i);
    GenericLinkedList<Zone> column = row->getData();
    GenericNode<Zone>* zNode = column.get(j);
    Zone zone = zNode->getData();
    Zone* zPtr = &zone;
    return zPtr;
}
