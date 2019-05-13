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

    //myGame.getGameZone()->printGrid();
    std::cout << myGame.getTowers().get(0)->getData() << std::endl;
    std::cout << myGame.getTowers().get(1)->getData() << std::endl;
    std::cout << myGame.getTowers().get(2)->getData() << std::endl;

    std::cout << "\n\n--------------------------------------------------------------------------------------------\n\n";

    std::cout << myGame.getChampions();

    /*
    GA genetic;

    std::cout << "\n\n GEN: " << genetic.getGeneration() << " Initial POP:\n";
    genetic.printPopResistance();
    std::cout << "CHAMPION: " << genetic.getStrongest().getResistance();

    for (int i = 0;i < 14;i++) {
        genetic.newGen();
        std::cout << "\n\n GEN " << genetic.getGeneration() << " RESISTANCE: " << std::endl;
        genetic.printPopResistance();
        std::cout << "CHAMPION: " << genetic.getStrongest().getResistance() << std::endl;
        std::cout << "Average ei: " << genetic.averageEmotionalIntelligence() << std::endl;
        std::cout << "Average pc: " << genetic.averagePhysicalCondition() << std::endl;
        std::cout << "Average ubs: " << genetic.averageUpperBodyStrength() << std::endl;
        std::cout << "Average lbs: " << genetic.averageLowerBodyStrength() << std::endl;
    }
     */
}
