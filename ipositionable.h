#ifndef IPOSITIONABLE
#define IPOSITIONABLE

#include "utils.h"
#include "map.h"

class iPositionable {
public:
    Vector2D getPosition() const {return mPosition;}
    void setPosition(const Vector2D position) {mPosition = position;}
protected:
    iPositionable(const Vector2D position) : mPosition(position){}

    void changePosition(const double dx, const double dy/*, double dz*/)
    {
        mPosition.change(dx, dy/*, dz*/);
    }
    void changePosition(const Vector2D deltaDistance)
    {this->changePosition(deltaDistance.x,deltaDistance.y);}

private:
    Vector2D mPosition;
};

#endif // IPOSITIONABLE
