#ifndef DISPLAY_H
#define DISPLAY_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <QList>

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

    /**
     * @brief setInfo Set's all the gladiators info in the panels.
     * @param infoList List that contains the gladiator's info.
     */
    void setInfo(GenericLinkedList<std::string> *infoList);

    /**
     * @brief shootArrow Animates an arrow being shoot from a tower to a gladiator.
     * @param towerId Tower shooting.
     * @param gladiator Gladiator that will be hit.
     */
    void shootArrow(std::string towerId, std::string gladiatorId);

    /**
     * @brief hitGladiator Updates the gladiator life when is shot.
     * @param gladiatorId Gladiator identification.
     * @param arrowType Type of arrow shot.
     */
    void hitGladiator(std::string gladiatorId, std::string arrowType);

    QGraphicsScene *scene; /**< Window QGraphicsScene. All the visual elements are added inside this scene for display. */

protected:
    /**
     * @brief showEvent Restarts the window every time is shown.
     * @param ev Event signal.
     */
    void showEvent(QShowEvent *ev);

private:
    Ui::Display *ui; /**< Qt form of Display class. Used to arrange the visual objects. */
    QGraphicsView *view; /**< Class QGraphicsView widget. The scene is added to it for display  purposes. */

    QLabel *starGldtr; /**< QLabel that holds the sprite of the A Star Gladiator. */
    QLabel *backGldtr; /**< QLabel that holds the sprite of the Backtracking Gladiator. */
    //GenericLinkedList<Tower*> *towers; /**< Lists that contains all the towers created. */
    QList<Tower*> *towers;

    QList<QLabel*> *infoLabels;/**< Lists that contains all the information labels from the panel. */


    //button test
    public slots: void test();
};

#endif // DISPLAY_H
