//
// Created by valva on 4/13/2019.
//

#ifndef GLADIATORS_GBP_ZONE_H
#define GLADIATORS_GBP_ZONE_H


class Zone {
private:
    int id;
    bool blocked;
    int tower;
    int damage;
    int g;
    int h;
    int f;
    bool start;
    bool end;

public:
    Zone();

    int getId() const;

    void setId(int id);

    bool isBlocked() const;

    void setBlocked(bool blocked);

    int getTower() const;

    void setTower(int tower);

    int getDamage() const;

    void setDamage(int damage);

    int getG() const;

    void setG(int g);

    int getH() const;

    void setH(int h);

    int getF() const;

    void setF(int f);

    bool isStart() const;

    void setStart(bool start);

    bool isEnd() const;

    void setEnd(bool end);
};


#endif //GLADIATORS_GBP_ZONE_H
