#ifndef UTILS_H
#define UTILS_H

typedef double Meter;
typedef double MeterPerSeconds;
typedef double MeterPerSeconds_2;

extern int getRandomValue(int min, int max);

struct Vector2D{
    Vector2D() : x(0.0), y(0.0){}
    Vector2D(Meter x, Meter y) : x(x), y(y){}
    Meter x;
    Meter y;
};

#endif // UTILS_H
