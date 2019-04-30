#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QGraphicsScene>

//#include "tower.h"

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

    QGraphicsScene *scene; /**< Window QGraphicsScene. All the visual elements are added inside this scene for display. */

private:
    Ui::Display *ui; /**< Qt form of Display class. Used to arrange the visual objects. */
    QGraphicsView *view; /**< Class QGraphicsView widget. The scene is added to it for display  purposes. */
};

#endif // DISPLAY_H
