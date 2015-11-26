#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "SFML/Graphics/CircleShape.hpp"

#include "shape.h"

#define SHAPE_POINTS_OF_CIRCLE 50


class CircleShape : public Shape
{
public:
    using iPositionable::changePosition;
    CircleShape(const Vector2D center, const double radius);
    virtual ~CircleShape();
    double getRadius() const;
    Degree getRotation() const;
    void rotate(Degree angle);
    void setOutlineThickness(float thickness);
    void setFillColor(const sf::Color& color);
    void setOutlineColor(const sf::Color &color);
    void draw(sf::RenderTarget &target) const;
    bool isColliding(const CircleShape &circle) const;
    bool isColliding(const RectangleShape &rectangle) const;
    void changePosition(const double dx, const double dy);
private:
    sf::CircleShape mCircle;
};

#endif // CIRCLESHAPE_H
