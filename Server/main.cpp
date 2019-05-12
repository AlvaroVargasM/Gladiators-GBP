//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"
#include "Logic/Game.h"

int main () {
    srand(time(nullptr));
    //Server::start();

    Game myGame;


    myGame.generateTowers();
    myGame.getGameZone()->printGrid();
}
