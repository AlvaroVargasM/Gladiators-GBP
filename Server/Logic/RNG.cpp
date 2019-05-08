//
// Created by alvar on 05/05/19.
//

#include "RNG.h"

int RNG::getRandomNumber(int first_Number,int max_Range) {

    int random = (std::rand() % max_Range) + first_Number;

    return random;
}
