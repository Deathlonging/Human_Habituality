#include "nonmoveablemapobject.h"

NonMoveableMapObject::NonMoveableMapObject(sf::RenderWindow &window, MapView &mapView, const Position position, const Direction direction)
    : MapObject(window, mapView), iPositionable(position), iDirectionable(direction)
{

}

Position NonMoveableMapObject::getPosition() const
{
    return iPositionable::getPosition();
}

