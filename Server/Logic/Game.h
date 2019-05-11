//
// Created by alvar on 10/05/19.
//

#pragma once

#define N_ROWS 10
# define N_COLUMNS 10

#include "GA.h"
#include "IntimidationZone.h"

class Game {
private:
    RNG rng;

    GA pool_A;
    GA pool_B;

    IntimidationZone* game_Zone = new IntimidationZone(N_ROWS,N_COLUMNS);

    int iteration;

    GenericLinkedList<std::string> calculateSteps();

public:
    Game() = default;

    GenericLinkedList<Gladiator> getChampions();

    void putTower(int i,int j,int type);

    void generateTowers();

    IntimidationZone *getGameZone() const;
};
