#ifndef IDIRECTIONABLE
#define IDIRECTIONABLE

#include <math.h>

#include "utils.h"
#include "debughandling.h"

#define DIRECTION_CARDINAL_ROUNDING_PRECISION 0.25
#define DEGREE_MAX 360.0

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

    CardinalDirection CombineCardinalDirections(CardinalDirection a, CardinalDirection b) const
    {return static_cast<CardinalDirection>(static_cast<int>(a) | static_cast<int>(b));}

    Direction(){}
    Direction(const Degree radianMeasure) : mRadianMeasure(radianMeasure) {}
    Direction(const CardinalDirection direction)
    {setRadianMeasure(direction);}

    void change(Degree deltaRadianMeasure)
    {
        this->mRadianMeasure += deltaRadianMeasure;
        this->mRadianMeasure = fmod(mRadianMeasure,DEGREE_MAX);
    }

    Vector2D getUnitVector() const
    {
        double radiant = mRadianMeasure * M_PI * 2 / DEGREE_MAX;
        return Vector2D(sin(radiant),-cos(radiant));
    }

    CardinalDirection getRoundedCardinalDirection() const
    {
        Vector2D unitVector = this->getUnitVector();
        CardinalDirection cardinalDirection = NoDirection;
        if(unitVector.y>DIRECTION_CARDINAL_ROUNDING_PRECISION)
        {
            cardinalDirection = CombineCardinalDirections(cardinalDirection,North);
        }
        else if(unitVector.y<-DIRECTION_CARDINAL_ROUNDING_PRECISION)
        {
            cardinalDirection = CombineCardinalDirections(cardinalDirection,South);
        }
        if(unitVector.x>DIRECTION_CARDINAL_ROUNDING_PRECISION)
        {
            cardinalDirection = CombineCardinalDirections(cardinalDirection,East);
        }
        else if(unitVector.x<-DIRECTION_CARDINAL_ROUNDING_PRECISION)
        {
            cardinalDirection = CombineCardinalDirections(cardinalDirection,West);
        }
        return cardinalDirection;
    }
    void setRadianMeasure(const CardinalDirection cardinalDirection)
    {
        switch(cardinalDirection)
        {
        case NoDirection:
        case North: mRadianMeasure = 0.0; break;
        case NorthEast: mRadianMeasure = 45.0; break;
        case East: mRadianMeasure = 90.0; break;
        case SouthEast: mRadianMeasure =  135.0; break;
        case South: mRadianMeasure = 180.0; break;
        case SouthWest: mRadianMeasure = 225.0; break;
        case West: mRadianMeasure = 270.0; break;
        case NorthWest: mRadianMeasure = 315.0; break;
        default: printWarning("Unimplemented CardinalDirection : " + (int) cardinalDirection); break;
        }
    }
    Degree getRadianMeasure() const {return mRadianMeasure;}
    void setRadianMeasure(const Degree radianMeasure) {mRadianMeasure = radianMeasure;}



private:
    ///
    /// \brief mRadianMeasure
    ///
    /// \note zero Radian Measure means North direction
    ///
    Degree mRadianMeasure;
};

class iDirectionable {

protected:
    iDirectionable() : mDirection(Direction()) {}
    iDirectionable(const Direction direction) : mDirection(direction) {}
    iDirectionable(const Direction::CardinalDirection direction) : mDirection(direction) {}
    Direction getDirection() const{return mDirection;}
    void setDirection(const Direction &direction){mDirection = direction;}

    void changeDirection(const Degree &degree){mDirection.change(degree);}

private:
    Direction mDirection;
};

#endif // IDIRECTIONABLE
