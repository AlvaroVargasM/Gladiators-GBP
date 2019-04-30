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

    /*GenericLinkedList<std::string*> *list = new GenericLinkedList<std::string*>;
    std::string s = "UNO";
    list->add(&s);
    list->printList();*/

    menu.show();



    return a.exec();
}
