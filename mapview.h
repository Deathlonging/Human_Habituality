#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "map.h"

class MapView
{
public:
    MapView(const Map& map);

private:
    const Map& mMap;
};

#endif // MAPVIEW_H
