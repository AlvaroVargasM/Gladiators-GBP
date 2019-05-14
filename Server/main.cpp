//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"

int main () {
    Game g;
    g.getTowers();
    std::cout << g.calculateSteps();
    // Server::start();
}
