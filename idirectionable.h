#ifndef IDIRECTIONABLE
#define IDIRECTIONABLE

struct Vector2D{
    double x;
    double y;
};

#include <math.h>

class Direction {
public:
    enum CardinalDirection {
        NoDirection = 0x00,
        North = 0x01,
        East = 0x02,
        South = 0x04,
        West = 0x08,
        NorthEast = 0x03,
        SouthEast = 0x06,
        SouthWest = 0x0C,
        NorthWest = 0x09
    };

    Direction(){}
    Direction(const double radianMeasure) : mRadianMeasure(radianMeasure) {}

    void change(double deltaRadianMeasure)
    {
        this->mRadianMeasure += deltaRadianMeasure;
        this->mRadianMeasure = fmod(mRadianMeasure,2*M_PI);
    }

    Vector2D getUnitVector() const
    {
        return Vector2D(sin(mRadianMeasure),cos(mRadianMeasure));
    }

    CardinalDirection getRoundedCardinalDirection() const
    {
        Vector2D unitVector = this->getUnitVector();
        CardinalDirection cardinalDirection = NoDirection;
        if(unitVector.y>0)
        {
            cardinalDirection |= North;
        }
        else if(unitVector.y<0)
        {
            cardinalDirection |= South;
        }
        if(unitVector.x>0)
        {
            cardinalDirection |= East;
        }
        else if(unitVector.x<0)
        {
            cardinalDirection |= West;
        }
        return cardinalDirection;
    }
    void setRadianMeasure(const CardinalDirection cardinalDirection)
    {
        switch(cardinalDirection)
        {
        case NoDirection:
        case North: mRadianMeasure = 0.0; break;
        case NorthEast: mRadianMeasure = M_PI_4; break;
        case East: mRadianMeasure = M_PI_2; break;
        case SouthEast: mRadianMeasure = M_PI_2 + M_PI_4; break;
        case South: mRadianMeasure = M_PI; break;
        case SouthWest: mRadianMeasure = M_PI + M_PI_4; break;
        case West: mRadianMeasure = M_PI + M_PI_2; break;
        case NorthWest: mRadianMeasure = M_PI + M_PI_2 + M_PI_4; break;
        default: printWarning("Unimplemented CardinalDirection : " + (int) cardinalDirection); break;
        }
    }
    double getRadianMeasure() const {return mRadianMeasure;}
    void setRadianMeasure(const double radianMeasure) {mRadianMeasure = radianMeasure;}

private:
    ///
    /// \brief mRadianMeasure
    ///
    /// \note zero Radian Measure means North direction
    ///
    double mRadianMeasure;
};

class iDirectionable {

protected:
    iDirectionable() : mDirection(Direction()) {}
    iDirectionable(const Direction direction) : mDirection(direction) {}
    Direction getDirection() const{return mDirection;}
    void setDirection(const Direction &direction){mDirection = direction;}

private:
    Direction mDirection;
};

#endif // IDIRECTIONABLE
