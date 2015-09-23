#include "map.h"

Map::Map(sf::RenderWindow &window) : iDrawable(window)
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
            mBlocks.emplace(std::pair<int,int>(xPos,yPos),MapBlock(mWindow,Position(xPos,yPos),MapBlock::Gras));
        }
    }
}

void Map::draw() const
{
    for(auto& block: mBlocks)
    {
        block.second.draw();
    }
}

double Map::getBlockSize()
{
    return MapBlock::getBlockSize();
}

