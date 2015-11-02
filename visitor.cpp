#include "visitor.h"

#include <sstream>

#include "debughandling.h"

Visitor::Visitor(sf::RenderWindow& window, const Map &map, const Position position, const Direction direction, double maxVelocity, double maxAccelration) : MapObject(window), iMoveable(map,position,direction,maxVelocity,maxAccelration)
{
    std::stringstream debugInformationMessage;
    debugInformationMessage << "Created Visitor(" << position.getXValue() << "," << position.getYValue() << ")";
    printInformation(debugInformationMessage.str());
}

void Visitor::draw() const
{
    sf::CircleShape circle(VISITOR_SIZE);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(sf::Vector2f(getPosition().getXValue()*sBlockSize,getPosition().getYValue()*sBlockSize));
    mWindow.draw(circle);
}

void Visitor::update(sf::Time timeDelta)
{
    move(timeDelta);
}

void Visitor::setBlockSize(double blocksize)
{
    sBlockSize = blocksize;
}

double Visitor::sBlockSize = 0.0;
