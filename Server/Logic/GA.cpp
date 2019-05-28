//
// Created by valva on 5/3/2019.
//

#include "GA.h"

/**
 * Constructs the GA and its first generation
 */
GA::GA() {
    this->generation = 1;
    this->generateInitPop();
    this->calculateFitness();
    this->quickSort(0,POP_SIZE);
}

/**
 * Fill the pop array with new gladiators created randomly by setting probabilities to create different types of
 * gladiators, for example a 60% chance to form a medium type gladiator, 20% for a weak and 20% for a strong one, the %
 * are in the gladiator constructor.
 */
void GA::generateInitPop() {
    this->population[0] = Gladiator(this->rng.getRandomNumber(1, 100));
    for (int i = 1; i < POP_SIZE + 1; i++)
        this->population[i] = Gladiator(this->rng.getRandomNumber(1, 100));
}

/**
 * Goes by each individual in the pop and calculates their fitness, in the case that their fitness hasn't been
 * calculated yet
 */
void GA::calculateFitness() {
    for (int i = 0;i < POP_SIZE;i++)
        this->population[i].setFitness(this->population[i].getResistance());
}

/**
 * Takes two gladiator pointers and swaps them, this method is used for the sorting of the population
 * @param a gladiator to swap for b
 * @param b gladiator to swap for a
 */
void GA::swap(Gladiator* a,Gladiator* b) {
    Gladiator t = *a;
    *a = *b;
    *b = t;
}

/**
 * Method for partitioning the population, used in the sorting of the population
 * @param low first element of the pop
 * @param high last element of the pop
 * @return index for the partition
 */
int GA::partition(int low, int high) {
    Gladiator pivot = this->population[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low;j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (this->population[j].getFitness() <= pivot.getFitness())
        {
            i++;    // increment index of smaller element
            swap(&this->population[i], &this->population[j]);
        }
    }
    swap(&this->population[i + 1], &this->population[high]);
    return (i + 1);
}

/**
 * Quick sort algorithm for sorting the pop by smallest to biggest fitness
 * @param low first element of the pop
 * @param high last element of the pop
 */
