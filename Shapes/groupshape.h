#ifndef GROUPSHAPE_H
#define GROUPSHAPE_H

#include <list>

#include "shape.h"

class GroupShape : public Shape
{
public:
    using iPositionable::changePosition;
    using iPositionable::setPosition;
    GroupShape(Vector2D center);
    virtual ~GroupShape();
    void addShape(Shape &shape);
    void rotate(Degree angle);
    Degree getRotation() const;
    void setOutlineThickness(float thickness);
    void setFillColor(const Color &color);
    void setOutlineColor(const Color &color);
    void draw(sf::RenderTarget &target) const;
    bool isColliding(const CircleShape& circle) const;
    bool isColliding(const RectangleShape &rectangle) const;
    void changePosition(const double dx, const double dy);
    void setPosition(const Vector2D position);
private:
    std::list<Shape*> mShapes;
    Degree mRotation;
};

#endif // GROUPSHAPE_H
