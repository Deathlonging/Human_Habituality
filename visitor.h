#ifndef VISITOR_H
#define VISITOR_H

#include "moveablemapobject.h"
#include "Shapes/circleshape.h"
#include "Shapes/groupshape.h"

#define VISITOR_TOTAL_MAX_VELOCITY 5
#define VISITOR_TOTAL_MIN_VELOCITY 1
#define VISITOR_TOTAL_MAX_ACCELRATION 2
#define VISITOR_TOTAL_MIN_ACCELRATION 0.2

#define VISITOR_SIZE_HEAD 16
#define VISITOR_SIZE_SHOULDER 10
#define VISITOR_SIZE_FOOT 8

class Visitor : public MoveableMapObject
{
public:
    Visitor(MapView &mapView, const Vector2D position, const Direction::CardinalDirection direction, const VelocityParameterSet velocityMaxParameters, PT1 VelocityProcessBlock);
    virtual ~Visitor();
    void init();
    void draw(sf::RenderTarget& target) const;
    void update(sf::Time timeDelta);
    void moveModel(const Vector2D moveVector);
    static void setBlockSize(double blocksize);
private:

    static double sBlockSize;

    class VisitorShape : public GroupShape
    {
    public:
        VisitorShape(Vector2D center, Direction direction);
        void moveFeet(Meter distance);
        void init(sf::Color headColor, sf::Color shoulderColor, sf::Color footColor);
    private:
        CircleShape mHead;
        CircleShape mLeftShoulder;
        CircleShape mRightShoulder;
        CircleShape mLeftFoot;
        CircleShape mRightFoot;
    };

    VisitorShape mBody;
};

#endif // VISITOR_H
