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

bool isDoubleNull(const double value)
{
    static const double epsilon = std::numeric_limits<double>::epsilon();
    return value< epsilon && value > -epsilon;
}

Radiant DegreeToRadiant(Degree angle)
{
    return angle*2*M_PI/DEGREE_MAX;
}

Degree RadiantToDegree(Radiant angle)
{
    return angle*DEGREE_MAX/(2*M_PI);
}

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
    Meter x = getXValue(),y = getYValue();
    Radiant angle;
    if(isDoubleNull(x))
    {
        angle = M_PI_2;
    }
    else
    {
        angle = atan(y/x);
    }
    if(x<0.0)
    {
        angle += M_PI;
    }
    angle -= M_PI_2;
    return RadiantToDegree(angle);
}

void Vector2D::rotate(Degree angle)
{
    Meter absolute = this->getAbsolute();
    if(isDoubleNull(absolute))
    {
        return;
    }
    Degree currentAngle = this->getAngle();
    Degree nextAngle = angle+currentAngle;
    Radiant radiant = DegreeToRadiant(nextAngle);
    setXValue(-absolute*sin(radiant));
    setYValue(absolute*cos(radiant));
}

Meter_2 Vector2D::getScalarProduct(const Vector2D &vec1, const Vector2D &vec2)
{
    return (vec1.getXValue() * vec2.getXValue()) + (vec1.getYValue() * vec2.getYValue());
}
