#include "moveablemapobject.h"

MoveableMapObject::MoveableMapObject(sf::RenderWindow &window, MapView& mapView, const Position position, const Direction direction, const VelocityParameterSet velocityMaxParameters)
    : MapObject(window, mapView), iMoveable(position, direction, velocityMaxParameters)
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

