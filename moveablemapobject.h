#ifndef MOVEABLEMAPOBJECT_H
#define MOVEABLEMAPOBJECT_H

#include "mapobject.h"
#include "imoveable.h"

class MoveableMapObject : public MapObject, public iMoveable
{
public:
    MoveableMapObject(sf::RenderWindow &window, MapView& mapView, const Position position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock);

    Position getPosition() const;
    void update(sf::Time timeDelta);
};

#endif // MOVEABLEMAPOBJECT_H
