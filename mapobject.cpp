#include "mapobject.h"

MapObject::MapObject(MapView &mapView)
    : iDrawable(), mMapView(mapView), mTimeSinceExistence(Time())
{

}

MapObject::~MapObject()
{

}

float MapObject::getSecondsSinceExistence() const
{
    return this->mTimeSinceExistence.asSeconds();
}

