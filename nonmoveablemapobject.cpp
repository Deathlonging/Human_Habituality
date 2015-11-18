#include "nonmoveablemapobject.h"

NonMoveableMapObject::NonMoveableMapObject(MapView &mapView, const Vector2D position, const Direction direction)
    : MapObject(mapView), iPositionable(position), iDirectionable(direction)
{

}

Vector2D NonMoveableMapObject::getPosition() const
{
    return iPositionable::getPosition();
}

