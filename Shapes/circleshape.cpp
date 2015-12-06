#include "circleshape.h"

#include "rectangleshape.h"

CircleShape::CircleShape(const Vector2D center, const double radius) : Shape(center), mCircle(sf::CircleShape(radius,SHAPE_POINTS_OF_CIRCLE))
{
    mCircle.setOrigin(radius,radius);
    mCircle.setPosition(center.getXValue(),center.getYValue());
}

CircleShape::~CircleShape()
{

}

double CircleShape::getRadius() const
{
    return this->mCircle.getRadius();
}

Degree CircleShape::getRotation() const
{
    return this->mCircle.getRotation();
}

void CircleShape::rotate(Degree angle)
{
    this->mCircle.rotate(angle);
}

void CircleShape::setOutlineThickness(float thickness)
{
    this->mCircle.setOutlineThickness(thickness);
}

void CircleShape::setFillColor(const Color &color)
{
    this->mCircle.setFillColor(color.toSFMLColor());
}

void CircleShape::setOutlineColor(const Color &color)
{
    this->mCircle.setOutlineColor(color.toSFMLColor());
}

void CircleShape::draw(sf::RenderTarget &target) const
{
    target.draw(this->mCircle);
}

bool CircleShape::isColliding(const CircleShape &circle) const
{
    Vector2D vectorCircle1 = this->getPosition();
    Vector2D vectorCircle2 = this->getPosition();
    Vector2D vectorOfCenters = vectorCircle1-vectorCircle2;
    Meter distanceOfCenters = vectorOfCenters.getAbsolute();
    return (this->getRadius()+circle.getRadius()) <= distanceOfCenters;
}

bool CircleShape::isColliding(const RectangleShape &rectangle) const
{
    return rectangle.isColliding(*this);
}

void CircleShape::changePosition(const double dx, const double dy)
{
    iPositionable::changePosition(dx,dy);
    this->mCircle.move(dx,dy);
}

void CircleShape::setPosition(const Vector2D position)
{
    iPositionable::setPosition(position);
    this->mCircle.setPosition(position.getXValue(),position.getYValue());
}

