//
// Created by valva on 5/3/2019.
//

#include "GA.h"

void GA::generateInitPop() {
    /*
     * Fill the pop array with new gladiators created randomly by setting probabilities to create different types of
     * gladiators, for example a 60% chance to form a medium type gladiator, 20% for a weak and 20% for a strong one
     */
}

void GA::calculateFitness() {
    /*
     * Goes by each individual in the pop and calculates their fitness, in the case that their fitness hasn't been
     * calculated yet, it also organizes the pop in order of fitness, from best to worse
     */
}

void GA::selection() {
    /*
     * Takes the top 20% of indiviuals of the pop and puts them on the fittest array
     */
}

Gladiator GA::crossover(Gladiator parent_1,Gladiator parent_2) {
    /*
     * Takes a pair of gladiators to create a new unique gladiator form there genes, applies mutation and inversion to
     * the new gladiator and then puts it in the newborns array
     */
    return Gladiator();
}

void GA::generationChange() {
    /*
     * Takes the newborns and puts them in the pop by replacing the worse individuals, empties the fittest and newborns
     * arrays
     */
}
