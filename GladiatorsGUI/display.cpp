#include "display.h"
#include "ui_display.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QMovie>
#include <QLabel>
#include <QPropertyAnimation>
#include <QtDebug>
#include <iostream>


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

    //
    starGldtr = new QLabel();
    starGldtr->setGeometry(0,0,32,32);
    starGldtr->setAttribute(Qt::WA_NoSystemBackground);
    QMovie *agif = new QMovie(":/astand.gif");
    agif->start();
    starGldtr->setMovie(agif);
    scene->addWidget(starGldtr);

    backGldtr = new QLabel();
    backGldtr->setGeometry(0,0,32,60);
    backGldtr->setAttribute(Qt::WA_NoSystemBackground);
    QMovie *bgif = new QMovie(":/bstand.gif");
    bgif->start();
    backGldtr->setMovie(bgif);
    scene->addWidget(backGldtr);


    //Button for test
    QPushButton *bt= new QPushButton;
    bt->setGeometry(QRect(600,200,120,40));
    bt->setText("Test");
    QObject::connect(bt, SIGNAL(clicked()), this, SLOT(test()));
    bt->setStyleSheet("QPushButton {background-color: #42c2f4; color: white;}");
    scene->addWidget(bt);
    //

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

/**
 * @brief move Moves a game object one square in the direction give.
 * @param id Game object identificator.
 * @param direction Direction wich the object has to move.
 */
void Display::move(std::string id, std::string direction)
{
    QLabel *sprite;
    if(id=="a" || id=="b") setAnimation(id,"walk");

    if(id=="a"){
        sprite = starGldtr;
    }else if(id=="b"){
        sprite = backGldtr;
    }else{
        //search in the towers linkedlist
        sprite = starGldtr;
    }

    int finalx = sprite->x();
    int finaly = sprite->y();
    if(direction=="up") finaly-=52.0;
    if(direction=="down") finaly+=52.0;
    if(direction=="right") finalx+=52.0;
    if(direction=="left") finalx-=52.0;


    QPropertyAnimation *animation = new QPropertyAnimation(sprite, "pos");
    animation->setDuration(1000);
    animation->setStartValue(sprite->pos());
    animation->setEndValue(QPoint(finalx,finaly));
    animation->start();

    while (animation->state() != QAbstractAnimation::Stopped) QCoreApplication::processEvents();

    if(id=="a" || id=="b") setAnimation(id,"stand");
}

/**
 * @brief setAnimation Changes the animation gif of a given gladiator.
 * @param gladiator Gladiator's id.
 * @param action Animation action to be displayed.
 */
void Display::setAnimation(std::string gladiator, std::string action)
{
    QLabel *gldtrLabel;
    if(gladiator == "a"){
        gldtrLabel = starGldtr;
    }else {
        gldtrLabel = backGldtr;
    }

    action.insert(0,":/"+gladiator);
    action.append(".gif");

    QMovie *gif = new QMovie(QString::fromStdString(action));
    gldtrLabel->setMovie(gif);
    gif->start();
}

//button for testing
void Display::test()
{
    move("a","down");
    move("a","right");

    move("b","right");
    move("b","right");
}


