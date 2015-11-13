#ifndef MAP_H
#define MAP_H

#include <map>

#include "idrawable.h"
#include "mapblock.h"
#include "utils.h"

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 50

class Map : public iDrawable
{
public:
    Map();
    void init();
    void load();
    void draw(sf::RenderTarget& target) const;

    int getMapSizeBlocksX() const;
    int getMapSizeBlocksY() const;

    bool isBlockAt(const double x, const double y) const;
    MapBlock getMapBlockAt(const double x, const double y) const;
    MapBlock getMapBlockAt(const Vector2D position) const;

    static double getBlockSize();
private:
    std::map<const MapBlock::Position,MapBlock> mBlocks;
};

#endif // MAP_H
