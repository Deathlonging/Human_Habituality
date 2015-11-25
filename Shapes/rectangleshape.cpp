#include "rectangleshape.h"

#include "circleshape.h"

RectangleShape::RectangleShape(const Vector2D center, const double length, const double height)
    : Shape(center), mRectangle(sf::RectangleShape(sf::Vector2f(length,height)))
{

}

RectangleShape::~RectangleShape()
{

}

double RectangleShape::getLength() const
{
    return this->mRectangle.getSize().x;
}

double RectangleShape::getHeight() const
{
    return this->mRectangle.getSize().y;
}

void RectangleShape::getVertices(Vector2D vertices[]) const
{
    Vector2D halfLengthVector(0,this->getLength()/2);
    halfLengthVector.rotate(this->getRotation());
    Vector2D halfHeightVector(this->getHeight()/2,0);
    halfHeightVector.rotate(this->getRotation());
    vertices[0] = getPosition() + halfLengthVector + halfHeightVector;
    vertices[1] = getPosition() - halfLengthVector + halfHeightVector;
    vertices[2] = getPosition() + halfLengthVector - halfHeightVector;
    vertices[3] = getPosition() - halfLengthVector - halfHeightVector;
}

void RectangleShape::getBorderLines(Shape::LineSegment lines[]) const
{
    Vector2D vertices[4];
    getVertices(vertices);
    lines[0] = LineSegment(vertices[0], vertices[1]);
    lines[1] = LineSegment(vertices[1], vertices[2]);
    lines[2] = LineSegment(vertices[2], vertices[3]);
    lines[3] = LineSegment(vertices[3], vertices[0]);
}

Degree RectangleShape::getRotation() const
{
    return this->mRectangle.getRotation();
}

void RectangleShape::rotate(Degree angle)
{
    this->mRectangle.rotate(angle);
}

void RectangleShape::setOutlineThickness(float thickness)
{
    this->mRectangle.setOutlineThickness(thickness);
}

void RectangleShape::setFillColor(const sf::Color &color)
{
    this->mRectangle.setFillColor(color);
}

void RectangleShape::setOutlineColor(const sf::Color& color)
{
    this->mRectangle.setOutlineColor(color);
}

void RectangleShape::draw(sf::RenderTarget &target) const
{
    target.draw(this->mRectangle);
}

bool RectangleShape::isColliding(const RectangleShape &rectangle) const
{
    LineSegment linesRecA[4];
    this->getBorderLines(linesRecA);
    LineSegment linesRecB[4];
    rectangle.getBorderLines(linesRecB);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Shape::isColliding(linesRecA[i],linesRecB[j]))
            {
                return true;
            }
        }
    }
    return false;
}

bool RectangleShape::isColliding(const CircleShape &circle) const
{
    LineSegment lines[4];
    getBorderLines(lines);
    return Shape::isColliding(circle,lines[0]) ||
           Shape::isColliding(circle,lines[1]) ||
           Shape::isColliding(circle,lines[2]) ||
           Shape::isColliding(circle,lines[3]);
}