void GA::quickSort(int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

/**
 * Takes a pair of gladiators to create a new unique gladiator from their genes, applies mutation and inversion to
 * the new gladiator
 * @param parent_1 first gladiator to cross
 * @param parent_2 second gladiator to cross
 * @return a new gladiator based on the cross of the attributes of the gladiators passed
 */
Gladiator GA::crossover(Gladiator parent_1,Gladiator parent_2) {
    Gladiator child;

    if (parent_1.getAge() > parent_2.getAge())
        child.setAge(parent_1.getAge() + 1);
    if (parent_1.getAge() == parent_2.getAge())
        child.setAge(parent_1.getAge() + 1);
    if (parent_1.getAge() < parent_2.getAge())
        child.setAge(parent_2.getAge() + 1);

    std::bitset<BIT_SET_SIZE> p1_EI (parent_1.getEmotionalIntelligence());
    std::bitset<BIT_SET_SIZE> p2_EI (parent_2.getEmotionalIntelligence());

    std::bitset<BIT_SET_SIZE> p1_PC = (parent_1.getPhysicalCondition());
    std::bitset<BIT_SET_SIZE> p2_PC = (parent_2.getPhysicalCondition());

    std::bitset<BIT_SET_SIZE> p1_UBS = (parent_1.getUpperBodyStrength());
    std::bitset<BIT_SET_SIZE> p2_UBS = (parent_2.getUpperBodyStrength());

    std::bitset<BIT_SET_SIZE> p1_LBS = (parent_1.getLowerBodyStrength());
    std::bitset<BIT_SET_SIZE> p2_LBS = (parent_2.getLowerBodyStrength());

    int ei = (int)bitCrossover(p1_EI,p2_EI).to_ulong();
    child.setEmotionalIntelligence(ei);

    int pc = (int)bitCrossover(p1_PC,p2_PC).to_ulong();
    child.setPhysicalCondition(pc);

    int ubs = (int)bitCrossover(p1_UBS,p2_UBS).to_ulong();
    child.setUpperBodyStrength(ubs);

    int lbs = (int)bitCrossover(p1_LBS,p2_LBS).to_ulong();
    child.setLowerBodyStrength(lbs);

    child.setResistance(child.calculateResistance());

    std::bitset<BIT_SET_SIZE> res (child.getResistance());

    int mut = rng.getRandomNumber(1,100);

    if (mut < INVERSION_PORCENTAGE)
        res = bitInversion(res);

    child.setResistance((int)res.to_ulong());
    child.setFitness((int)res.to_ulong());

    return child;
}

/**
 * Takes two bit sets and combines them to create a new one
 * @param parent_1 first bit set
 * @param parent_2 second bit set
 * @return the combination of both bit sets
 */
std::bitset<BIT_SET_SIZE> GA::bitCrossover(std::bitset<BIT_SET_SIZE> parent_1, std::bitset<BIT_SET_SIZE> parent_2) {
    std::bitset<BIT_SET_SIZE> child;
    int gene_Probability = BEST_GENE_SURVIVABILITY;

    for (int i = 0;i < BIT_SET_SIZE;i++){
        int x = this->rng.getRandomNumber(1,100);

        bool p1 = parent_1[i];
        bool p2 = parent_2[i];

        if (p1 == p2)
            child[i] = p1;

        if (p1)
            if (x < gene_Probability)
                child[i] = p1;
            else
                child[i] = p2;
        else
        if (x < gene_Probability)
            child[i] = p2;
        else
            child[i] = p1;
    }
    std::bitset<BIT_SET_SIZE> m_Child = bitMutation(child);

    return m_Child;
}

/**
 * Takes a bit set an changes one of its bit to true
 * @param child bit set to modify
 * @return new modified bit
 */
std::bitset<BIT_SET_SIZE> GA::bitMutation(std::bitset<BIT_SET_SIZE> child) {
    int x = this->rng.getRandomNumber(1,100);

    if (x < MUTATION_PORCENTAGE) {
        int i = 0;
        while (child[i] == true) {
            child[i] = false;
            ++i;
        }
        child[i] = true;
    }
    return child;
}

/**
 * Takes a bit set and inverts all of its bits
 * @param child bit set to invert
 * @return inverted bit set
 */
std::bitset<BIT_SET_SIZE> GA::bitInversion(std::bitset<BIT_SET_SIZE> child) {
    int i = 0;

    while (i < 8) {
        if (child[i] == true)
            child[i] = false;
        else
            child[i] = true;
        i++;
    }

    return child;
}

/**
 * Takes each pair in the fittest and makes two new gladiator from the pair, then puts th new pair of gladiators in the
 * population replacing the worse gladiators, by doing that a new generation is created.
 */
void GA::reproduction() {
    int x = POP_SIZE - 1;
    int y = POP_SIZE - FITTEST_SIZE - 1;
    int z = FITTEST_SIZE - 1;
    for (int i = 0;i < (FITTEST_SIZE / 2);i++) {

        // Takes two parents from fittest
        Gladiator parent_1 = this->population[x];
        Gladiator parent_2 = this->population[y];

        x--;
        y++;

        // Creates two new gladiators from the parents
        Gladiator newGladiator1 = crossover(parent_1,parent_2);
        Gladiator newGladiator2 = crossover(parent_1,parent_2);

        // Adds the new gladiators to the newborns
        this->newborns[i] = newGladiator1;
        this->newborns[z] = newGladiator2;
        z--;
    }
}

/**
 * Takes the newborns and puts them in the pop by replacing the worse individuals
 */
void GA::generationChange() {
    for (int i = 0;i < FITTEST_SIZE;i++)
        this->population[i] = this->newborns[i];

    this->generation++;
}

/**
 * Return the strongest gladiator from the population
 * @return strongest gladiator
 */
Gladiator GA::getStrongest() {
    return this->population[POP_SIZE - 1];
}

/**
 * Creates a new generation of the population by selecting the best individuals, applies reproduction at them, their
 * children replace te worst individuals of the pop, the pop is then sorted by their fitness
 */
void GA::newGen() {
    reproduction();
    generationChange();
    calculateFitness();
    quickSort(0,POP_SIZE);
}

int GA::getGeneration() {
    return this->generation;
}

/**
 * Prints the each individual of the pop resistance to console
 */
void GA::printPopResistance() {
    for(int i = 0; i < POP_SIZE;i++)
        std::cout << this->population[i].getResistance() << " / ";
    std::cout << std::endl;
}

/**
 * Gives back the average resistance of the current pop
 * @return average resistance
 */
int GA::averageResistance() {
    int res = 0;
    for (int i = 0;i < POP_SIZE;i++) {
        res += this->population[i].getResistance();
    }
    return res / POP_SIZE;
}

/**
 * Gives back the average emotional intelligence of the current pop
 * @return average emotional intelligence
 */
int GA::averageEmotionalIntelligence() {
    int aei = 0;
    for (int i = 0;i < POP_SIZE;i++) {
        aei += this->population[i].getEmotionalIntelligence();
    }
    return aei / POP_SIZE;
}

/**
 * Gives back the average physical condition of the current pop
 * @return average physical condition
 */
int GA::averagePhysicalCondition() {
    int apc = 0;
    for (int i = 0;i < POP_SIZE;i++) {
        int y = this->population[i].getPhysicalCondition();
        apc += this->population[i].getPhysicalCondition();
    }
    return apc / POP_SIZE;
}

/**
 * Gives back the average upper body strength of the current pop
 * @return average upper body strength
 */
int GA::averageUpperBodyStrength() {
    int aubs = 0;
    for (int i = 0;i < POP_SIZE;i++) {
        int y = this->population[i].getUpperBodyStrength();
        aubs += this->population[i].getUpperBodyStrength();
    }
    return aubs / POP_SIZE;
}

/**
 * Gives back the average lower body strength of the current pop
 * @return average lower body strength
 */
int GA::averageLowerBodyStrength() {
    int albs = 0;
    for (int i = 0;i < POP_SIZE;i++) {
        albs += this->population[i].getLowerBodyStrength();
    }
    return albs / POP_SIZE;
}

/**
 * Prints a set of generations
 * @param n_gens amount of generations to print
 */
void GA::printGenerations(int n_gens) {
    for (int i = 0;i < n_gens;i++) {
        std::cout << "\n\n GEN " << this->getGeneration() << " RESISTANCE: " << std::endl;
        this->printPopResistance();
        std::cout << std::setw(4) << "CHAMPION: " << this->getStrongest().getResistance() << std::endl;
        std::cout << std::setw(4) << "Average res: " << this->averageResistance() << std::endl;
        std::cout << std::setw(4) << "Average ei: " << this->averageEmotionalIntelligence() << std::endl;
        std::cout << std::setw(4) << "Average pc: " << this->averagePhysicalCondition() << std::endl; // ERROR on pool B
        std::cout << std::setw(4) << "Average ubs: " << this->averageUpperBodyStrength() << std::endl; // ERROR on pool B
        std::cout << std::setw(4) << "Average lbs: " << this->averageLowerBodyStrength() << std::endl;
        this->newGen();
    }
}

Gladiator *GA::getPopulation() {
    return population;
}