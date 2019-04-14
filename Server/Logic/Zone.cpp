//
// Created by valva on 4/13/2019.
//

#include "Zone.h"

Zone::Zone() {
    this->blocked = false;
    this->tower = 0;
    this->damage = 0;
    this->start = false;
    this->end = false;
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

int Zone::getDamage() const {
    return this->damage;
}

void Zone::setDamage(int damage) {
    this->damage = damage;
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
    return this->f;
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
