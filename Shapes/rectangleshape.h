#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "SFML/Graphics/RectangleShape.hpp"

#include "shape.h"

class RectangleShape : public Shape
{
public:
    using iPositionable::changePosition;
    using iPositionable::setPosition;
    RectangleShape(const Vector2D center, const double length, const double height);
    virtual ~RectangleShape();
    double getLength() const;
    double getHeight() const;
    void getVertices(Vector2D vertices[]) const;
    void getBorderLines(LineSegment lines[]) const;
    Degree getRotation() const;
    void rotate(Degree angle);
    void setOutlineThickness(float thickness);
    void setFillColor(const Color& color);
    void setOutlineColor(const Color &color);
    void draw(sf::RenderTarget &target) const;
    bool isColliding(const RectangleShape &rectangle) const;
    bool isColliding(const CircleShape &circle) const;
    void changePosition(const double dx, const double dy);
    void setPosition(const Vector2D position);
private:
    sf::RectangleShape mRectangle;
};

#endif // RECTANGLESHAPE_H
