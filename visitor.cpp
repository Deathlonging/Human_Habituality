#include "visitor.h"

#include <sstream>

#include "utils.h"
#include "debughandling.h"

Visitor::Visitor(MapView &mapView, const Vector2D position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 velocityProcessBlock)
    : MoveableMapObject(mapView,position, direction, velocityMaxParameters, velocityProcessBlock), mBody(VisitorShape(position*sBlockSize,direction))
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
    this->mBody.init(VisitorShape::getHairColor(),VisitorShape::getShoulderColor(),Color::Black);
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

void Visitor::changeDirection(const Degree degree)
{
    iDirectionable::changeDirection(degree);
    this->mBody.rotate(degree);
}

void Visitor::setBlockSize(double blocksize)
{
    sBlockSize = blocksize;
}

double Visitor::sBlockSize = 0.0;


Visitor::VisitorShape::VisitorShape(const Vector2D center, Direction direction)
    : GroupShape(center), mHead(CircleShape(center,VISITOR_SIZE_HEAD/2)),
      mLeftShoulder(CircleShape(center,VISITOR_SIZE_SHOULDER/2)), mRightShoulder(CircleShape(center,VISITOR_SIZE_SHOULDER/2)),
      mLeftFoot(CircleShape(center,VISITOR_SIZE_FOOT/2)), mRightFoot(CircleShape(center,VISITOR_SIZE_FOOT/2))
{
    mLeftShoulder.changePosition(VISITOR_SIZE_HEAD/2,0.0);
    mRightShoulder.changePosition(-VISITOR_SIZE_HEAD/2,0.0);
    mLeftFoot.changePosition(VISITOR_SIZE_HEAD/4,0.0);
    mRightFoot.changePosition(-VISITOR_SIZE_HEAD/4,0.0);
    this->addShape(mLeftFoot);
    this->addShape(mRightFoot);
    this->addShape(mLeftShoulder);
    this->addShape(mRightShoulder);
    this->addShape(mHead);

    this->rotate(direction.getRadianMeasure());
}

void Visitor::VisitorShape::moveFeet(Meter /*distance*/)
{

}

void Visitor::VisitorShape::init(Color headColor, Color shoulderColor, Color footColor)
{
    mHead.setFillColor(headColor);
    mLeftShoulder.setFillColor(shoulderColor);
    mRightShoulder.setFillColor(shoulderColor);
    mLeftFoot.setFillColor(footColor);
    mRightFoot.setFillColor(footColor);
}

Color Visitor::VisitorShape::getHairColor()
{
    return sHairColors[getRandomValue(0,sCountOfHairColors-1)].getRef();
}

const Visitor::VisitorShape::cColorRef Visitor::VisitorShape::sHairColors[] = {
    Color::BrightYellow, Color::Yellow, Color::DarkYellow,
    Color::BrightBrown, Color::Brown, Color::DarkBrown,
    Color::BrightGrey, Color::Grey, Color::DarkGrey,
    Color::Black
};

const int Visitor::VisitorShape::sCountOfHairColors = 3*3 + 1;

Color Visitor::VisitorShape::getShoulderColor()
{
    return sShoulderColor[getRandomValue(0,sCountOfShoulderColors-1)].getRef();
}

const Visitor::VisitorShape::cColorRef Visitor::VisitorShape::sShoulderColor[] = {
    Color::BrightRed, Color::Red, Color::DarkRed,
    Color::BrightGreen, Color::Green, Color::DarkGreen,
    Color::BrightBlue, Color::Blue, Color::DarkBlue,
    Color::BrightYellow, Color::Yellow, Color::DarkYellow,
    Color::BrightCyan, Color::Cyan, Color::DarkCyan,
    Color::BrightViolet, Color::Violet, Color::DarkViolet,
    Color::BrightBrown, Color::Brown, Color::DarkBrown,
    Color::BrightGrey, Color::Grey, Color::DarkGrey
};

const int Visitor::VisitorShape::sCountOfShoulderColors = 8*3;
