//
// Created by alvar on 10/05/19.
//

#pragma once

# define BASE_DAMAGE 5
# define N_ROWS 10
# define N_COLUMNS 10

#include "GA.h"
#include "IntimidationZone.h"
#include "PathSolver.h"

class Game {
private:
    RNG rng;

    PathSolver pths;

    GA pool_A;

    GA pool_B;

    std::string averageGensRes;

    std::string averageGensEI;

    std::string averageGensPC;

    std::string averageGensStr;

    IntimidationZone* game_Zone = new IntimidationZone(N_ROWS,N_COLUMNS);

    int iteration;

    GenericLinkedList<std::string> new_GUI_Towers;

    int n_Towers;

    void generateTowers();

    void putTower(int i,int j,int type);

    void generateNewGUITower(int i,int j,int type);

public:
    void saveGenStats();

    Game();

    std::string getChampions();

    GenericLinkedList<std::string> getTowers();

    std::string calculateSteps();

    std::string getStats();

    GA &getPoolA();

    GA &getPoolB();
};
