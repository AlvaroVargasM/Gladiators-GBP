//
// Created by alvar on 10/05/19.
//

#pragma once

#define BASE_DAMAGE 1
#define N_ROWS 10
#define N_COLUMNS 10
#define INI_I 0
#define INI_J 0
#define FIN_I 9
#define FIN_J 9

#include "GA.h"
#include "IntimidationZone.h"
#include "PathSolver.h"

/**
 * Game class, works as the main controller of all the different parts of he game
 */
class Game {
private:
    /**
     * RNG object for creating random generated objects
     */
    RNG rng;

    /**
     * Path solver object
     */
    PathSolver pths;

    /**
     * Path made by A*
     */
    GenericLinkedList<Zone*> path_A;

    /**
     * Path made by BackTrack
     */
    GenericLinkedList<Zone*> path_B;

    /**
     * Genetic pool for the gladiator A
     */
    GA pool_A;

    /**
     * Genetic pool for the gladiator B
     */
    GA pool_B;

    /**
     * Bool for checking if gladiator A won the game
     */
    bool completed_A;

    /**
     * Bool for checking if gladiator B won the game
     */
    bool completed_B;

    /**
     * String for storing the average resistance of the pools during the different generations
     */
    std::string averageGensRes;

    /**
     * String for storing the average emotional intelligence of the pools during the different generations
     */
    std::string averageGensEI;

    /**
     * String for storing the average physical condition of the pools during the different generations
     */
    std::string averageGensPC;

    /**
     * String for storing the average strength of the pools during the different generations
     */
    std::string averageGensStr;

    /**
     * Matrix of the game, where all towers go and where the path finding algorithms work
     */
    IntimidationZone* game_Zone = new IntimidationZone(N_ROWS,N_COLUMNS);

    /**
     * Linked list used for storing the commands of towers creations for the GUI
     */
    GenericLinkedList<std::string> new_GUI_Towers;

    /**
     * Int for keeping the amount of towers generated
     */
    int n_Towers;

    /**
     * Generates three random towers in the game zones of random type
     */
    void generateTowers();

    /**
     * Puts a single tower on the game zone, it marks the correct adjacents zones with the damage given by the tower's
     * arrows
     * @param i row of the tower
     * @param j column of the tower
     * @param type of tower
     */
    void putTower(int i,int j,int type);

    /**
     * Adds a new string to the linked list of new towers for the GUI using the info passed
     * @param type of tower
     * @param i row
     * @param j column
     */
    void generateNewGUITower(int i,int j,int type);

    /**
     * Takes a path choosen by the passed type to see if the gladiator would survive that path, it generates a new path of
     * the real route of the gladiator
     * @param type of path to check
     * @return the real path that the gladiator takes
     */
    GenericLinkedList<Zone*> resizePath(int type);

    /**
     * Takes a path and translates it to a command string for the GUI
     * @param travel_A path of gladiator A
     * @param travel_B path of gladiator B
     * @return the command for GUI
     */
    std::string translateTravel(GenericLinkedList<Zone*> travel_1,GenericLinkedList<Zone*>travel_2);

    /**
     * Saves the averages stats of the curent generation in each GA pool
     */
    void saveGenStats();

public:
    /**
     * Constructs the game class and initializes some of the members
     */
    Game();

    /**
     * Gets the best Gladiator from each pool and puts them in a linked list
     * @return linked list with the best gladiators from each pool
     */
    std::string getChampions();

    /**
     * Returns the string command for creating towers in the GUI
     * @return GUI towers recently added
     */
    GenericLinkedList<std::string> getTowers();

    /**
     * Gives back the steps for the gladiators in GUI, also
     * @return
     */
    std::string getSteps();

    /**
     * Gives a string with all the stats saved during the game
     * @return final stats
     */
    std::string getStats();
};
