#ifndef FEETMOVEMENT_H
#define FEETMOVEMENT_H

#include "Shapes/shape.h"
#include "utils.h"
#include "timeclass.h"

class FeetMovement
{
public:
    FeetMovement(Shape& leftFoot, Shape& rightFoot, const Time periodTime, const Meter maxDistanceFoot);
    void moveFeet(Time timeDelta, MeterPerSecond currentBodyVelocity, Vector2D currentDirectionUnitVector);
private:
    Meter getCurrentMaxFootDistance(MeterPerSecond currentBodyVelocity) const;
    Meter getNextDistanceLeftFoot(Meter currentMaxDistanceFoot) const;
    Shape& mLeftFoot;
    Shape& mRightFoot;
    const Time mPeriodTime;
    const Meter mMaxDistanceFoot;
    Time mCurrentTime;
    Meter mCurrentDistanceLeftFoot;
};

#endif // FEETMOVEMENT_H
