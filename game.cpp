#include "game.h"

#include <math.h>

#include "visitor.h"
#include "utils.h"
#include "debughandling.h"
#include "mapview.h"

Game::Game(sf::RenderWindow &window) : mMap(), mGameTime(sf::Time::Zero), mWindow(window)
{
    registerLogGameTime(&mGameTime);
}

Game::~Game()
{
    for(MapObject* p_MapObject : mMapObjects)
    {
        delete p_MapObject;
        p_MapObject = nullptr;
    }
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
    this->mMap.draw(mWindow);
    for(auto& mapObject: mMapObjects)
    {
        mapObject->draw(mWindow);
    }
}

void Game::createTestszenario()
{
    for(int i=0;i<COUNT_OF_VISITORS;i++)
    {
        Vector2D positionOfVisitor(getRandomValue(0,MAP_SIZE_X-1),getRandomValue(0,MAP_SIZE_Y-1));
        MoveableMapObject::VelocityParameterSet maxParameters;
        maxParameters.Velocity = 15.0;
        maxParameters.Accelration = 5.0;
        maxParameters.AngularVelocity = 20.0;
        maxParameters.AngularAccelration = 5.0;
        MapView mapView(mMap,mMapObjects);
        Visitor* p_Visitor = new Visitor(mapView,positionOfVisitor,Direction::South,maxParameters,PT1(1.0,0.5));
        p_Visitor->setTargetVelocity((double)getRandomValue(0,1500)/100);
        mMapObjects.push_back(p_Visitor);
    }
}

