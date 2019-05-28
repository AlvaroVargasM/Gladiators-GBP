//
// Created by alvar on 27/05/19.
//

#include "../Logic/GA.h"
#include <gtest/gtest.h>

GA* genetic_Algorithm = new GA;
int lr = genetic_Algorithm->getPopulation()[0].getResistance();
int sr = genetic_Algorithm->getPopulation()[POP_SIZE].getResistance();
int nr = genetic_Algorithm->getPopulation()[POP_SIZE / 2].getResistance();

TEST(genetic_Algorithm,initialChampIsBest) {
    bool isBest = true;
    Gladiator champ = genetic_Algorithm->getStrongest();

    for (int i = 0;i < POP_SIZE;i++)
        if (genetic_Algorithm->getPopulation()[i].getResistance() <= champ.getResistance())
            continue;
        else
            isBest = false;

    EXPECT_TRUE(isBest);
}

TEST(genetic_Algorithm,quicksortWorks) {
    bool isWorking = true;

    for (int i = 1;i < POP_SIZE - 1;i++) {
        int y = i + 1;

        if (genetic_Algorithm->getPopulation()[i].getResistance() <= genetic_Algorithm->getPopulation()[y].getResistance())
            continue;
        else
            isWorking = false;
    }

    EXPECT_TRUE(isWorking);
}

TEST(genetic_Algorithm,initialPopulationWeakestResistance) {
    EXPECT_TRUE(lr >= 5);
}

TEST(genetic_Algorithm,initialPopulationNormalResistance) {
    EXPECT_TRUE(nr >= 10);
}

TEST(genetic_Algorithm,initialPopulationStrongestResistance) {
    EXPECT_TRUE(sr <= (STRONG_RANGE * 5));
    genetic_Algorithm->newGen();
}

TEST(genetic_Algorithm,newQuicksortWorks) {
    bool isWorking = true;

    for (int i = 1;i < POP_SIZE - 1;i++) {
        int y = i + 1;

        if (genetic_Algorithm->getPopulation()[i].getResistance() <= genetic_Algorithm->getPopulation()[y].getResistance())
            continue;
        else
            isWorking = false;
    }

    EXPECT_TRUE(isWorking);
}

TEST(genetic_Algorithm,newChampIsBest) {
    bool isBest = true;
    Gladiator champ = genetic_Algorithm->getStrongest();

    for (int i = 0;i < POP_SIZE;i++)
        if (genetic_Algorithm->getPopulation()[i].getResistance() <= champ.getResistance())
            continue;
        else
            isBest = false;

    EXPECT_TRUE(isBest);
}

TEST(genetic_Algorithm,weakPopChange) {
    int nlr = genetic_Algorithm->getPopulation()[0].getResistance();
    EXPECT_TRUE(lr >= nlr) << nlr << " is not major or equal than " << lr;
}

TEST(genetic_Algorithm,strongPopChange) {
    int nsr = genetic_Algorithm->getPopulation()[POP_SIZE].getResistance();
    EXPECT_TRUE(nsr >= sr);
}

TEST(genetic_Algorithm,normalPopChange) {
    int nnr = genetic_Algorithm->getPopulation()[POP_SIZE / 2].getResistance();
    EXPECT_TRUE(nnr >= nr);
    delete genetic_Algorithm;
}

