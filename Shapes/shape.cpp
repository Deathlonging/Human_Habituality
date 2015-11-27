#include "shape.h"

#include "rectangleshape.h"
#include "circleshape.h"

Shape::Shape(const Vector2D center) : iPositionable(center)
{
}

Shape::~Shape()
{

}

bool Shape::isColliding(const CircleShape &circle, const Shape::LineSegment &line)
{
    Vector2D a = line.getDirectionVector();
    Vector2D centerCircle = circle.getPosition();
    Vector2D b = centerCircle-line.getPositionVector();
    double t = Vector2D::getScalarProduct(a,b) / Vector2D::getScalarProduct(a,a);
    if(t<0)
    {
        t=0;
    }
    else if(t>1)
    {
        t=1;
    }
    Vector2D d = line.at(t);
    Vector2D vectorCenterCircleToNearestPoint = centerCircle-d;
    return vectorCenterCircleToNearestPoint.getAbsolute()<=circle.getRadius();
}

bool Shape::isColliding(const Shape::LineSegment &line1, const Shape::LineSegment &line2)
{
    const Meter xA1 = line1.StartPoint.getXValue();
    const Meter xA2 = line1.EndPoint.getXValue();
    const Meter yA1 = line1.StartPoint.getYValue();
    const Meter yA2 = line1.EndPoint.getYValue();
    const Meter xB1 = line2.StartPoint.getXValue();
    const Meter xB2 = line2.EndPoint.getXValue();
    const Meter yB1 = line2.StartPoint.getYValue();
    const Meter yB2 = line2.EndPoint.getYValue();
    const double denumerator = ((yB2-yB1)*(xA2-xA1))-((xB2-xB1)*(yA2-yA1));
    //Check if lines are parallel (numerator = 0)
    if(isDoubleNull(denumerator))
    {
        return false;
    }
    const double numeratorA = ((xB2-xB1)*(yA1-yB1))-((yB2-yB1)*(xA1-xB1));
    const double numeratorB = ((xA2-xA1)*(yA1-yB1))-((yA2-yA1)*(xA1-xB1));
    const double uA = numeratorA/denumerator;
    const double uB = numeratorB/denumerator;
    if((uA>1 || uA<0) || (uB>1 || uB<0))
    {
        return false;
    }
    return true;
}
