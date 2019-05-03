#include "tower.h"
#include <QLabel>
#include <QPixmap>

Tower::Tower(QWidget *parent)
{
}

void Tower::setPos(int x, int y)
{
    setGeometry(x,y,43,129);
    setAttribute(Qt::WA_NoSystemBackground);
}

void Tower::setId(std::string id)
{
    this->id = id;
}

void Tower::setType(std::string type)
{
    this->type = type;

    type.insert(0,":/");
    type.append("tower.png");

    QPixmap img(QString::fromStdString(type));
    setPixmap(img);
}

std::string Tower::getId()
{
    return id;
}

std::string Tower::getType()
{
    return type;
}
