//
// Created by jondorito on 26/05/19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Logic/IntimidationZone.h"

#define N 10
#define M 10

IntimidationZone* intimidationZone = new IntimidationZone(N, M);

TEST(intimidationZone, GetZoneByID){
    Zone* zoneByXY = intimidationZone->getZone(5, 0);
    Zone* zoneByID = intimidationZone->getZoneByID(50);
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




int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

