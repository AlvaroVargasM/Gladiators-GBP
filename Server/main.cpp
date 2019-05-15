//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"

int main () {
    srand(time((nullptr)));

    Game g;

    g.getTowers();

    std::cout << g.getSteps();
}
