#ifndef NONMOVEABLEMAPOBJECT_H
#define NONMOVEABLEMAPOBJECT_H

#include "mapobject.h"
#include "ipositionable.h"
#include "idirectionable.h"

class NonMoveableMapObject : public MapObject, public iPositionable, public iDirectionable
{
public:
    NonMoveableMapObject(MapView& mapView, const Position position, const Direction direction);
    virtual Position getPosition() const;
};

#endif // NONMOVEABLEMAPOBJECT_H
