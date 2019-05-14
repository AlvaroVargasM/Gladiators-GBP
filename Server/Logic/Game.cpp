//
// Created by alvar on 10/05/19.
//

#include "Game.h"

/**
 * Constructs the game class and initializes some of the members
 */
Game::Game() {
    this->n_Towers = 0;
    this->iteration = 1;
    this->averageGensRes = " ";
    this->averageGensEI = " ";
    this->averageGensPC = " ";
    this->averageGensStr = " ";
    saveGenStats();
}

/**
 * Generates three random towers in the game zones of random type
 */
void Game::generateTowers() {
    for (int x = 0;x < 3;x++) {
        int i = rng.getRandomNumber(0,N_ROWS);
        int j = rng.getRandomNumber(0,N_COLUMNS);
        int type = this->rng.getRandomNumber(1,3);

        if (!this->game_Zone->getZone(i, j)->isBlocked()) {
            putTower(i,j,type);
            n_Towers++;
            generateNewGUITower(i,j,type);
        } else --x;
    }
}

/**
 * Puts a single tower on the game zone, it marks the correct adjacents zones with the damage given by the tower's
 * arrows
 * @param i row of the tower
 * @param j column of the tower
 * @param type of tower
 */
void Game::putTower(int i, int j, int type) {
    int damage;
    switch (type) {
        case 1:
            damage = BASE_DAMAGE;
            break;
        case 2:
            damage = BASE_DAMAGE * 2;
            break;
        case 3:
            damage = BASE_DAMAGE * 4;
            break;
        default:
            damage = 0;
            break;
    }
    this->game_Zone->getZone(i,j)->setBlocked(true);

    GenericLinkedList<int>* ahhhhh = new GenericLinkedList<int>;
    ahhhhh->add(n_Towers);
    ahhhhh->add(damage);

    this->game_Zone->getZone(i,j)->getDamage()->add(ahhhhh);

    for(int x = 1;x < (type + 1);x++) {
        if (i - x >= 0 && !this->game_Zone->getZone(i - x,j)->isBlocked())
            this->game_Zone->getZone(i - x,j)->getDamage()->add(ahhhhh);

        if (i + x < N_ROWS && !this->game_Zone->getZone(i + x,j)->isBlocked())
            this->game_Zone->getZone(i + x,j)->getDamage()->add(ahhhhh);

        if (j - x >= 0 && !this->game_Zone->getZone(i,j - x)->isBlocked())
            this->game_Zone->getZone(i,j - x)->getDamage()->add(ahhhhh);

        if (j + x < N_COLUMNS && !this->game_Zone->getZone(i,j + x)->isBlocked())
            this->game_Zone->getZone(i,j + x)->getDamage()->add(ahhhhh);

        if (i - x >= 0 && j - x >= 0 && !this->game_Zone->getZone(i - x,j - x)->isBlocked())
            this->game_Zone->getZone(i - x,j - x)->getDamage()->add(ahhhhh);

        if (i - x >= 0 && j + x < N_COLUMNS && !this->game_Zone->getZone(i - x,j + x)->isBlocked())
            this->game_Zone->getZone(i - x,j + x)->getDamage()->add(ahhhhh);

        if (i + x < N_ROWS && j - x >= 0 && !this->game_Zone->getZone(i + x,j - x)->isBlocked())
            this->game_Zone->getZone(i + x,j - x)->getDamage()->add(ahhhhh);

        if (i + x < N_ROWS && j + x < N_COLUMNS && !this->game_Zone->getZone(i + x,j + x)->isBlocked())
            this->game_Zone->getZone(i + x,j + x)->getDamage()->add(ahhhhh);
    }
}

/**
 * Gets the best Gladiator from each pool and puts them in a linked list
 * @return linked list with the best gladiators from each pool
 */
std::string Game::getChampions() {
    this->path_A = *this->pths.findPathByA_Star(this->game_Zone,INI_I,INI_J,FIN_I,FIN_J);
    Gladiator champ_1 = this->pool_A.getStrongest();
    Gladiator champ_2 = this->pool_B.getStrongest();

    std::string champs = std::to_string(champ_1.getResistance()) + "," + std::to_string(champ_2.getResistance()) + "," +
            std::to_string(this->pool_A.getGeneration()) + "," + std::to_string(this->pool_B.getGeneration()) + "," +
            std::to_string(champ_1.getAge()) + "," + std::to_string(champ_2.getAge()) + "," +
            "0" + "," + "0" + "," +
            "0" + "," + "0" + "," +
            std::to_string(champ_1.getEmotionalIntelligence()) + "," + std::to_string(champ_2.getEmotionalIntelligence()) + "," +
            std::to_string(champ_1.getPhysicalCondition()) + "," + std::to_string(champ_2.getPhysicalCondition()) + "," +
            std::to_string(champ_1.getUpperBodyStrength()) + "," + std::to_string(champ_1.getLowerBodyStrength()) + "," +
            std::to_string(champ_2.getUpperBodyStrength()) + "," + std::to_string(champ_2.getLowerBodyStrength()) + "," +
            std::to_string(this->pths.getA_starTime()) + "0";
    return champs;
}

