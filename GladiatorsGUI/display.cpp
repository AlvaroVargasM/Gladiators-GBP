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


Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

    view = new QGraphicsView(this);
    scene = new QGraphicsScene(0,0,700,550,this);
    towers = new QList<Tower*>;
    infoLabels = new QList<QLabel*>;

    QGraphicsPixmapItem *scenebg = scene->addPixmap(QPixmap(":/arena.jpg"));
    scenebg->setPos(-300,-100);

    QLabel *start = new QLabel();
    start->setGeometry(0,0,50,50);
    start->setStyleSheet("QLabel { background-color : #cccccc;}");
    scene->addWidget(start);

    QLabel *end = new QLabel();
    end->setGeometry(468,468,50,50);
    end->setStyleSheet("QLabel { background-color : #2B8B5B;}");
    scene->addWidget(end);

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

    QLabel *infobg = new QLabel();
    infobg->setGeometry(560,-50,400,1000);
    infobg->setStyleSheet("QLabel { background-color:#f4faea;}");
    scene->addWidget(infobg);

    QLabel *infogap = new QLabel();
    infogap->setGeometry(650,-50,1,1000);
    infogap->setStyleSheet("QLabel { background-color:#1F4546;}");
    scene->addWidget(infogap);

    for(int n=0;n<12;n++){
        QLabel *infoHeader = new QLabel();
        infoHeader->setGeometry(560,-24+(24+1)*2*n,189,25);
        infoHeader->setAlignment(Qt::AlignCenter);
        infoHeader->setStyleSheet("QLabel { background-color:#1F4546; color:white; font:10pt; font-weight: bold;}");
        QString str = "";
        switch(n){
            case 0:
                str = "Gladiator";
                break;
            case 1:
                str = "Health";
                break;
            case 2:
                str = "Id";
                break;
            case 3:
                str = "Age";
                break;
            case 4:
                str = "Next Gen Survival Probability";
                break;
            case 5:
                str = "Expected Gens of Survival";
                break;
            case 6:
                str = "Emotional Intelligence";
                break;
            case 7:
                str = "Physical Condition";
                break;
            case 8:
                str = "Upper Body Strenght";
                break;
            case 9:
                str = "Lower Body Strenght";
                break;
            case 10:
                str = "Resistance";
                break;
            case 11:
                str = "Pathfinding Time";
                break;

        }
        infoHeader->setText(str);

        scene->addWidget(infoHeader);
    }

    for(int n=0;n<12;n++){
        QLabel *infoA = new QLabel();
        QLabel *infoB = new QLabel();
        infoA->setGeometry(560,3+(50*n),90,25);
        infoB->setGeometry(560+100,3+(50*n),90,25);
        infoA->setAlignment(Qt::AlignCenter);
        infoB->setAlignment(Qt::AlignCenter);
        infoA->setAttribute(Qt::WA_NoSystemBackground);
        infoB->setAttribute(Qt::WA_NoSystemBackground);
        infoA->setStyleSheet("QLabel {color:#1F4546; font:10pt; font-weight: bold;}");
        infoB->setStyleSheet("QLabel {color:#1F4546; font:10pt; font-weight: bold;}");
        infoA->setText("");
        infoB->setText("");
        if(n==0){
            infoA->setText("A Star");
            infoB->setText("Backtracking");
        }else{
            infoLabels->append(infoA);
            infoLabels->append(infoB);
        }
        scene->addWidget(infoA);
        scene->addWidget(infoB);
    }

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


    //Button for test/////////////
    QPushButton *bt= new QPushButton;
    bt->setGeometry(QRect(0,530,120,40));
    bt->setText("Test");
    QObject::connect(bt, SIGNAL(clicked()), this, SLOT(test()));
    bt->setStyleSheet("QPushButton {background-color: #42c2f4; color: white;}");
    scene->addWidget(bt);
    ///////////////////////////

    view->setScene(scene);
    this->setCentralWidget(view);
}

Display::~Display()
{
    delete ui;
    this->close();
}

void Display::move(std::string id, std::string direction)
{
    QLabel *sprite = new QLabel();

    if(id=="a" || id=="b") setAnimation(id,"walk");

    if(id=="a"){
        sprite = starGldtr;
    }else if(id=="b"){
        sprite = backGldtr;
    }else{
        //temp
        foreach(Tower* tower, *towers){
            if(id==tower->getId()){
                sprite = tower;
            }
        }
        //search in the towers linkedlist
    }

    int finalx = sprite->x();
    int finaly = sprite->y();
    if(direction=="up") finaly-=52.0;
    if(direction=="down") finaly+=52.0;
    if(direction=="right") finalx+=52.0;
    if(direction=="left") finalx-=52.0;


    QPropertyAnimation *animation = new QPropertyAnimation(sprite, "pos");
    animation->setDuration(200);
    animation->setStartValue(sprite->pos());
    animation->setEndValue(QPoint(finalx,finaly));
    animation->start();

    while (animation->state() != QAbstractAnimation::Stopped) QCoreApplication::processEvents();

    if(id=="a" || id=="b") setAnimation(id,"stand");
}

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

std::string Display::splitCommand(std::string *command)
{
    std::string subCommand = command->substr(0, command->find("."));
    command->erase(0, command->find(".")+1);
    return subCommand;
}

