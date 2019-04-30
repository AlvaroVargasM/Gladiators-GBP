#include <QApplication>

#include "genericlinkedlist.h"
#include "menu.h"
#include "display.h"
#include "statistics.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu;
    Display display;
    Statistics statistics;

    //menu.show();

    display.show();

    return a.exec();
}
