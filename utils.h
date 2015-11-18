#ifndef UTILS_H
#define UTILS_H

typedef double Meter;
typedef double Meter_2;
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
    Meter getXValue() const {return x;}
    Meter getYValue() const {return y;}
    void setXValue(Meter xValue) {x=xValue;}
    void setYValue(Meter yValue) {y=yValue;}
    void change(Meter dx, Meter dy);
    Meter getAbsolute() const;
    Degree getAngle() const;
    void rotate(Degree angle);
    bool operator==(const Vector2D& vector) const
    {return this->x==vector.x && this->y==vector.y;}
    Vector2D operator+(const Vector2D& vector) const
    {return Vector2D(this->x+vector.x,this->y+vector.y);}
    Vector2D operator-(const Vector2D& vector) const
    {return Vector2D(this->x-vector.x,this->y+vector.y);}
    Vector2D operator*(const double t) const
    {return Vector2D(this->x*t,this->y*t);}
    static Meter_2 getScalarProduct(const Vector2D &vec1, const Vector2D &vec2);
};

#endif // UTILS_H
