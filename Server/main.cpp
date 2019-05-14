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
    RNG rng;

    //std::cout << rng.getRandomNumber(0,5);

    Game myGame;
    myGame.getTowers();

    std::cout << "\n\n--------------------------------------------------------------------------------------------\n\n";

    std::cout << myGame.getTowers().get(0)->getData() << std::endl;
    std::cout << myGame.getTowers().get(1)->getData() << std::endl;
    std::cout << myGame.getTowers().get(2)->getData() << std::endl;

    std::cout << "\n\n--------------------------------------------------------------------------------------------\n\n";

    std::cout << myGame.getChampions();

    std::cout << "\n\n--------------------------------------------------------------------------------------------\n\n";

    myGame.getPoolA().printGenerations(2);

    std::cout << "\n\n--------------------------------------------------------------------------------------------\n\n";

    myGame.getPoolB().printGenerations(2);

    std::cout << "\n\n--------------------------------------------------------------------------------------------\n\n";

    std::cout << myGame.getStats() << std::endl;

}