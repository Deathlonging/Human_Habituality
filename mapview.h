#ifndef MAPVIEW_H
#define MAPVIEW_H


#include <list>

#include "map.h"
#include "mapobject.h"
#include "utils.h"

//class MapObject;

class MapView
{
public:
    MapView(const Map& map, const std::list<MapObject*>& mapObjects);
    bool isObjectAt(const Vector2D position) const;
private:
    const Map& mMap;
    const std::list<MapObject*>& mMapObjects;
};

#endif // MAPVIEW_H
