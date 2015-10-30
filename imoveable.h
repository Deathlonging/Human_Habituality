#ifndef IMOVEABLE
#define IMOVEABLE

#include <SFML/System/Time.hpp>

#include "ipositionable.h"
#include "idirectionable.h"

class iMoveable : public iPositionable, public iDirectionable
{
public:
    iMoveable(const Map& map, Position position, Direction direction, double maxVelocity, double maxAccelration)
        : iPositionable(map, position), iDirectionable(direction), mMaxVelocity(maxVelocity), mMaxAccelration(mMaxAccelration)
    {}

    void move(sf::Time timeDelta)
    {
        Direction currentDirection = this->getDirection();
        Vector2D currentDirectionUnitVector = currentDirection.getUnitVector();

        double absDeltaDistance = (mCurrentVelocity * 1000) / timeDelta.asMilliseconds();
        Vector2D deltaDistanceVector(currentDirectionUnitVector.x * absDeltaDistance, currentDirectionUnitVector.y * absDeltaDistance);

        this->changePosition(deltaDistanceVector);
    }

private:
    double mCurrentVelocity;
    double mCurrentAccelration;
    const double mMaxVelocity;
    const double mMaxAccelration;
};

#endif // IMOVEABLE
