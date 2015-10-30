#include "game.h"

#include <math.h>

#include "utils.h"
#include "debughandling.h"

Game::Game(sf::RenderWindow &window) : iDrawable(window), mMap(window), mGameTime(sf::Time::Zero)
{
    Visitor::setBlockSize(Map::getBlockSize());
    registerLogGameTime(&mGameTime);
}

void Game::init()
{
    mMap.init();
    createTestszenario();
}

void Game::update(sf::Time timeDelta)
{
    mGameTime += timeDelta;
    for(auto& visitor: mVisitors)
    {
        visitor->update();
    }
}

void Game::draw() const
{
    this->mMap.draw();
    for(auto& visitor: mVisitors)
    {
        visitor->draw();
    }
}

void Game::createTestszenario()
{
    for(int i=0;i<COUNT_OF_VISITORS;i++)
    {
        Position positionOfVisitor(Vector2D(getRandomValue(0,MAP_SIZE_X-1),getRandomValue(0,MAP_SIZE_Y-1)));
        Visitor* p_Visitor = new Visitor(mWindow,mMap,positionOfVisitor);
        mVisitors.push_back(p_Visitor);
    }
}

