#ifndef MOVEABLEMAPOBJECT_H
#define MOVEABLEMAPOBJECT_H

#include "mapobject.h"
#include "imoveable.h"

class MoveableMapObject : public MapObject, public iMoveable
{
public:
    MoveableMapObject(MapView& mapView, const Vector2D position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock);
    virtual ~MoveableMapObject();
    Vector2D getPosition() const;
    void update(sf::Time timeDelta);
    virtual void moveModel(const Vector2D moveVector) = 0;
};

#endif // MOVEABLEMAPOBJECT_H
