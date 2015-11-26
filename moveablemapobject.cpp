#include "moveablemapobject.h"

MoveableMapObject::MoveableMapObject(MapView& mapView, const Vector2D position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock)
    : MapObject(mapView), iMoveable(position, direction, velocityMaxParameters, velocityProcessBlock)
{

}

MoveableMapObject::~MoveableMapObject()
{

}

Vector2D MoveableMapObject::getPosition() const
{
    return iMoveable::getPosition();
}

void MoveableMapObject::update(sf::Time timeDelta)
{
    Vector2D movedVector = this->move(timeDelta);
    this->moveModel(movedVector);
}

