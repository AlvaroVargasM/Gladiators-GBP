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
    this->completed_A = false;
    this->completed_B = false;
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

        if ((i != INI_I && j != INI_J) && (i != FIN_I && j != FIN_J) && !this->game_Zone->getZone(i, j)->isBlocked()) {
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

    GenericLinkedList<int>* arrow = new GenericLinkedList<int>;
    arrow->add(n_Towers);
    arrow->add(damage);

    this->game_Zone->getZone(i,j)->getDamage()->add(arrow);

    for(int x = 1;x < (type + 1);x++) {
        if (i - x >= 0 && !this->game_Zone->getZone(i - x,j)->isBlocked())
            this->game_Zone->getZone(i - x,j)->getDamage()->add(arrow);

        if (i + x < N_ROWS && !this->game_Zone->getZone(i + x,j)->isBlocked())
            this->game_Zone->getZone(i + x,j)->getDamage()->add(arrow);

        if (j - x >= 0 && !this->game_Zone->getZone(i,j - x)->isBlocked())
            this->game_Zone->getZone(i,j - x)->getDamage()->add(arrow);

        if (j + x < N_COLUMNS && !this->game_Zone->getZone(i,j + x)->isBlocked())
            this->game_Zone->getZone(i,j + x)->getDamage()->add(arrow);

        if (i - x >= 0 && j - x >= 0 && !this->game_Zone->getZone(i - x,j - x)->isBlocked())
            this->game_Zone->getZone(i - x,j - x)->getDamage()->add(arrow);

        if (i - x >= 0 && j + x < N_COLUMNS && !this->game_Zone->getZone(i - x,j + x)->isBlocked())
            this->game_Zone->getZone(i - x,j + x)->getDamage()->add(arrow);

        if (i + x < N_ROWS && j - x >= 0 && !this->game_Zone->getZone(i + x,j - x)->isBlocked())
            this->game_Zone->getZone(i + x,j - x)->getDamage()->add(arrow);

        if (i + x < N_ROWS && j + x < N_COLUMNS && !this->game_Zone->getZone(i + x,j + x)->isBlocked())
            this->game_Zone->getZone(i + x,j + x)->getDamage()->add(arrow);
    }
}

/**
 * Gets the best Gladiator from each pool and puts them in a linked list
 * @return linked list with the best gladiators from each pool
 */
std::string Game::getChampions() {
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
    this->path_A = *this->pths.findPathByA_Star(this->game_Zone,INI_I,INI_J,FIN_I,FIN_J);
    this->path_B = *this->pths.BackTrack(this->game_Zone,INI_I,INI_J,FIN_I,FIN_J);
    return new_GUI_Towers;
}

/**
 * Gives a string with all the stats saved during the game
 * @return final stats
 */
std::string Game::getStats() {
    std::string stats = this->averageGensRes + "/" + this->averageGensEI + "/" + this->averageGensPC + "/" + this->averageGensStr;
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
    GenericLinkedList<Zone*> travel_A = resizePath(1);
    GenericLinkedList<Zone*> travel_B = resizePath(2);

    // TRADUZCO A NUEVA LISTA A UN STRING
    std::string result = translateTravel(travel_A,travel_B);

    this->pool_A.newGen(); // GENERATION
    this->pool_B.newGen(); // CHANGE
    this->saveGenStats();  // Save the data of the new gen
    this->new_GUI_Towers = GenericLinkedList<std::string>(); // Clears the list for the GUI towers
    return result;
}

