#include "clock.h"

Clock::Clock()
{

}

Time Clock::getElapsedTime() const
{
    return Time(mClock.getElapsedTime());
}

Time Clock::restart()
{
    return Time(mClock.restart());
}

