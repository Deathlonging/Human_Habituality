#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include "idrawable.h"
#include "ipositionable.h"

#define MAP_BLOCK_SIZE 10

class MapBlock : public iDrawable, public iPositionable
{
public:
    enum BlockType{
        Undefined=0,
        Gras,
        Tar,
        Wood
    };

    MapBlock(sf::RenderWindow& window, Position position, BlockType blockType);
    void draw() const;
    BlockType getBlockType() const;

    bool isWalkable() const;

    static double getBlockSize();
private:
    const BlockType mBlockType;
};

#endif // MAPBLOCK_H
