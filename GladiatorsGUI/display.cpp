    #include "display.h"
#include "ui_display.h"
#include "statistics.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QMovie>
#include <QLabel>
#include <QPropertyAnimation>
#include <QtDebug>
#include <iostream>
#include <QTimer>


Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{

    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);
    active = true;

    //connector = Connector();

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

    for(int n=0;n<11;n++){
        QLabel *infoHeader = new QLabel();
        infoHeader->setGeometry(560,-24+(24+3)*2*n,189,25);
        infoHeader->setAlignment(Qt::AlignCenter);
        infoHeader->setStyleSheet("QLabel { background-color:#1F4546; color:white; font:10pt; font-weight: bold;}");
        QString str = "";
        switch(n){
            case 0:
                str = "Gladiator";
                break;
            case 1:
                str = "Resistance";
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
                str = "Pathfinding Time";
                break;
        }
        infoHeader->setText(str);

        scene->addWidget(infoHeader);
    }

    for(int n=0;n<11;n++){
        QLabel *infoA = new QLabel();
        QLabel *infoB = new QLabel();
        infoA->setGeometry(560,3+(54*n),90,25);
        infoB->setGeometry(560+100,3+(54*n),90,25);
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
    starGldtr->setGeometry(-50,-60,32,32);
    starGldtr->setAttribute(Qt::WA_NoSystemBackground);
    QMovie *agif = new QMovie(":/astand.gif");
    agif->start();
    starGldtr->setMovie(agif);
    scene->addWidget(starGldtr);

    backGldtr = new QLabel();
    backGldtr->setGeometry(-75,0,32,60);
    backGldtr->setAttribute(Qt::WA_NoSystemBackground);
    QMovie *bgif = new QMovie(":/bstand.gif");
    bgif->start();
    backGldtr->setMovie(bgif);
    scene->addWidget(backGldtr);

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
        foreach(Tower* tower, *towers){
            if(id==tower->getId()){
                sprite = tower;
            }
        }
    }

    int finalx = sprite->x();
    int finaly = sprite->y();
    if(direction=="up") finaly-=52.0;
    if(direction=="down") finaly+=52.0;
    if(direction=="right") finalx+=52.0;
    if(direction=="left") finalx-=52.0;


    QPropertyAnimation *animation = new QPropertyAnimation(sprite, "pos");
    animation->setDuration(300);
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

        if(command=="finish") active=false;


        std::string action = splitCommand(&command);

        if(action=="move"){
            std::string id = splitCommand(&command);
            move(id,command);
        }else if(action=="create"){
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
            std::string shooter = splitCommand(&command);
            shootArrow(shooter,command);
        }
    }
}

void Display::setInfo(GenericLinkedList<std::string> *infoList)
{
    for(int i=0;i<infoList->getLength();i++){
        std::string str = infoList->get(i)->getData();

        if(i==2){
            str = "A Staridas "+toRoman(stoi(str));
        }
        if(i==3){
            str = "Backtracus "+toRoman(stoi(str));
        }

        infoLabels->at(i)->setText(QString::fromStdString(str));
    }
}

std::string Display::toRoman(int value)
{
    struct romandata_t { unsigned int value; char const* numeral; };
        const struct romandata_t romandata[] =
        {
            {1000, "M"}, {900, "CM"},{500, "D"}, {400, "CD"},
            {100, "C"}, { 90, "XC"},{ 50, "L"}, { 40, "XL"},
            { 10, "X"}, { 9, "IX"},{ 5, "V"}, { 4, "IV"},
            { 1, "I"},{ 0, NULL}
        };
        std::string result;
        for (const romandata_t* current = romandata; current->value > 0; ++current)
        {
            while (value >= current->value)
            {
                result += current->numeral;
                value -= current->value;
            }
        }
        return result;
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
    arrow->setGeometry(tower->x()+10,tower->y(),160,160);

    QPixmap pix(QString::fromStdString(imageurl));

    QMatrix rm;

    int rotation=0;
    if(gladiator->x()<tower->x()){
        rotation=-90;
    }else{
        rotation=90;
    }

    if(abs(gladiator->x()-tower->x())<35 && gladiator->y()<(tower->y()+88)){
        rotation=0;
    }else if(abs(gladiator->x()-tower->x())<35 && gladiator->y()>(tower->y()+88)){
        rotation=180;
    }else if(abs(gladiator->y()-tower->y()-88)<35){
        if(gladiator->x()<tower->x()){
            rotation=-90;
        }else{
            rotation=90;
        }
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
    int damage=4;
    if(arrowType=="fire"){
        damage=8;
    }else if(arrowType=="explosive"){
        damage=16;
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

void Display::clear(bool total)
{
    foreach(QLabel *label,*infoLabels){
        label->setText("");
    }
    starGldtr->setGeometry(-50,-60,32,32);
    backGldtr->setGeometry(-75,0,32,60);

    if(total){
        foreach(Tower *listTower,*towers){
            delete listTower;
        }
        towers = new QList<Tower*>;
    }else{
        setAnimation("a","walk");
        setAnimation("b","walk");

        QPropertyAnimation *animation1 = new QPropertyAnimation(starGldtr, "pos");
        animation1->setDuration(400);
        animation1->setStartValue(QPoint(-50,-50));
        animation1->setEndValue(QPoint(0,0));
        animation1->start();
        while (animation1->state() != QAbstractAnimation::Stopped) QCoreApplication::processEvents();

        QPropertyAnimation *animation2 = new QPropertyAnimation(backGldtr, "pos");
        animation2->setDuration(400);
        animation2->setStartValue(QPoint(-70,0));
        animation2->setEndValue(QPoint(0,0));
        animation2->start();
        while (animation2->state() != QAbstractAnimation::Stopped) QCoreApplication::processEvents();

        setAnimation("a","stand");
        setAnimation("b","stand");
    }
}

void Display::gameLoop()
{
    while(active){
        QEventLoop loop;
        QTimer::singleShot(1300,&loop,SLOT(quit()));
        loop.exec();

        clear(false);

        //test();
        setInfo(Connector::get("setStats"));
        runCommands(Connector::get("setSteps"));
    }

    clear(true);

    statisticsWin = new Statistics();
    statisticsWin->setParent(this);
    statisticsWin->generateCharts(Connector::getCharts());
    this->hide();
    statisticsWin->show();
}

void Display::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    QTimer::singleShot(500, this, SLOT(restart()));
    return;
}

void Display::test()
{
    //GenericLinkedList<std::string> *infoList = Connector::get("setStats");
    /*GenericLinkedList<std::string> *infoList = new GenericLinkedList<std::string>;
    infoList->add("30");
    infoList->add("30");
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
    infoList->add("2.25");
    infoList->add("5.33");*/
    //setInfo(infoList);

    //GenericLinkedList<std::string>* list = Connector::get("setSteps");
    /*GenericLinkedList<std::string> *list = new GenericLinkedList<std::string>;
    list->add("create.1.explosive.2.2");
    list->add("create.2.normal.3.2");
    list->add("create.3.explosive.4.2");
    list->add("move.1.up");
    list->add("shoot.4.a");
    runCommands(list);*/
}

void Display::restart()
{
    active = true;
    gameLoop();
}


