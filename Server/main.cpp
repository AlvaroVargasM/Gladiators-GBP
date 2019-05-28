//
// Created by alvar on 11/04/19.
//

#include "Logic/IntimidationZone.h"
#include "Logic/PathSolver.h"
#include "Networking/Server.h"
#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
    srand(time(nullptr));
    //Server::start();
    //GA g;
    //g.printGenerations(5);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
