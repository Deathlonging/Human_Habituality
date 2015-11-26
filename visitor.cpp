#include "visitor.h"

#include <sstream>

#include "utils.h"
#include "debughandling.h"

Visitor::Visitor(MapView &mapView, const Vector2D position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock)
    : MoveableMapObject(mapView,position, direction, velocityMaxParameters, velocityProcessBlock), mBody(VisitorShape(position,direction))
{
    this->init();
    std::stringstream debugInformationMessage;
    debugInformationMessage << "Created Visitor(" << position.getXValue() << "," << position.getYValue() << ")";
    printInformation(debugInformationMessage.str());
}

Visitor::~Visitor()
{

}

void Visitor::init()
{
    this->mBody.init(sf::Color(50,50,50,100),sf::Color::Blue,sf::Color::Black);
}

void Visitor::draw(sf::RenderTarget &target) const
{
    mBody.draw(target);
}

void Visitor::update(sf::Time timeDelta)
{
    MoveableMapObject::update(timeDelta);
}

void Visitor::moveModel(const Vector2D moveVector)
{
    this->mBody.changePosition(moveVector);
}

void Visitor::setBlockSize(double blocksize)
{
    sBlockSize = blocksize;
}

double Visitor::sBlockSize = 0.0;


Visitor::VisitorShape::VisitorShape(Vector2D center, Direction direction)
    : GroupShape(center), mHead(CircleShape(center,VISITOR_SIZE_HEAD)),
      mLeftShoulder(CircleShape(center,VISITOR_SIZE_SHOULDER)), mRightShoulder(CircleShape(center,VISITOR_SIZE_SHOULDER)),
      mLeftFoot(CircleShape(center,VISITOR_SIZE_FOOT)), mRightFoot(CircleShape(center,VISITOR_SIZE_FOOT))
{
    mLeftShoulder.changePosition(VISITOR_SIZE_HEAD/2,0.0);
    mRightShoulder.changePosition(-VISITOR_SIZE_HEAD/2,0.0);
    mLeftFoot.changePosition(VISITOR_SIZE_HEAD/4,0.0);
    mRightFoot.changePosition(-VISITOR_SIZE_HEAD/4,0.0);
    this->addShape(mHead);
    this->addShape(mLeftShoulder);
    this->addShape(mRightShoulder);
    this->addShape(mLeftFoot);
    this->addShape(mRightFoot);
    this->rotate(direction.getRadianMeasure());
}

void Visitor::VisitorShape::moveFeet(Meter /*distance*/)
{

}

void Visitor::VisitorShape::init(sf::Color headColor, sf::Color shoulderColor, sf::Color footColor)
{
    mHead.setFillColor(headColor);
    mLeftShoulder.setFillColor(shoulderColor);
    mRightShoulder.setFillColor(shoulderColor);
    mLeftFoot.setFillColor(footColor);
    mRightFoot.setFillColor(footColor);
}
