#include "display.h"
#include <QApplication>

#include "genericlinkedlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Display w;

    /*GenericLinkedList<std::string*> *list = new GenericLinkedList<std::string*>;
    std::string s = "UNO";
    list->add(&s);
    list->printList();*/

    w.show();



    return a.exec();
}
