#ifndef IMOVEABLE
#define IMOVEABLE

#include <SFML/System/Time.hpp>
#include <math.h>

#include "ipositionable.h"
#include "idirectionable.h"
#include "utils.h"

class iMoveable : public iPositionable, public iDirectionable
{
public:
    iMoveable(const Map& map, Position position, Direction direction, MeterPerSeconds maxVelocity, MeterPerSeconds_2 maxAccelration)
        : iPositionable(map, position), iDirectionable(direction), mMaxVelocity(fabs(maxVelocity)), mMaxAccelration(fabs(maxAccelration))
    {}

    void move(sf::Time timeDelta)
    {
        Vector2D currentMovementVector = this->getMovementVector(this->getDirection(),this->getCurrentMovedDistance(timeDelta));
        this->changePosition(currentMovementVector);
        if(hasToSlamOnTheBreaks())
        {
            mCurrentAccelration = mCurrentVelocity >= 0 ? -mMaxAccelration : mMaxAccelration;
        }
        this->updateVelocity(timeDelta);
    }

private:
    MeterPerSeconds mCurrentVelocity;
    MeterPerSeconds_2 mCurrentAccelration;
    const MeterPerSeconds mMaxVelocity;
    const MeterPerSeconds_2 mMaxAccelration;

    Meter getSlamOnTheBreaksDistance() const
    {
        return mMaxAccelration == 0.0 ? 0.0 : fabs(0.5 * mCurrentVelocity * mCurrentVelocity / mMaxAccelration); // s=-(1/2)(v0²/a)
    }

    bool hasToSlamOnTheBreaks() const
    {
        Vector2D stoppingMovementVector = getMovementVector(this->getDirection(),this->getSlamOnTheBreaksDistance());
        Position pointOfLastPossibleStop = this->getPosition().change(stoppingMovementVector);
        if(this->mMap.isBlockAt(pointOfLastPossibleStop.getXValue(),pointOfLastPossibleStop.getYValue()))
        {
            MapBlock mapBlock = this->mMap.getMapBlockAt(pointOfLastPossibleStop.getXValue(),pointOfLastPossibleStop.getYValue());
            return !mapBlock.isWalkable();
        }
        return true;
    }

    void updateVelocity(sf::Time timeDelta)
    {
        mCurrentVelocity = (mCurrentAccelration * timeDelta.asSeconds()) + mCurrentVelocity;
        if(fabs(mCurrentVelocity)>mMaxVelocity)
        {
            mCurrentVelocity = mCurrentVelocity >= 0 ? mMaxVelocity : -mMaxVelocity;
        }
    }

    Meter getCurrentMovedDistance(sf::Time timeDelta) const{
        return this->mCurrentVelocity * timeDelta.asSeconds();
    }

    static Vector2D getMovementVector(const Direction& direction, const Meter& distance) const
    {
        Vector2D directionUnitVector = direction.getUnitVector();
        return Vector2D(directionUnitVector.x * distance, directionUnitVector.y * distance);
    }
};

#endif // IMOVEABLE
