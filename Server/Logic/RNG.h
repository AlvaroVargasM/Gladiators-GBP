//
// Created by alvar on 05/05/19.
//

#ifndef GA_RNG_H
#define GA_RNG_H

#include <cstdlib>
#include <time.h>
#include <iostream>

class RNG {
public:
    RNG() = default;
    int getRandomNumber(int first_Number,int max_Range);
};


#endif //GA_RNG_H
