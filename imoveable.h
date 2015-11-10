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
    struct VelocityParameterSet{
        VelocityParameterSet() : Velocity(0), Accelration(0), AngularVelocity(0), AngularAccelration(0) {}
        MeterPerSecond Velocity;
        MeterPerSecond_2 Accelration;
        DegreePerSecond AngularVelocity;
        DegreePerSecond_2 AngularAccelration;
    };

    iMoveable(const Position position, const Direction::CardinalDirection direction, const VelocityParameterSet maxParameters)
        : iPositionable(position), iDirectionable(direction), mMaxParameters(maxParameters)
    {}

    void move(sf::Time timeDelta)
    {
        Vector2D currentMovementVector = this->getMovementVector(this->getDirection(),this->getCurrentMovedDistance(timeDelta));
        this->changePosition(currentMovementVector);
        Degree currentTurningValue = this->getCurrentTurningDegree(timeDelta);
        this->changeDirection(currentTurningValue);
        this->updateMovement(timeDelta);
    }

    MeterPerSecond getCurrentVelocity() const {return mCurrentParameters.Velocity;}
    void setCurrentVelocity(const MeterPerSecond &currentVelocity) {mCurrentParameters.Velocity=currentVelocity;}

    MeterPerSecond_2 getCurrentAccelration() const {return mCurrentParameters.Accelration;}
    void setCurrentAccelration(const MeterPerSecond_2 &currentAccelration) {mCurrentParameters.Accelration=currentAccelration;}

    DegreePerSecond getCurrentAngularVelocity() const {return mCurrentParameters.AngularVelocity;}
    void setCurrentAngularVelocity(const DegreePerSecond &currentAngularVelocity) {mCurrentParameters.AngularVelocity=currentAngularVelocity;}

    DegreePerSecond_2 getCurrentAngularAccelration() const {return mCurrentParameters.AngularAccelration;}
    void setCurrentAngularAccelration(const DegreePerSecond_2 &currentAngularAccelration) {mCurrentParameters.AngularAccelration=currentAngularAccelration;}

    Meter getSlamOnTheBreaksDistance() const
    {
        return mMaxParameters.Accelration == 0.0 ? 0.0 : fabs(0.5 * mCurrentParameters.Velocity * mCurrentParameters.Velocity / mMaxParameters.Accelration); // s=-(1/2)(v0²/a)
    }

private:
    VelocityParameterSet mCurrentParameters;
    const VelocityParameterSet mMaxParameters;

    void updateMovement(sf::Time timeDelta)
    {
        mCurrentParameters.Velocity += (mCurrentParameters.Accelration * timeDelta.asSeconds());
        if(fabs(mCurrentParameters.Velocity)>mMaxParameters.Velocity)
        {
            mCurrentParameters.Velocity = mCurrentParameters.Velocity >= 0 ? mMaxParameters.Velocity : -mMaxParameters.Velocity;
        }
        mCurrentParameters.AngularVelocity += (mCurrentParameters.AngularAccelration * timeDelta.asSeconds());
        if(fabs(mCurrentParameters.AngularVelocity)>mMaxParameters.AngularVelocity)
        {
            mCurrentParameters.AngularVelocity = mCurrentParameters.AngularVelocity >= 0 ? mMaxParameters.AngularVelocity : -mMaxParameters.AngularVelocity;
        }
    }

    Meter getCurrentMovedDistance(sf::Time timeDelta) const{
        return this->mCurrentParameters.Velocity * timeDelta.asSeconds();
    }

    Degree getCurrentTurningDegree(sf::Time timeDelta) const{
        return this->mCurrentParameters.AngularVelocity * timeDelta.asSeconds();
    }

    static Vector2D getMovementVector(const Direction& direction, const Meter& distance)
    {
        Vector2D directionUnitVector = direction.getUnitVector();
        return Vector2D(directionUnitVector.x * distance, directionUnitVector.y * distance);
    }
};

#endif // IMOVEABLE

