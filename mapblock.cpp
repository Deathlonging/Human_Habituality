#include "mapblock.h"
#include "debughandling.h"
#include "color.h"

MapBlock::MapBlock(Position position, BlockType blockType)
    : iDrawable(), mPosition(position), mBlockType(blockType), mShape(sf::Vector2f(MAP_BLOCK_SIZE,MAP_BLOCK_SIZE))
{
    init(position);
}

void MapBlock::init(Position& position)
{

    Color mapBlockColor;

    switch(mBlockType)
    {
    case Undefined: mapBlockColor = Color::Black; break;
    case Gras: mapBlockColor = Color(107,142,35); break;
    case Tar: mapBlockColor = Color::Blue; break;
    case Wood: mapBlockColor = Color::Red; break;
    default: printWarning("Unimplemented BlockType : " + (int) mBlockType); mapBlockColor = Color::Cyan; break;
    }
    mShape.setFillColor(mapBlockColor.toSFMLColor());
    mShape.setPosition(sf::Vector2f(position.x*getBlockSize(),position.y*getBlockSize()));
}

void MapBlock::draw(sf::RenderTarget &target) const
{
    target.draw(mShape);
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


