#ifndef IPOSITIONABLE
#define IPOSITIONABLE

#include "position.h"

class iPositionable {

public:
    iPositionable(){}
    iPositionable(const Position position) : mPosition(position){}
    Position getPosition() const {return mPosition;}
    void setPosition(const Position &position) {mPosition = position;}
    void changePosition(double dx, double dy/*, double dz*/)
    {mPosition.change(dx, dy/*, dz*/);}
protected:
    Position mPosition;
};

#endif // IPOSITIONABLE
