//
// Created by jondorito on 13/05/19.
//

#ifndef GLADIATORS_GBP_TIMER_H
#define GLADIATORS_GBP_TIMER_H


#include <iostream>
#include <time.h>	// class needs this inclusion


//////////////////////////////////////////
// class declaration:


class timer {
public:
    timer();
    void           start();
    void           stop();
    void           reset();
    bool           isRunning();
    float          getTime();
    bool           isOver(unsigned long seconds);
private:
    bool           resetted;
    bool           running;
    unsigned long  beg;
    unsigned long  end;
};


#endif //GLADIATORS_GBP_TIMER_H
