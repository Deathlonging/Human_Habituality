#ifndef UTILS_H
#define UTILS_H

typedef double Meter;
typedef double MeterPerSecond;
typedef double MeterPerSecond_2;
typedef double Degree;
typedef double DegreePerSecond;
typedef double DegreePerSecond_2;

extern int getRandomValue(int min, int max);

struct Vector2D{
    Vector2D() : x(0.0), y(0.0){}
    Vector2D(Meter x, Meter y) : x(x), y(y){}
    Meter x;
    Meter y;
    bool operator==(const Vector2D& vector) const
    {return this->x==vector.x && this->y==vector.y;}
};

#endif // UTILS_H
