#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include "idrawable.h"

#define MAP_BLOCK_SIZE 10

class MapBlock : public iDrawable
{
public:
    struct Position {
        Position(const int x, const int y) : x(x), y(y){}
        const int x;
        const int y;
        bool operator==(const Position& pos) const {return x==pos.x && y==pos.y;}
        bool operator<(const Position& pos) const {return x<pos.x || (x==pos.x && y<pos.y);}
    };

    enum BlockType{
        Undefined=0,
        Gras,
        Tar,
        Wood
    };

    MapBlock(Position position, BlockType blockType);
    void draw(sf::RenderTarget& target) const;
    BlockType getBlockType() const;

    bool isWalkable() const;

    static double getBlockSize();
private:
    const Position mPosition;
    const BlockType mBlockType;
};

#endif // MAPBLOCK_H
