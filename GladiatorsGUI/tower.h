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

    /**
     * @brief Tower Default constructor.
     * @param parent
     */
    Tower(QWidget *parent = 0);

    /**
     * @brief setPos Sets the sprite location in the display.
     * @param x X coordinate.
     * @param y Y coordinate.
     */
    void setPos(int x, int y);

    /**
     * @brief setId Sets the identification class member.
     * @param id Tower identification.
     */
    void setId(std::string id);

    /**
     * @brief setType Sets the type of the tower. Options are fire, explosive and normal.
     * @param type Tower's type.
     */
    void setType(std::string type);

    /**
     * @brief getId Returns the tower id.
     * @return Tower id.
     */
    std::string getId();

    /**
     * @brief getType Returns the tower type.
     * @return Tower type.
     */
    std::string getType();

private:
    std::string id; /**< Tower id. */
    std::string type; /**< Tower type. */
};

#endif // TOWER_H
