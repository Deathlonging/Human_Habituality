#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "iupdateable.h"
#include "idrawable.h"

class MapObject : public iUpdateable, public iDrawable
{
public:
    MapObject(sf::RenderWindow &window);
};

#endif // MAPOBJECT_H
