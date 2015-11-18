#include "groupshape.h"

#include "circleshape.h"
#include "rectangleshape.h"

GroupShape::GroupShape(Vector2D center) : Shape(center)
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
        p_shape->setPosition(this->getPosition() + centerToShape);
        p_shape->rotate(angle);
    }
}

Degree GroupShape::getRotation() const
{
    return mRotation;
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

