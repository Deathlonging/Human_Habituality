#include "groupshape.h"

#include "circleshape.h"
#include "rectangleshape.h"

GroupShape::GroupShape(Vector2D center) : Shape(center), mRotation(0.0)
{

}

GroupShape::~GroupShape()
{
}

void GroupShape::addShape(Shape& shape)
{
    mShapes.push_back(&shape);
}

void GroupShape::rotate(Degree angle)
{
    mRotation += angle;
    for(Shape* p_shape : mShapes)
    {
        Vector2D centerToShape = p_shape->getPosition() - this->getPosition();
        centerToShape.rotate(angle);
        Vector2D newCenter = this->getPosition() + centerToShape;
        p_shape->setPosition(newCenter);
        p_shape->rotate(angle);
    }
}

Degree GroupShape::getRotation() const
{
    return mRotation;
}

void GroupShape::setOutlineThickness(float thickness)
{
    for(Shape* p_shape : mShapes)
    {
        p_shape->setOutlineThickness(thickness);
    }
}

void GroupShape::setFillColor(const sf::Color &color)
{
    for(Shape* p_shape : mShapes)
    {
        p_shape->setFillColor(color);
    }
}

void GroupShape::setOutlineColor(const sf::Color &color)
{
    for(Shape* p_shape : mShapes)
    {
        p_shape->setOutlineColor(color);
    }
}

void GroupShape::draw(sf::RenderTarget &target) const
{
    for(Shape* p_shape : mShapes)
    {
        p_shape->draw(target);
    }
}

bool GroupShape::isColliding(const CircleShape &circle) const
{
    for(Shape* p_shape : mShapes)
    {
        if(p_shape->isColliding(circle))
        {
            return true;
        }
    }
    return false;
}

bool GroupShape::isColliding(const RectangleShape &rectangle) const
{
    for(Shape* p_shape : mShapes)
    {
        if(p_shape->isColliding(rectangle))
        {
            return true;
        }
    }
    return false;
}

void GroupShape::changePosition(const double dx, const double dy)
{
    iPositionable::changePosition(dx,dy);
    for(Shape* p_Shape : mShapes)
    {
        p_Shape->changePosition(dx,dy);
    }
}

void GroupShape::setPosition(const Vector2D position)
{
    iPositionable::setPosition(position);
    for(Shape* p_Shape : mShapes)
    {
        p_Shape->setPosition(position);
    }
}

