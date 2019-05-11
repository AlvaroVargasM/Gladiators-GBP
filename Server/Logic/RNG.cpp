//
// Created by alvar on 05/05/19.
//

#include "RNG.h"

/**
 * Method for creating a random integer from a given range
 * @param minimun_Number minimum number to generate
 * @param max_Range maximum number to generate
 * @return an int created from 0 to the max_range + the minimum number
 */
int RNG::getRandomNumber(int minimun_Number, int max_Range) {
    int random = (std::rand() % max_Range) + minimun_Number;
    return random;
}
