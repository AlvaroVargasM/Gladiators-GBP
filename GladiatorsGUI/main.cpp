#include <QApplication>
#include <QtDebug>
#include <QString>

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

    display.show();

    return a.exec();
}

/* Example of linked list usage and iteration.
 * When using it with a new class the line
 * "template class GenericNode<theClassBeingUsed>"
 * has to be added at the end of both list and node cpp files.
 *
GenericLinkedList<std::string>* list = new GenericLinkedList<std::string>;

list->add("Uno");
list->add("Dos");
list->add("Tres");

for(int i=0;i<list->getLength();i++){
    std::string str = list->get(i)->getData();
    qDebug() << QString::fromStdString(str);
}
*/
