#ifndef NONMOVEABLEMAPOBJECT_H
#define NONMOVEABLEMAPOBJECT_H

#include "mapobject.h"
#include "ipositionable.h"
#include "idirectionable.h"

class NonMoveableMapObject : public MapObject, public iPositionable, public iDirectionable
{
public:
    NonMoveableMapObject(MapView& mapView, const Vector2D position, const Direction direction);
    virtual Vector2D getPosition() const;
};

#endif // NONMOVEABLEMAPOBJECT_H
