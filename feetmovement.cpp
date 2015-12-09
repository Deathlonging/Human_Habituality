#include "feetmovement.h"

FeetMovement::FeetMovement(Shape &leftFoot, Shape &rightFoot, const Time periodTime, const Meter maxDistanceFoot)
    : mLeftFoot(leftFoot), mRightFoot(rightFoot), mPeriodTime(periodTime), mMaxDistanceFoot(maxDistanceFoot), mCurrentTime(Time::Zero), mCurrentDistanceLeftFoot(0.0)
{

}

void FeetMovement::moveFeet(Time timeDelta, MeterPerSecond currentBodyVelocity, Vector2D currentDirectionUnitVector)
{
    if(isDoubleNull(currentBodyVelocity))
    {
        mCurrentTime=Time::Zero;
        mCurrentDistanceLeftFoot=0.0;
        return;
    }

    Meter currentMaxDistanceFoot = getCurrentMaxFootDistance(currentBodyVelocity);
    mCurrentTime += timeDelta;
    mCurrentTime = mCurrentTime > mPeriodTime ? mPeriodTime - mCurrentTime : mCurrentTime;
    Meter nextDistanceLeftFoot = getNextDistanceLeftFoot(currentMaxDistanceFoot);
    Meter diffDistanceLeftFoot = nextDistanceLeftFoot - mCurrentDistanceLeftFoot;
    mCurrentDistanceLeftFoot = nextDistanceLeftFoot;
    Vector2D diffMoveVectorLeftFoot = currentDirectionUnitVector * diffDistanceLeftFoot;
    mLeftFoot.changePosition(diffMoveVectorLeftFoot);
    mRightFoot.changePosition(diffMoveVectorLeftFoot * -1);
}

Meter FeetMovement::getCurrentMaxFootDistance(MeterPerSecond currentBodyVelocity) const
{
    return currentBodyVelocity;
}

Meter FeetMovement::getNextDistanceLeftFoot(Meter currentMaxDistanceFoot) const
{
    Radiant processStatus = (mCurrentTime/mPeriodTime) * M_PI * 2;
    return currentMaxDistanceFoot * cos(processStatus);
}

