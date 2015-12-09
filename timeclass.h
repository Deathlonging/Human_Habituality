#ifndef TIME_H
#define TIME_H

#include <SFML/System/Time.hpp>

typedef float Seconds;
typedef int MicroSeconds;

class Time
{
public:
    Time();
    Time(sf::Time time);
    Time(Seconds time);
    Seconds asSeconds() const;
    static const Time Zero;

    bool operator==(const Time& right) const;
    bool operator>(const Time& right) const;
    void operator+=(const Time& right);
    Time operator-(const Time& right) const;
    double operator/(const Time& right) const;
    sf::Time getSFMLTime() const;
private:
    sf::Time mTime;
};

#endif // TIME_H
