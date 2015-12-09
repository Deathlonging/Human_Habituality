#include "timeclass.h"

Time::Time() : mTime(sf::Time())
{

}

Time::Time(sf::Time time) : mTime(time)
{
}

Time::Time(Seconds time) : mTime(sf::seconds(time))
{

}

Seconds Time::asSeconds() const
{
    return mTime.asSeconds();
}

bool Time::operator==(const Time &right) const
{
    return this->mTime == right.getSFMLTime();
}

bool Time::operator>(const Time &right) const
{
    return this->mTime > right.getSFMLTime();
}

void Time::operator+=(const Time &right)
{
    this->mTime += right.getSFMLTime();
}

Time Time::operator-(const Time &right) const
{
    return Time(this->mTime - right.getSFMLTime());
}

double Time::operator/(const Time &right) const
{
    return this->mTime.asSeconds()/(right.getSFMLTime().asSeconds());
}

sf::Time Time::getSFMLTime() const
{
    return mTime;
}

const Time Time::Zero = Time(sf::Time::Zero);