/**
 * Adds a new string to the linked list of new towers for the GUI using the info passed
 * @param type of tower
 * @param i row
 * @param j column
 */
void Game::generateNewGUITower(int i,int j,int type) {
    std::string stype;
    switch (type) {
        case 1:
            stype = "normal";
            break;
        case 2:
            stype = "fire";
            break;
        case 3:
            stype = "explosive";
            break;
        default:
            stype = "!117GAME";
    }
    this->new_GUI_Towers.add("create." + std::to_string(this->n_Towers) + "." + stype +"." + std::to_string(i) + "." + std::to_string(j));
}

/**
 * Returns the string command for creating towers in the GUI
 * @return GUI towers recently added
 */
GenericLinkedList<std::string> Game::getTowers() {
    generateTowers();
    return new_GUI_Towers;
}

/**
 * Gives a string with all the stats saved during the game
 * @return final stats
 */
std::string Game::getStats() {
    std::string stats = this->averageGensRes + ",/" + this->averageGensEI + ",/" + this->averageGensPC + ",/" + this->averageGensStr;

    return stats;
}

/**
 * Saves the averages stats of the curent generation in each GA pool
 */
void Game::saveGenStats() {
    if (this->averageGensRes == " ")
        this->averageGensRes = std::to_string(this->pool_A.averageResistance()) + "," + std::to_string(this->pool_B.averageResistance());
    else
        this->averageGensRes += "," + std::to_string(this->pool_A.averageResistance()) + "," + std::to_string(this->pool_B.averageResistance());

    if (this->averageGensEI == " ")
        this->averageGensEI = std::to_string(this->pool_A.averageEmotionalIntelligence()) + "," + std::to_string(this->pool_B.averageEmotionalIntelligence());
    else
        this->averageGensEI += "," + std::to_string(this->pool_A.averageEmotionalIntelligence()) + "," + std::to_string(this->pool_B.averageEmotionalIntelligence());

    if (this->averageGensPC == " ")
        this->averageGensPC = std::to_string(this->pool_A.averagePhysicalCondition()) + "," + std::to_string(this->pool_B.averagePhysicalCondition());
    else
        this->averageGensPC += "," + std::to_string(this->pool_A.averagePhysicalCondition()) + "," + std::to_string(this->pool_B.averagePhysicalCondition());

    if (this->averageGensStr == " ") {
        this->averageGensStr = std::to_string(this->pool_A.averageUpperBodyStrength()) + "," +
                               std::to_string(this->pool_A.averageLowerBodyStrength()) + "," +
                               std::to_string(this->pool_B.averageUpperBodyStrength()) + "," +
                               std::to_string(this->pool_B.averageLowerBodyStrength());
    }

    else
        this->averageGensStr += "," + std::to_string(this->pool_A.averageUpperBodyStrength()) + "," +
                               std::to_string(this->pool_A.averageLowerBodyStrength()) + "," +
                               std::to_string(this->pool_B.averageUpperBodyStrength()) + "," +
                               std::to_string(this->pool_B.averageLowerBodyStrength());
}

GA &Game::getPoolA() {
    return pool_A;
}

GA &Game::getPoolB() {
    return pool_B;
}

std::string Game::calculateSteps() {
    // RECORRO LA LISTA PARA CREAR UNA NUEVA DE HASTA DONDE LLEGA EL CHAMP


    // TRADUZCO A NUEVA LISTA A UN STRING


    this->pool_A.newGen(); // GENERATION
    this->pool_B.newGen(); // CHANGE
    this->saveGenStats();  // Save the data of the new gen
    this->new_GUI_Towers = GenericLinkedList<std::string>(); // Clears the list for the GUI towers
    return "!202GAME";
}

GenericLinkedList<Zone *> Game::resizePath(int type) {
    if (type == 1) {//RESIZE A*
        }
    if (type == 2) {//RESIZE Bt
        }
    else
        std::cout << "!219GAME";

    return GenericLinkedList<Zone *>();
}


