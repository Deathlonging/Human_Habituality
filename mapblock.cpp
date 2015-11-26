#include "mapblock.h"
#include "debughandling.h"

#include <SFML/Graphics.hpp>

MapBlock::MapBlock(Position position, BlockType blockType) : iDrawable(), mPosition(position), mBlockType(blockType)
{

}

void MapBlock::draw(sf::RenderTarget &target) const
{
    sf::RectangleShape square(sf::Vector2f(MAP_BLOCK_SIZE,MAP_BLOCK_SIZE));
    sf::Color mapBlockColor;

    switch(mBlockType)
    {
    case Undefined: mapBlockColor = sf::Color::Black; break;
    case Gras: mapBlockColor = sf::Color(107,142,35); break;
    case Tar: mapBlockColor = sf::Color::Blue; break;
    case Wood: mapBlockColor = sf::Color::Red; break;
    default: printWarning("Unimplemented BlockType : " + (int) mBlockType); mapBlockColor = sf::Color::Cyan; break;
    }

    square.setFillColor(mapBlockColor);
    square.setPosition(sf::Vector2f(mPosition.x*getBlockSize(),mPosition.y*getBlockSize()));
    target.draw(square);
}

MapBlock::BlockType MapBlock::getBlockType() const
{
    return mBlockType;
}

bool MapBlock::isWalkable() const
{
    switch(mBlockType)
    {
    case Undefined: return false;
    case Gras:
    case Tar:
    case Wood: return true;
    default: printWarning("Unimplemented BlockType : " + (int) mBlockType); break;
    }
    return false;
}

double MapBlock::getBlockSize()
{
    return MAP_BLOCK_SIZE;
}


