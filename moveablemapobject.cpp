#include "moveablemapobject.h"

MoveableMapObject::MoveableMapObject(sf::RenderWindow &window, MapView& mapView, const Position position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock)
    : MapObject(window, mapView), iMoveable(position, direction, velocityMaxParameters, velocityProcessBlock)
{

}

Position MoveableMapObject::getPosition() const
{
    return iMoveable::getPosition();
}

void MoveableMapObject::update(sf::Time timeDelta)
{
    this->move(timeDelta);
}