void Display::runCommands(GenericLinkedList<std::string> *commands)
{

    for(int i=0;i<commands->getLength();i++){
        std::string command = commands->get(i)->getData();

        std::string action = splitCommand(&command);

        if(action=="move"){
            //move.a.right
            std::string id = splitCommand(&command);
            move(id,command);
        }else if(action=="create"){
            //create.1.normal.5.2
            std::string id = splitCommand(&command);
            std::string type = splitCommand(&command);
            int xpos  = std::stoi(splitCommand(&command));
            int ypos  = std::stoi(command);

            Tower *tower = new Tower();
            tower->setId(id);
            tower->setType(type);
            tower->setPos(xpos,ypos);

            towers->append(tower);
            scene->addWidget(tower);
        }else if(action=="shoot"){
            //shoot.1.a
            std::string shooter = splitCommand(&command);
            shootArrow(shooter,command);
        }
    }
}

void Display::setInfo(GenericLinkedList<std::string> *infoList)
{
    for(int i=0;i<infoList->getLength();i++){
        std::string str = infoList->get(i)->getData();
        infoLabels->at(i)->setText(QString::fromStdString(str));
    }
}

void Display::shootArrow(std::string towerId, std::string gladiatorId)
{
    QLabel *gladiator = starGldtr;
    if(gladiatorId=="b")gladiator = backGldtr;

    Tower *tower = new Tower();

    foreach(Tower *listTower,*towers){
        if(towerId==listTower->getId()) tower=listTower;
    }

    std::string imageurl = tower->getType().append("arrow.png");
    imageurl.insert(0,":/");

    QLabel *arrow = new QLabel();
    arrow->setAttribute(Qt::WA_NoSystemBackground);
    arrow->setGeometry(tower->x(),tower->y(),160,160);

    QPixmap pix(QString::fromStdString(imageurl));

    QMatrix rm;

    int rotation;
    if(gladiator->x()<tower->x()){
        rotation=-90;
    }else{
        rotation=90;
    }

    rm.rotate(rotation);
    int pxw = pix.width(), pxh = pix.height();
    pix = pix.transformed(rm);
    pix = pix.copy((pix.width() - pxw)/2, (pix.height() - pxh)/2, pxw, pxh);

    arrow->setPixmap(pix);

    scene->addWidget(arrow);


    QPropertyAnimation *animation = new QPropertyAnimation(arrow, "pos");
    animation->setDuration(1500);
    animation->setStartValue(arrow->pos());

    int yoffset;
    if(gladiator->y()<tower->y()){
        yoffset= -12;
    }else{
        yoffset= -66;
    }

    animation->setEndValue(QPoint(gladiator->x(),gladiator->y()+yoffset));
    animation->start();
    while (animation->state() != QAbstractAnimation::Stopped) QCoreApplication::processEvents();

    arrow->setPixmap(QPixmap(""));

    setAnimation(gladiatorId,"hit");
    QPropertyAnimation *wait = new QPropertyAnimation(arrow, "pos");
    wait->setDuration(600);
    wait->setStartValue(arrow->pos());
    wait->setEndValue(tower->pos());
    wait->start();
    while (wait->state() != QAbstractAnimation::Stopped) QCoreApplication::processEvents();
    delete arrow;

    hitGladiator(gladiatorId,tower->getType());
}

void Display::hitGladiator(std::string gladiatorId, std::string arrowType)
{
    int index=0;
    if(gladiatorId=="b")index=1;
    int damage=1;
    if(arrowType=="fire"){
        damage=2;
    }else if(arrowType=="explosive"){
        damage=4;
    }

    int health = infoLabels->at(index)->text().toInt();
    health -=damage;

    if(health<1){
        health=0;
        setAnimation(gladiatorId,"dead");
    }else{
        setAnimation(gladiatorId,"stand");
    }

    infoLabels->at(index)->setText(QString::number(health));
}

void Display::showEvent(QShowEvent *ev)
{
    //initialize();
}

//button for testing
void Display::test()
{
    GenericLinkedList<std::string> *infoList = new GenericLinkedList<std::string>;
    infoList->add("1");
    infoList->add("1");
    infoList->add("Startacus");
    infoList->add("Backtracking");
    infoList->add("26");
    infoList->add("30");
    infoList->add("60");
    infoList->add("50");
    infoList->add("4");
    infoList->add("3");
    infoList->add("High");
    infoList->add("Medium");
    infoList->add("Outstanding");
    infoList->add("Average");
    infoList->add("8");
    infoList->add("7");
    infoList->add("6");
    infoList->add("9");
    infoList->add("80");
    infoList->add("65");
    infoList->add("2.25");
    infoList->add("5.33");
    setInfo(infoList);

    GenericLinkedList<std::string> *list = new GenericLinkedList<std::string>;
    /*for(int i =0;i<8;i++){
        list->append("move.a.right");
        list->append("move.b.down");
    }*/
    list->add("move.a.right");
    list->add("move.b.down");list->add("move.b.down");list->add("move.b.down");
    list->add("create.1.normal.6.2");
    list->add("shoot.1.a");
    list->add("shoot.1.b");
    runCommands(list);

}


