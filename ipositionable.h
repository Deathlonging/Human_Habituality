#ifndef IPOSITIONABLE
#define IPOSITIONABLE

class Position{
public:
    Position() : xValue(0.0), yValue(0.0)/*, zValue(0.0)*/
    {}
    Position(const double x, const double y/*, double z*/) : xValue(x), yValue(y)/*, zValue(z)*/
    {}
    void change(const double dx, const double dy/*, double dz*/){xValue+=dx;yValue+=dy;/*zValue+=dz;*/}

    double getXValue() const {return xValue;}
    double getYValue() const {return yValue;}
    //double getZValue() const {return zValue;}
    void setXValue(const double value){xValue = value;}
    void setYValue(const double value){yValue = value;}
    //void setZValue(double value){zValue = value;}

private:
    double xValue;
    double yValue;
    //double zValue;
};

class iPositionable {

protected:
    iPositionable(){}
    iPositionable(const Position position) : mPosition(position){}
    Position getPosition() const {return mPosition;}
    void setPosition(const Position position) {mPosition = position;}
    void changePosition(const double dx, const double dy/*, double dz*/)
    {mPosition.change(dx, dy/*, dz*/);}
private:
    Position mPosition;
};

#endif // IPOSITIONABLE
