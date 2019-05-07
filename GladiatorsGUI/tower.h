#ifndef TOWER_H
#define TOWER_H

#include <QLabel>


/**
 * @brief The Tower class Tower object. It's sprite depends on the type specified.
 */
class Tower : public QLabel
{
    Q_OBJECT

public:
    Tower(QWidget *parent = 0);
    void setPos(int x, int y);
    void setId(std::string id);
    void setType(std::string type);
    std::string getId();
    std::string getType();

private:
    std::string id;
    std::string type;
};

#endif // TOWER_H
