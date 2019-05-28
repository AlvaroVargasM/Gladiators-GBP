//
// Created by jondorito on 26/05/19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Logic/IntimidationZone.h"
#include "../Logic/PathSolver.h"

#define N 10
#define M 10
#define ZONE_ID 50
#define ZONE_X 5
#define ZONE_Y 0

IntimidationZone* intimidationZone = new IntimidationZone(N, M);

TEST(intimidationZone, GetZoneByID){
    Zone* zoneByXY = intimidationZone->getZone(ZONE_X, ZONE_Y);
    Zone* zoneByID = intimidationZone->getZoneByID(ZONE_ID);
    EXPECT_EQ(zoneByXY->getId(), zoneByID->getId());
}

TEST(intimidationZone, GetIntimidationN){
    int n = intimidationZone->getN();
    EXPECT_EQ(N, n);
}

TEST(intimidationZone, GetIntimidationM){
    int m = intimidationZone->getM();
    EXPECT_EQ(M, m);
}

TEST(intimidationZone, A_Star_Path){
    PathSolver* pathSolver = new PathSolver;
    GenericLinkedList<Zone*>* results = pathSolver->findPathByA_Star(intimidationZone, 0, 0, 2, 2);
    int expectedResults[] = {0, 1, 2, 5, 8};
    bool incorrect = false;
    for(int i = 0; i < *results->getLength();i++) {
        int num = results->get(i)->getData()->getId();
        if (num != expectedResults[i]) {
            incorrect = false;
            break;
        }
    }
    EXPECT_TRUE(!incorrect);
}




int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

