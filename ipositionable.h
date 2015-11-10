#ifndef IPOSITIONABLE
#define IPOSITIONABLE

#include "utils.h"
#include "map.h"

class Position{
public:
    Position() : mPositionVector(){}
    Position(const Vector2D startPosition) : mPositionVector(startPosition)
    {}

    void change(const double dx, const double dy/*, double dz*/){mPositionVector.x+=dx;mPositionVector.y+=dy;/*zValue+=dz;*/}
    void change(const Vector2D deltaDistance){this->change(deltaDistance.x,deltaDistance.y);}

    double getXValue() const {return mPositionVector.x;}
    double getYValue() const {return mPositionVector.y;}

    Vector2D getPositionVector() const {return this->mPositionVector;}
    //double getZValue() const {return zValue;}
    void setXValue(const double value){mPositionVector.x = value;}
    void setYValue(const double value){mPositionVector.y = value;}
    //void setZValue(double value){zValue = value;}

    bool operator ==(const Position& position) const {return mPositionVector==position.getPositionVector();}

private:
    Vector2D mPositionVector;
};

class iPositionable {
public:
    Position getPosition() const {return mPosition;}
protected:
    iPositionable(const Position position) : mPosition(position){}
    void setPosition(const Position position) {mPosition = position;}

    void changePosition(const double dx, const double dy/*, double dz*/)
    {
        mPosition.change(dx, dy/*, dz*/);
    }
    void changePosition(const Vector2D deltaDistance)
    {this->changePosition(deltaDistance.x,deltaDistance.y);}

private:
    Position mPosition;
};

#endif // IPOSITIONABLE
