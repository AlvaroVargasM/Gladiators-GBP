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
}

/**
 * Generates three random towers in the game zones of random type
 */
void Game::generateTowers() {
    for (int x = 0;x < 3;x++) {
        int i = rng.getRandomNumber(0,N_ROWS - 1);
        int j = rng.getRandomNumber(0,N_COLUMNS - 1);
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

GenericLinkedList<std::string> Game::calculateSteps() {
    return GenericLinkedList<std::string>();
}

/**
 * Gets the best Gladiator from each pool and puts them in a linked list
 * @return linked list with the best gladiators from each pool
 */
std::string Game::getChampions() {
    Gladiator champ_1 = this->pool_A.getStrongest();
    Gladiator champ_2 = this->pool_B.getStrongest();

    std::string champs = std::to_string(champ_1.getResistance()) + "," + std::to_string(champ_2.getResistance()) + "," +
            "Yeet" + "," +"DoubleYeet" + "," +
            std::to_string(champ_1.getAge()) + "," + std::to_string(champ_2.getAge()) + "," +
            "0" + "," + "0" + "," +
            "0" + "," + "0" + "," +
            std::to_string(champ_1.getEmotionalIntelligence()) + "," + std::to_string(champ_2.getEmotionalIntelligence()) + "," +
            std::to_string(champ_1.getPhysicalCondition()) + "," + std::to_string(champ_2.getPhysicalCondition()) + "," +
            std::to_string(champ_1.getUpperBodyStrength()) + "," + std::to_string(champ_1.getLowerBodyStrength()) + "," +
            std::to_string(champ_2.getUpperBodyStrength()) + "," + std::to_string(champ_2.getLowerBodyStrength());

    return champs;
}

IntimidationZone *Game::getGameZone() const {
    return game_Zone;
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
    return new_GUI_Towers;
}


