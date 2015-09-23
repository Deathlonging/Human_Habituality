#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include "idrawable.h"
#include "position.h"

#define MAP_BLOCK_SIZE 10

class MapBlock : public iDrawable
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
    const Position mPosition;
    const BlockType mBlockType;
};

#endif // MAPBLOCK_H
