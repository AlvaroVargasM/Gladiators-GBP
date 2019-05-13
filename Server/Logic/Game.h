//
// Created by alvar on 10/05/19.
//

#pragma once

# define BASE_DAMAGE 5
# define N_ROWS 10
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

    GenericLinkedList<std::string> new_GUI_Towers;

    int n_Towers;

public:
    Game();

    GenericLinkedList<Gladiator> getChampions();

    void putTower(int i,int j,int type);

    void generateTowers();

    void generateNewGUITower(int i,int j,int type);

    GenericLinkedList<std::string> getTowers();

    IntimidationZone *getGameZone() const;

    GenericLinkedList<std::string> calculateSteps();
};
