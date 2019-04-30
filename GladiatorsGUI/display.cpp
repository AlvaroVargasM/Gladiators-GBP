#include "display.h"
#include "ui_display.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>


/**
 * @brief Display class constructor.
 * @param parent
 */
Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

    view = new QGraphicsView(this);
    scene = new QGraphicsScene(0,0,700,550,this);

    QGraphicsPixmapItem *scenebg = scene->addPixmap(QPixmap(":/arena.jpg"));
    scenebg->setPos(-300,-100);

    int dimension = 50;
    int gridSize = 10;
    int margin = 2;
    int x=0;
    int y=0;
    for(int n=1; n < (gridSize*gridSize)+1; n++){
        QGraphicsPixmapItem *square = scene->addPixmap(QPixmap(":/grid.png") );
        square->setPos(x,y);
        x+=dimension+ margin;
        if(n%gridSize == 0){
            x=0;
            y+=dimension+margin;
        }
    }

    view->setScene(scene);
    this->setCentralWidget(view);
}


/**
 * @brief Display class destructor.
 */
Display::~Display()
{
    delete ui;
    this->close();
}
