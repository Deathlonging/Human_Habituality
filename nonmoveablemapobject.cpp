#include "nonmoveablemapobject.h"

NonMoveableMapObject::NonMoveableMapObject(MapView &mapView, const Position position, const Direction direction)
    : MapObject(mapView), iPositionable(position), iDirectionable(direction)
{

}

Position NonMoveableMapObject::getPosition() const
{
    return iPositionable::getPosition();
}

