#ifndef MAP_H
#define MAP_H

#include <map>

#include "idrawable.h"
#include "mapblock.h"

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 50

class Map : public iDrawable
{
public:
    Map(sf::RenderWindow& window);
    void init();
    void load();
    void draw() const;

    static double getBlockSize();
private:
    std::map<const std::pair<int,int>,MapBlock> mBlocks;
};

#endif // MAP_H
