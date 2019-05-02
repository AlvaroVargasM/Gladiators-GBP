//
// Created by valva on 5/2/2019.
//

#include "Gladiator.h"

Gladiator::Gladiator() {

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
