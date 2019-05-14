//
// Created by alvar on 10/05/19.
//

#pragma once

#define BASE_DAMAGE 4
#define N_ROWS 10
#define N_COLUMNS 10
#define INI_I 0
#define INI_J 0
#define FIN_I 9
#define FIN_J 9


#include "GA.h"
#include "IntimidationZone.h"
#include "PathSolver.h"

class Game {
private:
    RNG rng;

    PathSolver pths;

    GenericLinkedList<Zone*> path_A;

    GA pool_A;

    GA pool_B;

    bool completed_A;
    bool completed_B;

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
    Game();

    std::string getChampions();

    GenericLinkedList<std::string> getTowers();

    std::string calculateSteps();

    GenericLinkedList<Zone*> resizePath(int type);

    std::string getStats();

    GA &getPoolA();

    GA &getPoolB();

    void saveGenStats();

    bool isCompletedA();

    bool isCompletedB();
};
