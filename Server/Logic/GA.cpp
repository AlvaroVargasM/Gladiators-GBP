//
// Created by valva on 5/3/2019.
//

#include "GA.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

GA::GA() {
    this->generation = 1;
}


/**
 * Fill the pop array with new gladiators created randomly by setting probabilities to create different types of
 * gladiators, for example a 60% chance to form a medium type gladiator, 20% for a weak and 20% for a strong one, the %
 * are in the gladiator constructor.
 */
void GA::generateInitPop() {
    for (int i = 0; i < POP_SIZE; i++)
        this->population[i] = Gladiator(this->rng.getRandomNumber(1, 100));
}

/**
 * Goes by each individual in the pop and calculates their fitness, in the case that their fitness hasn't been
 * calculated yet
 */
void GA::calculateFitness() {
    for (int i = 0;i < POP_SIZE;i++)
        this->population[i].setFitness(this->population[i].getResistance());
}

void GA::swap(Gladiator* a,Gladiator* b) {
    Gladiator t = *a;
    *a = *b;
    *b = t;
}

int GA::partition(int low, int high) {
    Gladiator pivot = this->population[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low;j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (this->population[j].getFitness() <= pivot.getFitness())
        {
            i++;    // increment index of smaller element
            swap(&this->population[i], &this->population[j]);
        }
    }
    swap(&this->population[i + 1], &this->population[high]);
    return (i + 1);
}

void GA::quickSort(int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

/**
 * Takes the top 20% of individuals of the pop and puts them on the fittest array, it assumens that the pop has already
 * been sorted and the fist 20 are the best of the population.
 */
void GA::selection() {
    int x = POP_SIZE - 1;
    for (int i = 0;i < FITTEST_SIZE;i++) {
        this->fittest[i] = this->population[x];
        --x;
    }
}

/**
 * Takes a pair of gladiators to create a new unique gladiator from their genes, applies mutation and inversion to
 * the new gladiator
 */
Gladiator GA::crossover(Gladiator parent_1,Gladiator parent_2) {
    int p1_EI = parent_1.getEmotionalIntelligence();
    int p2_EI = parent_2.getEmotionalIntelligence();

    int p1_PC = parent_1.getPhysicalCondition();
    int p2_PC = parent_2.getPhysicalCondition();

    int p1_UBS = parent_1.getUpperBodyStrength();
    int p2_UBS = parent_2.getUpperBodyStrength();

    int p1_LBS = parent_1.getLowerBodyStrength();
    int p2_LBS = parent_2.getLowerBodyStrength();

    Gladiator child;
    child.setAge((parent_1.getAge() + parent_2.getAge())/2 + this->rng.getRandomNumber(1,5));

    // Setting the child EI based on its parents
    if (p1_EI > p2_EI)
        child.setEmotionalIntelligence(this->rng.getRandomNumber(p2_EI,p1_EI) - p2_EI/2);
    if (p1_EI == p2_EI)
        child.setEmotionalIntelligence(p1_EI);
    if (p1_EI < p2_EI)
        child.setEmotionalIntelligence(this->rng.getRandomNumber(p1_EI,p2_EI) - p1_EI/2);

    // Setting the child PC based on its parents
    if (p1_PC > p2_PC)
        child.setPhysicalCondition(this->rng.getRandomNumber(p2_PC,p1_PC) - p2_PC/2);
    if (p1_PC == p2_PC)
        child.setPhysicalCondition(p1_PC);
    if (p1_PC < p2_PC)
        child.setPhysicalCondition(this->rng.getRandomNumber(p1_PC,p2_PC) - p1_PC/2);

    // Setting the child UBS based on its parents
    if (p1_UBS > p2_UBS)
        child.setUpperBodyStrength(this->rng.getRandomNumber(p2_UBS,p1_UBS) - p2_UBS/2);
    if (p1_UBS == p2_UBS)
        child.setUpperBodyStrength(p1_UBS);
    if (p1_UBS < p2_UBS)
        child.setUpperBodyStrength(this->rng.getRandomNumber(p1_UBS,p2_UBS) - p1_UBS/2);

    // Setting the child LBS based on its parents
    if (p1_LBS > p2_LBS)
        child.setLowerBodyStrength(this->rng.getRandomNumber(p2_LBS,p1_LBS) - p2_LBS/2);
    if (p1_LBS == p2_LBS)
        child.setLowerBodyStrength(p1_LBS);
    if (p1_LBS < p2_LBS)
        child.setLowerBodyStrength(this->rng.getRandomNumber(p1_LBS,p2_LBS) - p1_LBS/2);

    child.setResistance(child.calculateResistance());

    child.setFitness(child.getResistance());

    int mut = this->rng.getRandomNumber(1,100);

    if (mut <= 5) {
        int z = this->rng.getRandomNumber(1,2);
        if (z == 1)
            child.setResistance(child.getResistance() * 2);
        else
            child.setResistance(child.getResistance() / 2);
    }

    //std::cout << "CHILD: " << child.getFitness() << std::endl;

    return child;
}

/**
 * Takes each pair in the fittest and makes two new gladiator from the pair, then puts th new pair of gladiators in the
 * population replacing the worse gladiators, by doing that a new generation is created.
 */
void GA::reproduction() {
    int x = FITTEST_SIZE - 1;
    for (int i = 0;i < (FITTEST_SIZE / 2);i++) {

        // Takes two parents from fittest
        Gladiator parent_1 = this->fittest[i];
        Gladiator parent_2 = this->fittest[-x];

        // Creates two new gladiators from the parents
        Gladiator newGladiator1 = crossover(parent_1,parent_2);
        Gladiator newGladiator2 = crossover(parent_1,parent_2);

        // Adds the new gladiators to the newborns
        this->newborns[i] = newGladiator1;
        this->newborns[x] = newGladiator2;
        --x;
    }
}

/**
 * Takes the newborns and puts them in the pop by replacing the worse individuals
 */
void GA::generationChange() {
    for (int i = 0;i < FITTEST_SIZE;i++)
        this->population[i] = this->newborns[i];
    this->generation++;
}

/**
 * Prints the each individual of the pop resistance to console
 */
void GA::printPopResistance() {
    for(int i = 0; i < POP_SIZE;i++)
        std::cout << this->population[i].getResistance() << " / ";
    std::cout << std::endl;
}

/**
 * Prints the each individual of the pop fitness to console
 */
void GA::printPopFitness() {
    for(int i = 0; i < POP_SIZE;i++)
        std::cout << this->population[i].getFitness() << " / ";
    std::cout << std::endl;
}

void GA::printFittest() {
    for(int i = 0; i < FITTEST_SIZE;i++)
        std::cout << this->fittest[i].getFitness() << " / ";
    std::cout << std::endl;
}

int GA::getGeneration() {
    return this->generation;
}

void GA::setGeneration(int generation) {
    this->generation = generation;
}

Gladiator GA::getStrongest() {
    return this->population[POP_SIZE - 1];
}