//
// Created by valva on 5/2/2019.
//

#pragma once

#include <string>
#include "RNG.h"
#define WEAK_RANGE 4
#define NORMAL_RANGE 7
#define STRONG_RANGE 10

/**
 * Gladiator class used for the GA and to be tested in a route giveng by a path finding algorithm
 */
class Gladiator {
private:
    /**
     * Gladiator ID
     */
    std::string ID;

    /**
     * Gladiator age
     */
    int age;

    /**
     * Gladiator emotional intelligence
     */
    int emotional_Intelligence;

    /**
     * Gladiator physical condition
     */
    int physical_Condition;

    /**
     * Gladiator upper body strength
     */
    int upper_Body_Strength;

    /**
     * Gladiator lower body strength
     */
    int lower_Body_Strength;

    /**
     * Gladiator resistance, calculated by the sum of emotional intelligence, physical condition and upper and lower
     * body strength
     */
    int resistance;

    /**
     * Fitness of the gladiator used for the genetic algorithm
     */
    int fitness;

public:
    /**
     * Default constructor
     */
    Gladiator();

    /**
     * Constructor that creates the gladiator depending on the passed value
     * @param type of gladiator to create
     */
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