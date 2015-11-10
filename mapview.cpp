#include "mapview.h"

MapView::MapView(const Map& map, const std::list<MapObject *> &mapObjects) : mMap(map), mMapObjects(mapObjects)
{

}

bool MapView::isObjectAt(const Vector2D position) const
{
    bool foundObject = false;
    for(auto& mapObject: mMapObjects)
    {
        foundObject = mapObject->getPosition() == position;
        if(foundObject)
        {
            return true;
        }
    }
    return false;
}

