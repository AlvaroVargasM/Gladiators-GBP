//
// Created by valva on 4/13/2019.
//

#include "IntimidationZone.h"

/**
 * The default constructor for the class, it will create a matrix using linked ist with linked lists
 * and Zone class objects
 */
IntimidationZone::IntimidationZone(int n, int m) {
    this->n = n;
    this->m = m;
    for(int i = 0;i < n;++i) {
        GenericLinkedList<Zone*>* list = new GenericLinkedList<Zone*>;
        for(int j = 0;j < m;++j) {
            Zone* z = new Zone;
            z->setId(i*m + j);
            list->add(z);
        }
        this->zoneMatrix->add(list);
    }
}

/**
 * This method makes possible to retrieve a pointer to a specific Zone in the matrix
 * @param i which row you will be accessing
 * @param j which column wu will be accessing
 * @return the pointer to the zone yuo specified
 */
Zone *IntimidationZone::getZone(int i, int j) {
    GenericNode<GenericLinkedList<Zone*>*>* row = this->zoneMatrix->get(i);
    GenericLinkedList<Zone*>* column = row->getData();
    GenericNode<Zone*>* zNode = column->get(j);
    Zone* zone = zNode->getData();
    return zone;
}

void IntimidationZone::printGrid() {
    for(int i = 0; i < *this->zoneMatrix->getLength(); i++){
        GenericLinkedList<Zone*>* row = this->zoneMatrix->get(i)->getData();
        for(int j = 0; j < *this->zoneMatrix->getLength(); j++){
            Zone* current = row->get(j)->getData();
            std::cout << current->getDamage() << std::endl;
        }
    }
}

int IntimidationZone::getM() {
    return this->m;
}

int IntimidationZone::getN() {
    return this->n;
}

Zone *IntimidationZone::getZoneByID(int id) {
    int i = id % this->n;
    int j = id - (i*this->m);
    return this->getZone(i, j);
}
