#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "SFML/Graphics/CircleShape.hpp"

#include "shape.h"

#define SHAPE_POINTS_OF_CIRCLE 50

class CircleShape : public Shape
{
public:
    CircleShape(const Vector2D center, const double radius);
    virtual ~CircleShape();
    double getRadius() const;
    Degree getRotation() const;
    void rotate(Degree angle);
    void draw(sf::RenderTarget &target) const;
    bool isColliding(const CircleShape &circle) const;
    bool isColliding(const RectangleShape &rectangle) const;
private:
    sf::CircleShape mCircle;
};

#endif // CIRCLESHAPE_H
