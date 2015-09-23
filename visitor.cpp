#include "visitor.h"

#include <sstream>

#include "debughandling.h"

Visitor::Visitor(sf::RenderWindow& window, const Position position) : iDrawable(window), iPositionable(position)
{
    std::stringstream debugInformationMessage;
    debugInformationMessage << "Created Visitor(" << position.getXValue() << "," << position.getYValue() << ")";
    printInformation(debugInformationMessage.str());
}

void Visitor::draw() const
{
    sf::CircleShape circle(VISITOR_SIZE);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(sf::Vector2f(mPosition.getXValue()*sBlockSize,mPosition.getYValue()*sBlockSize));
    mWindow.draw(circle);
}

void Visitor::update(sf::Time timeDelta)
{

}

void Visitor::setBlockSize(double blocksize)
{
    sBlockSize = blocksize;
}

double Visitor::sBlockSize = 0.0;
