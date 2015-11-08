#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "iupdateable.h"
#include "idrawable.h"
//#include "mapview.h"
#include "ipositionable.h"

class MapView;

class MapObject : public iUpdateable, public iDrawable
{
public:
    MapObject(sf::RenderWindow &window, MapView& mapView);
    virtual Position getPosition() const=0;
protected:
    MapView& mMapView;
};

#endif // MAPOBJECT_H
