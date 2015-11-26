#ifndef IMOVEABLE
#define IMOVEABLE

#include <SFML/System/Time.hpp>
#include <math.h>

#include "ipositionable.h"
#include "idirectionable.h"
#include "utils.h"
#include "controlelements.h"
///
/// \brief The iMoveable class
///
/// \note The Current Velocity is not avaible from outside. This only make sense if the moving object crashes.
/// Because it is not wanted that something crashes it is not implemented
class iMoveable : public iPositionable, public iDirectionable
{
public:
    struct VelocityParameterSet{
        VelocityParameterSet() : Velocity(0.0), Accelration(0.0), AngularVelocity(0.0), AngularAccelration(0.0) {}
        MeterPerSecond Velocity;
        MeterPerSecond_2 Accelration;
        DegreePerSecond AngularVelocity;
        DegreePerSecond_2 AngularAccelration;
    };

    iMoveable(const Vector2D position, const Direction::CardinalDirection direction, const VelocityParameterSet maxParameters, PT1 velocityProcessBlock)
        : iPositionable(position), iDirectionable(direction), mMaxParameters(maxParameters), mVelocityProcessBlock(velocityProcessBlock), mAngularVelocityProcessBlock(velocityProcessBlock)
    {}

    Vector2D move(sf::Time timeDelta)
    {
        Vector2D currentMovementVector = this->getMovementVector(this->getDirection(),this->getCurrentMovedDistance(timeDelta));
        this->changePosition(currentMovementVector);
        Degree currentTurningValue = this->getCurrentTurningDegree(timeDelta);
        this->changeDirection(currentTurningValue);
        this->updateMovement(timeDelta);
        return currentMovementVector;
    }
    MeterPerSecond getTargetVelocity() const {return mTargetParameters.Velocity;}
    void setTargetVelocity(const MeterPerSecond &targetVelocity) {mTargetParameters.Velocity=targetVelocity;}

//    MeterPerSecond_2 getTargetAccelration() const {return mTargetParameters.Accelration;}
//    void setTargetAccelration(const MeterPerSecond_2 &targetAccelration) {mTargetParameters.Accelration=targetAccelration;}

    DegreePerSecond getTargetAngularVelocity() const {return mTargetParameters.AngularVelocity;}
    void setTargetAngularVelocity(const DegreePerSecond &targetAngularVelocity) {mTargetParameters.AngularVelocity=targetAngularVelocity;}

//    DegreePerSecond_2 getTargetAngularAccelration() const {return mTargetParameters.AngularAccelration;}
//    void setTargetAngularAccelration(const DegreePerSecond_2 &targetAngularAccelration) {mTargetParameters.AngularAccelration=targetAngularAccelration;}

    MeterPerSecond getCurrentVelocity() const {return mCurrentParameters.Velocity;}
    MeterPerSecond_2 getCurrentAccelration() const {return mCurrentParameters.Accelration;}
    DegreePerSecond getCurrentAngularVelocity() const {return mCurrentParameters.AngularVelocity;}
    DegreePerSecond_2 getCurrentAngularAccelration() const {return mCurrentParameters.AngularAccelration;}

    Meter getEmergenyStopDistance() const
    {
        return mMaxParameters.Accelration == 0.0 ? 0.0 : fabs(0.5 * mCurrentParameters.Velocity * mCurrentParameters.Velocity / mMaxParameters.Accelration); // s=-(1/2)(v0²/a)
    }

private:
    VelocityParameterSet mCurrentParameters;
    const VelocityParameterSet mMaxParameters;
    VelocityParameterSet mTargetParameters;

    PT1 mVelocityProcessBlock;
    PT1 mAngularVelocityProcessBlock;

    void updateMovement(sf::Time timeDelta)
    {
        updateCurrentAccelration(timeDelta);
        updateCurrentVelocity(timeDelta);
    }

    void updateCurrentAccelration(sf::Time timeDelta)
    {
        //instant accelration;
        MeterPerSecond velocityDelta = mTargetParameters.Velocity - mCurrentParameters.Velocity;
        MeterPerSecond_2 accelrationDelta = mVelocityProcessBlock.ynext(timeDelta,velocityDelta);
        mCurrentParameters.Accelration += accelrationDelta;
        if(mCurrentParameters.Accelration > mMaxParameters.Accelration)
        {
            mCurrentParameters.Accelration = mMaxParameters.Accelration;
        }
        else if(mCurrentParameters.Accelration < -mMaxParameters.Accelration)
        {
            mCurrentParameters.Accelration = -mMaxParameters.Accelration;
        }
        //instant accelration;
        DegreePerSecond angularVelocityDelta = mTargetParameters.AngularVelocity - mCurrentParameters.AngularVelocity;
        DegreePerSecond_2 angularAccelrationDelta = mAngularVelocityProcessBlock.ynext(timeDelta,angularVelocityDelta);
        mCurrentParameters.AngularAccelration += angularAccelrationDelta;
        if(mCurrentParameters.AngularAccelration > mMaxParameters.AngularAccelration)
        {
            mCurrentParameters.AngularAccelration = mMaxParameters.AngularAccelration;
        }
        else if(mCurrentParameters.AngularAccelration < -mMaxParameters.AngularAccelration)
        {
            mCurrentParameters.AngularAccelration = -mMaxParameters.AngularAccelration;
        }
    }

    void updateCurrentVelocity(sf::Time timeDelta)
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

