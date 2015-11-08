#ifndef VISITOR_H
#define VISITOR_H

#include "moveablemapobject.h"

#define VISITOR_TOTAL_MAX_VELOCITY 5
#define VISITOR_TOTAL_MIN_VELOCITY 1
#define VISITOR_TOTAL_MAX_ACCELRATION 2
#define VISITOR_TOTAL_MIN_ACCELRATION 0.2
#define VISITOR_SIZE 5

class Visitor : public MoveableMapObject
{
public:
    Visitor(sf::RenderWindow &window, MapView &mapView, const Position position, const Direction direction, const VelocityParameterSet velocityMaxParameters);
    void draw() const;
    void update(sf::Time timeDelta);
    static void setBlockSize(double blocksize);
private:

    static double sBlockSize;
};

#endif // VISITOR_H
