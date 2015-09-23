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
}

void Game::update(sf::Time timeDelta)
{
    mGameTime += timeDelta;
    mTimeSinceLastCreateVisitorCall += timeDelta;
    if(mTimeSinceLastCreateVisitorCall.asSeconds() > ((float)1/FREQUENCE_OF_VISITOR_CREATE_CALLS))
    {
        createVisitor();
        mTimeSinceLastCreateVisitorCall = sf::Time::Zero;
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

void Game::createVisitor()
{
    if(getRandomValue(0,100)<=CHANCE_OF_CREATING_VISITOR_IN_PERCENT)
    {
        Position positionOfVisitor(getRandomValue(0,MAP_SIZE_X-1),getRandomValue(0,MAP_SIZE_Y-1));
        Visitor* p_Visitor = new Visitor(mWindow,positionOfVisitor);
        mVisitors.push_back(p_Visitor);
    }
}

