#ifndef DISPLAY_H
#define DISPLAY_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>

#include "genericlinkedlist.h"
#include "tower.h"

namespace Ui {
class Display;
}

/**
 * @brief Game's main window. The gladiators and towers are displayed here.
 */
class Display : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Display class constructor.
     * @param parent
     */
    explicit Display(QWidget *parent = nullptr);

    /**
     * @brief Display class destructor.
     */
    ~Display();

    /**
     * @brief move Moves a game object one square in the direction give.
     * @param id Game object identificator.
     * @param direction Direction wich the object has to move.
     */
    void move(std::string id, std::string direction);


    /**
     * @brief setAnimation Changes the animation gif of a given gladiator.
     * @param gladiator Gladiator's id.
     * @param action Animation action to be displayed.
     */
    void setAnimation(std::string gladiator,std::string action);

    /**
     * @brief splitCommand Splits a subcommand out of a command string.
     * @param command Command string.
     * @return A subcommand.
     */
    std::string splitCommand(std::string *command);

    /**
     * @brief runCommands Displays all the commands in a given list.
     * @param commands List holding the commands.
     */
    void runCommands(GenericLinkedList<std::string> *commands);



    QGraphicsScene *scene; /**< Window QGraphicsScene. All the visual elements are added inside this scene for display. */

private:
    Ui::Display *ui; /**< Qt form of Display class. Used to arrange the visual objects. */
    QGraphicsView *view; /**< Class QGraphicsView widget. The scene is added to it for display  purposes. */

    QLabel *starGldtr; /**< QLabel that holds the sprite of the A Star Gladiator. */
    QLabel *backGldtr; /**< QLabel that holds the sprite of the Backtracking Gladiator. */
    GenericLinkedList<Tower>* towers; /**< Lists that contains all the towers created. */



    //button test
    public slots: void test();
};

#endif // DISPLAY_H
