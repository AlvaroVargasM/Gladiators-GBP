//
// Created by valva on 5/3/2019.
//

#ifndef GLADIATORS_GBP_GA_H
#define GLADIATORS_GBP_GA_H

#define POP_SIZE 100
#define FITTEST_SIZE 20

#include "Gladiator.h"

class GA {
private:
    Gladiator population [POP_SIZE];
    Gladiator fittest [FITTEST_SIZE];
    Gladiator newborns [FITTEST_SIZE];
    int generation;

public:
    void generateInitPop(); // Se va a gnerar la pop inicial

    void calculateFitness(); // Calcula el fitness de la pop(o de los individuos que aun no se hayan calculado), acomoda el array deacuerdo al fitness
    void selection(); // Toma los 20 mejores de del array y los mete en el arraay fittest

    Gladiator crossover(Gladiator parent_1,Gladiator parent_2); // Toma de par en par los individuos de fittest y crea dos hijos de cada par, aca mismo ocurre la mutacion e inversion, los hijos son puestos en newborns
    void generationChange(); // Toma los newborns y remplaza los ultimos 20 de la ploblacion, se aumenta la generacion
};


#endif //GLADIATORS_GBP_GA_H
