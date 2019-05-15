#include <QApplication>
#include <QtDebug>
#include <QString>

#include "genericlinkedlist.h"
#include "menu.h"
#include "display.h"
#include "statistics.h"
#include "tower.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu;
    menu.show();
    return a.exec();
}
