#include "utils.h"

#include <time.h>
#include <stdlib.h>
int getRandomValue(int min, int max)
{
    static bool isInitialized = false;
    if(!isInitialized)
    {
        srand(time(NULL));
        isInitialized=true;
    }
    return min + (rand() % (max-min+1));
}

#include <cmath>

void Vector2D::change(Meter dx, Meter dy)
{
    x += dx;
    y += dy;
}

Meter Vector2D::getAbsolute() const
{
    return sqrt((getXValue()*getXValue())+(getYValue()*getYValue()));
}

Degree Vector2D::getAngle() const
{
    return acos(getYValue()/getAbsolute()); //nördlich ist 0
}

void Vector2D::rotate(Degree angle)
{
    Meter absolute = this->getAbsolute();
    Degree currentAngle = this->getAngle();
    Degree nextAngle = angle+currentAngle;
    setXValue(absolute*sin(nextAngle));
    setYValue(-absolute*cos(nextAngle));
}

Meter_2 Vector2D::getScalarProduct(const Vector2D &vec1, const Vector2D &vec2)
{
    return (vec1.getXValue() * vec2.getXValue()) + (vec1.getYValue() * vec2.getYValue());
}
