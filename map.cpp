#include "map.h"

#include "debughandling.h"

Map::Map() : iDrawable()
{
}

void Map::init()
{
    load();
}

void Map::load()
{
    for(int xPos=0; xPos<MAP_SIZE_X; xPos++)
    {
        for(int yPos=0; yPos<MAP_SIZE_Y; yPos++)
        {
            mBlocks.emplace(MapBlock::Position(xPos,yPos),MapBlock(MapBlock::Position(xPos,yPos),MapBlock::Gras));
        }
    }
}

void Map::draw(sf::RenderTarget &target) const
{
    for(auto& block: mBlocks)
    {
        block.second.draw(target);
    }
}

int Map::getMapSizeBlocksX() const
{
    return MAP_SIZE_X;
}

int Map::getMapSizeBlocksY() const
{
    return MAP_SIZE_Y;
}

bool Map::isBlockAt(const double x, const double y) const
{
    return mBlocks.find(MapBlock::Position(x,y)) != mBlocks.end();
}

MapBlock Map::getMapBlockAt(const double x, const double y) const
{
    double blockSize = MapBlock::getBlockSize();
    int xInt = x/blockSize;
    int yInt = y/blockSize;
    if(isBlockAt(xInt,yInt))
    {
        return mBlocks.at(MapBlock::Position(xInt,yInt));
    }
    else
    {
        printError("Checked for not existent Mapblock!");
        return MapBlock(MapBlock::Position(-1,-1),MapBlock::Undefined);
    }
}

MapBlock Map::getMapBlockAt(const Vector2D position) const
{
    return this->getMapBlockAt(position.x,position.y);
}

