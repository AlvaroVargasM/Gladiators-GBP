//
// Created by valva on 5/2/2019.
//

#pragma once

#include <string>

#include "RNG.h"

class Gladiator {
private:
    std::string ID;
    int age;
    int emotional_Intelligence;
    int physical_Condition;
    int upper_Body_Strength;
    int lower_Body_Strength;
    int resistance;

    int fitness;

public:
    Gladiator();

    Gladiator(int type);

    const std::string &getId();

    void setId(std::string &id);

    int getAge();

    void setAge(int age);

    int getEmotionalIntelligence();

    void setEmotionalIntelligence(int emotionalIntelligence);

    int getPhysicalCondition();

    void setPhysicalCondition(int physicalCondition);

    int getUpperBodyStrength();

    void setUpperBodyStrength(int upperBodyStrength);

    int getLowerBodyStrength();

    void setLowerBodyStrength(int lowerBodyStrength);

    int getResistance();

    void setResistance(int resistance);

    int calculateResistance();

    int getFitness();

    void setFitness(int fitness);
};