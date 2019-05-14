//
// Created by jondorito on 23/04/19.
//

#include "timer.h"

timer::timer() {
    resetted = true;
    running = false;
    beg = 0;
    end = 0;
}


/**
 * starts the timer, if the timer was pause it starts it right from where it left off
 */
void timer::start() {
    if(! running) {
        if(resetted)
            beg = (unsigned long) clock();
        else
            beg -= end - (unsigned long) clock();
        running = true;
        resetted = false;
    }
}

/**
 * Stops the clock
 */
void timer::stop() {
    if(running) {
        end = (unsigned long) clock();
        running = false;
    }
}

/**
 * Resets the timer back to 0
 */
void timer::reset() {
    bool wereRunning = running;
    if(wereRunning)
        stop();
    resetted = true;
    beg = 0;
    end = 0;
    if(wereRunning)
        start();
}

/**
 * Tells whether the timer is in a start state
 * @return boolean whether timer is currently running
 */
bool timer::isRunning() {
    return running;
}

/**
 * Return the current elapsed time
 * @return long time
 */
float timer::getTime() {
    if(running)
        return ((float) clock() - beg) / CLOCKS_PER_SEC;
    else
        return end - beg;
}

/**
 * Returns whether the timer is passed "n" seconds
 * @param seconds
 * @return
 */
bool timer::isOver(unsigned long seconds) {
    return seconds <= getTime();
}
