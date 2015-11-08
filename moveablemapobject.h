#ifndef MOVEABLEMAPOBJECT_H
#define MOVEABLEMAPOBJECT_H

#include "mapobject.h"
#include "imoveable.h"

class MoveableMapObject : public MapObject, public iMoveable
{
public:
    MoveableMapObject(sf::RenderWindow &window, MapView& mapView, const Position position, const Direction direction, const VelocityParameterSet velocityMaxParameters);
    void draw() const;
    void update(sf::Time timeDelta);

    Position getPosition() const;
};

#endif // MOVEABLEMAPOBJECT_H
