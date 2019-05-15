//
// Created by valva on 4/13/2019.
//

#include "Zone.h"

Zone::Zone() {
    this->blocked = false;
    this->tower = 0;
    this->g = 0;
    this->h = 0;
    this->f = 0;
    this->start = false;
    this->end = false;
    this->previous = nullptr;

}

int Zone::getId() const {
    return this->id;
}

void Zone::setId(int id) {
    this->id = id;
}

bool Zone::isBlocked() const {
    return this->blocked;
}

void Zone::setBlocked(bool blocked) {
    this->blocked = blocked;
}

int Zone::getTower() const {
    return this->tower;
}

void Zone::setTower(int tower) {
    this->tower = tower;
}

GenericLinkedList<GenericLinkedList<int>*>* Zone::getDamage() {
    return this->damage;
}

int Zone::getG() const {
    return this->g;
}

void Zone::setG(int g) {
    this->g = g;
}

int Zone::getH() const {
    return this->h;
}

void Zone::setH(int h) {
    this->h = h;
}

int Zone::getF() const {
    return this->g + this->h;
}

void Zone::setF(int f) {
    this->f = f;
}

bool Zone::isStart() const {
    return this->start;
}

void Zone::setStart(bool start) {
    this->start = start;
}

bool Zone::isEnd() const {
    return this->end;
}

void Zone::setEnd(bool end) {
    this->end = end;
}

void Zone::addNeighbor(Zone* zone) {
    this->neighbors->add(zone);
}

GenericLinkedList<Zone*>* Zone::getNeighbors() {
    return this->neighbors;
}

Zone *Zone::getParent() {
    return this->previous;
}

void Zone::setParent(Zone* zone) {
    this->previous = zone;
}

int Zone::getX(int n) {
    int x = this->id / n;
    //std::cout << "Found this x " << x << std::endl;
    return  x;
}

int Zone::getY(int n, int m) {
    int y = this->id - (this->getX(n)*m);
    //std::cout << "Found this y " << y << std::endl;
    return y;
}
