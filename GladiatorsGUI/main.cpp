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

    menu.show();


    /*GenericLinkedList<std::string>* list = new GenericLinkedList<std::string>;
    for(int i = 0; i<25; i++){
        list->add("Prueba");
    }list->printList();*/

    return a.exec();
}
