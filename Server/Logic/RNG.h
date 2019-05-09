//
// Created by alvar on 05/05/19.
//

#pragma once

#include <cstdlib>
#include <time.h>
#include <iostream>

/**
 * Random number generator class, it is used for the generation of random integers
 */
class RNG {
public:
    /**
     * RNG default constructor
     */
    RNG() = default;

    /**
     * Method for creating a random integer from a given range
     * @param minimun_Number minimum number to generate
     * @param max_Range maximum number to generate
     * @return an int created from 0 to the max_range + the minimum number
     */
    int getRandomNumber(int minimun_Number, int max_Range);
};