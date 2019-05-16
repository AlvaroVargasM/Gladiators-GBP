//
// Created by valva on 5/2/2019.
//

#include "Gladiator.h"
#include <iostream>

/**
 * Default constructor
 */
Gladiator::Gladiator() {}

/**
 * Constructor that creates the gladiator depending on the passed value
 * @param type of gladiator to create
 */
Gladiator::Gladiator(int type) {
    RNG rng;

    // Weak Glad.
    if (type <= 20) {
        int r1 = rng.getRandomNumber(1,WEAK_RANGE);
        int r2 = rng.getRandomNumber(1,WEAK_RANGE);
        int r3 = rng.getRandomNumber(1,WEAK_RANGE);
        int r4 = rng.getRandomNumber(1,WEAK_RANGE);

        this->emotional_Intelligence = r1;
        this->physical_Condition = r2;
        this->upper_Body_Strength = r3;
        this->lower_Body_Strength = r4;

        this->resistance = calculateResistance();

        this->age = 21;
    }
    // Normal Glad.
    if (20 < type && type < 80) {
        int r1 = rng.getRandomNumber(1,NORMAL_RANGE);
        int r2 = rng.getRandomNumber(1,NORMAL_RANGE);
        int r3 = rng.getRandomNumber(1,NORMAL_RANGE);
        int r4 = rng.getRandomNumber(1,NORMAL_RANGE);

        this->emotional_Intelligence = r1;
        this->physical_Condition = r2;
        this->upper_Body_Strength = r4;
        this->lower_Body_Strength = r3;

        this->resistance = calculateResistance();

        this->age = 22;
    }
    // Strong Glad.
    if (type >= 80) {
        int r1 = rng.getRandomNumber(1,STRONG_RANGE);
        int r2 = rng.getRandomNumber(1,STRONG_RANGE);
        int r3 = rng.getRandomNumber(1,STRONG_RANGE);
        int r4 = rng.getRandomNumber(1,STRONG_RANGE);

        this->emotional_Intelligence = r1;
        this->physical_Condition = r2;
        this->upper_Body_Strength = r4;
        this->lower_Body_Strength = r3;

        this->resistance = calculateResistance();

        this->age = 23;
    }
    this->fitness = 0;
}

const std::string &Gladiator::getId() {
    return this->ID;
}

void Gladiator::setId(std::string &id) {
    this->ID = id;
}

int Gladiator::getAge() {
    return this->age;
}

void Gladiator::setAge(int age) {
    this->age = age;
}

int Gladiator::getEmotionalIntelligence() {
    return this->emotional_Intelligence;
}

void Gladiator::setEmotionalIntelligence(int emotionalIntelligence) {
    this->emotional_Intelligence = emotionalIntelligence;
}

int Gladiator::getPhysicalCondition() {
    return this->physical_Condition;
}

void Gladiator::setPhysicalCondition(int physicalCondition) {
    this->physical_Condition = physicalCondition;
}

int Gladiator::getUpperBodyStrength() {
    return this->upper_Body_Strength;
}

void Gladiator::setUpperBodyStrength(int upperBodyStrength) {
    this->upper_Body_Strength = upperBodyStrength;
}

int Gladiator::getLowerBodyStrength() {
    return this->lower_Body_Strength;
}

void Gladiator::setLowerBodyStrength(int lowerBodyStrength) {
    this->lower_Body_Strength = lowerBodyStrength;
}

int Gladiator::getResistance() {
    return this->resistance;
}

void Gladiator::setResistance(int resistance) {
    this->resistance = resistance;
}

int Gladiator::getFitness() {
    return this->fitness;
}

void Gladiator::setFitness(int fitness) {
    this->fitness = fitness;
}

int Gladiator::calculateResistance() {
    int res = getEmotionalIntelligence() + getPhysicalCondition() + getUpperBodyStrength() + getLowerBodyStrength();
    return res;
}