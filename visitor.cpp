#include "visitor.h"

#include <sstream>

#include "utils.h"
#include "debughandling.h"

Visitor::Visitor(MapView &mapView, const Position position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock)
    : MoveableMapObject(mapView,position, direction, velocityMaxParameters, velocityProcessBlock)
{
    std::stringstream debugInformationMessage;
    debugInformationMessage << "Created Visitor(" << position.getXValue() << "," << position.getYValue() << ")";
    printInformation(debugInformationMessage.str());
}

void Visitor::draw(sf::RenderTarget &target) const
{
    sf::CircleShape circle(VISITOR_SIZE);
    circle.setFillColor(sf::Color::Yellow);
    Position currentPosition = iPositionable::getPosition();
    circle.setPosition(sf::Vector2f(currentPosition.getXValue()*sBlockSize,currentPosition.getYValue()*sBlockSize));
    target.draw(circle);
}

void Visitor::update(sf::Time timeDelta)
{
    MoveableMapObject::update(timeDelta);
}

void Visitor::setBlockSize(double blocksize)
{
    sBlockSize = blocksize;
}

double Visitor::sBlockSize = 0.0;
