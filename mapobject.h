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
    MapObject(MapView& mapView);
    virtual ~MapObject();
    virtual Vector2D getPosition() const=0;
    float getSecondsSinceExistence() const;
protected:
    MapView& mMapView;
private:
    Time mTimeSinceExistence;
};

#endif // MAPOBJECT_H
