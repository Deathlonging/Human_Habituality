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

private:
    Vector2D mPositionVector;
};

class iPositionable {

protected:
    iPositionable(const Map& map) : mMap(map){}
    iPositionable(const Map& map,const Position position) : mMap(map),mPosition(position){}
    Position getPosition() const {return mPosition;}
    void setPosition(const Position position) {mPosition = position;}

    bool isPositionWalkable(const Position position) const {
        MapBlock mapBlock = mMap.getMapBlockAt(position.getPositionVector());
        return mapBlock.isWalkable();
    }

    bool changePosition(const double dx, const double dy/*, double dz*/)
    {
        Position oldPosition = this->getPosition();
        mPosition.change(dx, dy/*, dz*/);
        if(isPositionWalkable(mPosition))
        {
            return true;
        }
        mPosition = oldPosition;
        return false;
    }
    bool changePosition(const Vector2D deltaDistance)
    {return this->changePosition(deltaDistance.x,deltaDistance.y);}

private:
    const Map& mMap;
    Position mPosition;
};

#endif // IPOSITIONABLE
