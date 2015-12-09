#ifndef CLOCK_H
#define CLOCK_H

#include <SFML/System/Clock.hpp>

#include "timeclass.h"

class Clock
{
public:
    Clock();
    Time getElapsedTime() const;
    Time restart();
private:
    sf::Clock mClock;
};

#endif // CLOCK_H