GenericLinkedList<Zone*> Game::resizePath(int type) {
    GenericLinkedList<Zone*> cutPath;

    if (type == 1) { // RESIZE A*
        int glife = this->pool_A.getStrongest().getResistance();

        for (int i = 0;i < *this->path_A.getLength();i++) {
            for (int x = 0; x < *this->path_A.get(i)->getData()->getDamage()->getLength() - 1;i++) {
                glife -= this->path_A.get(i)->getData()->getDamage()->get(x)->getData()->get(1)->getData();
                x++;
            }
            if (glife > 0) {
                cutPath.add(this->path_A.get(i)->getData());
            }
        }
        if (cutPath.getLast()->getData()->getId() == this->path_A.getLast()->getData()->getId())
            this->completed_A = true;
    }
    if (type == 2) { // RESIZE Bt
        int glife = this->pool_B.getStrongest().getResistance();

        for (int i = 0;i < *this->path_B.getLength();i++) {
            for (int x = 0; x < *this->path_B.get(i)->getData()->getDamage()->getLength() - 1;i++) {
                glife -= this->path_B.get(i)->getData()->getDamage()->get(x)->getData()->get(1)->getData();
                x++;
            }
            if (glife > 0) {
                cutPath.add(this->path_B.get(i)->getData());
            }
        }
        if (cutPath.getLast()->getData()->getId() == this->path_B.getLast()->getData()->getId())
            this->completed_B = true;
    }

    return cutPath;
}

std::string Game::translateTravel(GenericLinkedList<Zone *> travel_A,GenericLinkedList<Zone *> travel_B) {
    std::string final_Command_Line; // Used for the completed string

    int last_i = INI_I;
    int last_j = INI_J;

    GenericLinkedList<std::string> commands_A;
    GenericLinkedList<std::string> commands_B;

    // We fill the command list of A
    for (int i = 0;i < *travel_A.getLength();i++) {
        std::string command;
        int current_i = travel_A.get(i)->getData()->getX(N_COLUMNS);
        int current_j = travel_A.get(i)->getData()->getY(N_COLUMNS,N_ROWS);

        if (current_i == last_i && current_j > last_j) {
            command += ",move.a.right";
            last_i = current_i;
            last_j = current_j;
        }
        if (current_i == last_i && current_j < last_j) {
            command += ",move.a.left";
            last_i = current_i;
            last_j = current_j;
        }
        if (current_i < last_i && current_j == last_j) {
            command += ",move.a.up";
            last_i = current_i;
            last_j = current_j;
        }
        if (current_i > last_i && current_j == last_j) {
            command += ",move.a.down";
            last_i = current_i;
            last_j = current_j;
        }

        commands_A.add(command);
    }

    // We fill the command list of B
    for (int i = 1;i < *travel_B.getLength();i++) {
        std::string command;
        int current_i = travel_B.get(i)->getData()->getX(N_COLUMNS);
        int current_j = travel_B.get(i)->getData()->getY(N_COLUMNS,N_ROWS);



        if (current_i == last_i && current_j > last_j) {
            command += ",move.b.right";
            last_i = current_i;
            last_j = current_j;
        }
        if (current_i == last_i && current_j < last_j) {
            command += ",move.b.left";
            last_i = current_i;
            last_j = current_j;
        }
        if (current_i < last_i && current_j == last_j) {
            command += ",move.b.up";
            last_i = current_i;
            last_j = current_j;
        }
        if (current_i > last_i && current_j == last_j) {
            command += ",move.b.down";
            last_i = current_i;
            last_j = current_j;
        }

        commands_B.add(command);
    }

    int index = 0;
    if (*commands_A.getLength() == *commands_B.getLength())
        index = *commands_A.getLength();
    if (*commands_A.getLength() < *commands_B.getLength())
        index = *commands_B.getLength();
    if (*commands_A.getLength() > *commands_B.getLength())
        index = *commands_A.getLength();

    for (int i = 0;i < index - 1;i++) {
        final_Command_Line += commands_A.get(i)->getData();
        final_Command_Line += commands_B.get(i)->getData();
    }
    std::cout << final_Command_Line;
    return final_Command_Line;
}

bool Game::isCompletedA() {
    return this->completed_A;
}

bool Game::isCompletedB() {
    return this->completed_B;
}

IntimidationZone *Game::getGameZone() {
    return game_Zone;
}


