//
// Created by valva on 5/3/2019.
//

#ifndef GLADIATORS_GBP_GA_H
#define GLADIATORS_GBP_GA_H

#define POP_SIZE 40
#define FITTEST_SIZE 20

#include "Gladiator.h"

class GA {
private:
    Gladiator population [POP_SIZE];
    Gladiator fittest [FITTEST_SIZE];
    Gladiator newborns [FITTEST_SIZE];
    int generation;
    RNG rng;

public:
    GA();

    void generateInitPop();

    void calculateFitness();

    void swap(Gladiator *a,Gladiator *b);
    int partition(int low, int high);
    void quickSort(int low, int high);

    void selection();

    Gladiator crossover(Gladiator parent_1,Gladiator parent_2);
    void reproduction();

    void generationChange();

    void printPopResistance();
    void printPopFitness();
    void printFittest();

    int getGeneration();
    void setGeneration(int generation);

    Gladiator getStrongest();
};


#endif //GLADIATORS_GBP_GA_H

