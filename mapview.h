#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "map.h"

class MapView
{
public:
    MapView(Map& map);

private:
    Map& mMap;
};

#endif // MAPVIEW_H
