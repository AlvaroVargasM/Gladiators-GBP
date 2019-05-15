//
// Created by valva on 5/3/2019.
//

#pragma once

#define POP_SIZE 20
#define FITTEST_SIZE 20
#define BIT_SET_SIZE 11
#define BEST_GENE_SURVIVABILITY 70
#define MUTATION_PORCENTAGE 25
#define INVERSION_PORCENTAGE 5

#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
#include "Gladiator.h"

/**
 * Genetic Algorithm class, works on a population of gladiators to simulate the theories of natural selection and
 * evolution
 */
class GA {
private:
    /**
     * The main pool of gladiators to be analyzed and used by by the GA
     */
    Gladiator population [POP_SIZE];

    /**
     * An array of gladiators used to store the best individuals of the pop
     */
    Gladiator fittest [FITTEST_SIZE];

    /**
     * An array of gladiators used to store the children of the fittest
     */
    Gladiator newborns [FITTEST_SIZE];

    /**
     * Integer for maintaining a amount of generations created
     */
    int generation;

    /**
     * RNG object to be used to create random numbers
     */
    RNG rng;


    /**
     * Fill the pop array with new gladiators created randomly by setting probabilities to create different types of
     * gladiators, for example a 60% chance to form a medium type gladiator, 20% for a weak and 20% for a strong one, the %
     * are in the gladiator constructor.
     */
    void generateInitPop();

    /**
     * Goes by each individual in the pop and calculates their fitness, in the case that their fitness hasn't been
     * calculated yet
     */
    void calculateFitness();

    /**
     * Takes two gladiator pointers and swaps them, this method is used for the sorting of the population
     * @param a gladiator to swap for b
     * @param b gladiator to swap for a
     */
    void swap(Gladiator *a,Gladiator *b);

    /**
     * Method for partitioning the population, used in the sorting of the population
     * @param low first element of the pop
     * @param high last element of the pop
     * @return index for the partition
     */
    int partition(int low, int high);

    /**
     * Method for partitioning the population, used in the sorting of the population
     * @param low first element of the pop
     * @param high last element of the pop
     * @return index for the partition
     */
    void quickSort(int low, int high);

    /**
     * Takes the top 20% of individuals of the pop and puts them on the fittest array, it assumens that the pop has already
     * been sorted and the fist 20 are the best of the population.
     */
    void selection();

    /**
     * Takes a pair of gladiators to create a new unique gladiator from their genes, applies mutation and inversion to
     * the new gladiator
     * @param parent_1 first gladiator to cross
     * @param parent_2 second gladiator to cross
     * @return a new gladiator based on the cross of the attributes of the gladiators passed
     */
    Gladiator crossover(Gladiator parent_1,Gladiator parent_2);

    /**
     * Takes two bit sets and combines them to create a new one
     * @param parent_1 first bit set
     * @param parent_2 second bit set
     * @return the combination of both bit sets
     */
    std::bitset<BIT_SET_SIZE> bitCrossover(std::bitset<BIT_SET_SIZE> parent_1,std::bitset<BIT_SET_SIZE> parent_2);

    /**
     * Takes a bit set an changes one of its bit to true
     * @param child bit set to modify
     * @return new modified bit
     */
    std::bitset<BIT_SET_SIZE> bitMutation(std::bitset<BIT_SET_SIZE> child);

    /**
     * Takes a bit set and inverts all of its bits
     * @param child bit set to invert
     * @return inverted bit set
     */
    std::bitset<BIT_SET_SIZE> bitInversion(std::bitset<BIT_SET_SIZE> child);

    /**
     * Takes each pair in the fittest and makes two new gladiator from the pair, then puts th new pair of gladiators in the
     * population replacing the worse gladiators, by doing that a new generation is created.
     */
    void reproduction();

    /**
     * Takes the newborns and puts them in the pop by replacing the worse individuals
     */
    void generationChange();


public:
    /**
     * Constructs the GA and its first generation
     */
    GA();

    /**
     * Return the strongest gladiator from the population
     * @return strongest gladiator
     */
    Gladiator getStrongest();

    /**
     * Creates a new generation of the population by selecting the best individuals, applies reproduction at them, their
     * children replace te worst individuals of the pop, the pop is then sorted by their fitness
     */
    void newGen();

    /**
     * Gives the number of generation the GA is currently in
     * @return generation number
     */
    int getGeneration();

    /**
     * Gives back the average resistance of the current pop
     * @return average resistance
     */
    int averageResistance();

    /**
     * Gives back the average emotional intelligence of the current pop
     * @return average emotional intelligence
     */
    int averageEmotionalIntelligence();

    /**
     * Gives back the average physical condition of the current pop
     * @return average physical condition
     */
    int averagePhysicalCondition();

    /**
     * Gives back the average upper body strength of the current pop
     * @return average upper body strength
     */
    int averageUpperBodyStrength();

    /**
     * Gives back the average lower body strength of the current pop
     * @return average lower body strength
     */
    int averageLowerBodyStrength();

    /**
     * Prints the each individual of the pop resistance to console
     */
    void printPopResistance();

    /**
     * Prints the each individual of the pop fitness to console
     */
    void printPopFitness();

    /**
     * Prints the each individual of the fitness list to console
     */
    void printFittest();

    void printGenerations(int n_gens);

    Gladiator *getPopulation();
};