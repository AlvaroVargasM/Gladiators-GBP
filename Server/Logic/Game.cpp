//
// Created by alvar on 10/05/19.
//

#include "Game.h"

/**
 * Generates three random towers in the game zones of random type
 */
void Game::generateTowers() {
    for (int x = 0;x < 3;x++) {
        int i = rng.getRandomNumber(0,N_ROWS - 1);
        int j = rng.getRandomNumber(0,N_COLUMNS - 1);
        int type = this->rng.getRandomNumber(1,3);

        if (!this->game_Zone->getZone(i, j)->isBlocked()) {
            putTower(i,j,type);
        } else --x;
    }
}

void Game::putTower(int i, int j, int type) {
    int damage;
    switch (type) {
        case 1:
            damage = 10;
            break;
        case 2:
            damage = 20;
            break;
        case 3:
            damage = 40;
            break;
        default:
            damage = 0;
            break;
    }
    this->game_Zone->getZone(i,j)->setBlocked(true);
    this->game_Zone->getZone(i,j)->setDamage(0);

    for(int x = 1;x < (type + 1);x++) {
        if (!this->game_Zone->getZone(i - x,j)->isBlocked() && i - x >= 0)
            this->game_Zone->getZone(i - x,j)->setDamage(damage);

        if (!this->game_Zone->getZone(i + x,j)->isBlocked() && i + x < N_ROWS)
            this->game_Zone->getZone(i + x,j)->setDamage(damage);

        if (!this->game_Zone->getZone(i,j - x)->isBlocked() && j - x >= 0)
            this->game_Zone->getZone(i,j - x)->setDamage(damage);

        if (!this->game_Zone->getZone(i,j + x)->isBlocked() && j + x < N_COLUMNS)
            this->game_Zone->getZone(i,j + x)->setDamage(damage);

        if (!this->game_Zone->getZone(i - x,j - x)->isBlocked() && i - x >= 0 && j - x >= 0)
            this->game_Zone->getZone(i - x,j - x)->setDamage(damage);

        if (!this->game_Zone->getZone(i - x,j + x)->isBlocked() && i - x >= 0 && j + x < N_COLUMNS)
            this->game_Zone->getZone(i - x,j + x)->setDamage(damage);

        if (!this->game_Zone->getZone(i + x,j - x)->isBlocked() && i + x < N_ROWS && j - x >= 0)
            this->game_Zone->getZone(i + x,j - x)->setDamage(damage);

        if (!this->game_Zone->getZone(i + x,j + x)->isBlocked() && i + x < N_ROWS && j + x < N_COLUMNS)
            this->game_Zone->getZone(i + x,j + x)->setDamage(damage);
    }
}

GenericLinkedList<std::string> Game::calculateSteps() {
    return GenericLinkedList<std::string>();
}

/**
 * Gets the best Gladiator from each pool and puts them in a linked list
 * @return linked list with the best gladiators from each pool
 */
GenericLinkedList<Gladiator> Game::getChampions() {
    GenericLinkedList<Gladiator> champs;
    champs.add(pool_A.getStrongest());
    champs.add(pool_B.getStrongest());
    return champs;
}

IntimidationZone *Game::getGameZone() const {
    return game_Zone;
}
