#include "game.h"

#include <math.h>

#include "visitor.h"
#include "utils.h"
#include "debughandling.h"
#include "mapview.h"

Game::Game(sf::RenderWindow &window) : iDrawable(window), mMap(window), mGameTime(sf::Time::Zero)
{
    registerLogGameTime(&mGameTime);
}

void Game::init()
{
    Visitor::setBlockSize(Map::getBlockSize());
    mMap.init();
    createTestszenario();
}

void Game::update(sf::Time timeDelta)
{
    mGameTime += timeDelta;
    for(auto& mapObject: mMapObjects)
    {
        mapObject->update(timeDelta);
    }
}

void Game::draw() const
{
    this->mMap.draw();
    for(auto& mapObject: mMapObjects)
    {
        mapObject->draw();
    }
}

void Game::createTestszenario()
{
    for(int i=0;i<COUNT_OF_VISITORS;i++)
    {
        Position positionOfVisitor(Vector2D(getRandomValue(0,MAP_SIZE_X-1),getRandomValue(0,MAP_SIZE_Y-1)));
        MoveableMapObject::VelocityParameterSet maxParameters;
        maxParameters.Velocity = 5.0;
        maxParameters.Accelration = 1.0;
        maxParameters.AngularVelocity = 20.0;
        maxParameters.AngularAccelration = 5.0;
        MapView mapView(mMap,mMapObjects);
        Visitor* p_Visitor = new Visitor(mWindow,mapView,positionOfVisitor,Direction::South,maxParameters,PT1(1.0,0.5));
        p_Visitor->setTargetVelocity((double)getRandomValue(0,500)/100);
        mMapObjects.push_back(p_Visitor);
    }
}

