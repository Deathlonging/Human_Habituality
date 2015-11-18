#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics/RenderTarget.hpp>

#include "ipositionable.h"
#include "utils.h"

class CircleShape;
class RectangleShape;

class Shape : public iPositionable
{
public:
    Shape(const Vector2D center);
    virtual ~Shape();
    virtual void rotate(Degree angle) = 0;
    virtual Degree getRotation() const = 0;
    virtual bool isColliding(const CircleShape& circle) const = 0;
    virtual bool isColliding(const RectangleShape &rectangle) const = 0;
    virtual void draw(sf::RenderTarget& target) const = 0;
protected:
    struct LineSegment{
        LineSegment(){}
        LineSegment(Vector2D startpoint, Vector2D endpoint) : StartPoint(startpoint), EndPoint(endpoint){}
        Vector2D StartPoint;
        Vector2D EndPoint;
        Vector2D getPositionVector() const {return StartPoint;}
        Vector2D getDirectionVector() const {return EndPoint-StartPoint;}
        Vector2D at(Meter t) const {return StartPoint + (getDirectionVector()*t);}
    };

    static bool isColliding(const CircleShape &circle, const LineSegment &line);
    static bool isColliding(const LineSegment &line1, const LineSegment &line2);
};

#endif // SHAPE_H
