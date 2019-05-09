//
// Created by alvar on 11/04/19.
//

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Logic/Gladiator.h"
#include "Logic/GA.h"
#include "Logic/RNG.h"

#include "Logic/IntimidationZone.h"

int main () {
    IntimidationZone* intimidationZone = new IntimidationZone(2, 2);

    srand(time(nullptr));

    GA genetic;

    genetic.generateInitPop();
    std::cout << "\nInitial POP:\n";
    genetic.printPopResistance();

    for (int i = 0;i < 5;i++) {
        std::cout << "GENERATION: " << genetic.getGeneration() << "\n\n\n";
        genetic.calculateFitness();
        std::cout << "\nCalculating fitness of POP:\n";
        genetic.printPopFitness();

        genetic.quickSort(0, POP_SIZE);
        std::cout << "\nSorting POP by fitness:\n";
        genetic.printPopFitness();

        genetic.selection();
        std::cout << "\nSelection:\n";
        genetic.printFittest();

        genetic.reproduction();
        genetic.generationChange();
        std::cout << "\nPOP after reproduction and generation change:\n";
        genetic.printPopFitness();
    }

    return 0;

}
