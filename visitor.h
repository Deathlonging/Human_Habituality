#ifndef VISITOR_H
#define VISITOR_H

#include "map.h"
#include "idrawable.h"
#include "ipositionable.h"
#include "iupdateable.h"

#define VISITOR_TOTAL_MAX_VELOCITY 5
#define VISITOR_TOTAL_MIN_VELOCITY 1
#define VISITOR_TOTAL_MAX_ACCELRATION 2
#define VISITOR_TOTAL_MIN_ACCELRATION 0.2
#define VISITOR_SIZE 5

class Visitor : public iDrawable, public iPositionable, public iUpdateable
{
public:
    Visitor(sf::RenderWindow &window, const Map& map, const Position position);
    void draw() const;
    void update(sf::Time timeDelta);
    static void setBlockSize(double blocksize);
private:

    static double sBlockSize;
};

#endif // VISITOR_H
