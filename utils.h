#ifndef UTILS_H
#define UTILS_H

extern int getRandomValue(int min, int max);

struct Vector2D{
    Vector2D() : x(0.0), y(0.0){}
    Vector2D(double x, double y) : x(x), y(y){}
    double x;
    double y;
};

#endif // UTILS_H
