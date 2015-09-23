#ifndef POSITION
#define POSITION

class Position{
public:
    Position() : xValue(0.0), yValue(0.0)/*, zValue(0.0)*/
    {}
    Position(double x, double y/*, double z*/) : xValue(x), yValue(y)/*, zValue(z)*/
    {}
    void change(double dx, double dy/*, double dz*/){xValue+=dx;yValue+=dy;/*zValue+=dz;*/}

    double getXValue() const {return xValue;}
    double getYValue() const {return yValue;}
    //double getZValue() const {return zValue;}
    void setXValue(double value){xValue = value;}
    void setYValue(double value){yValue = value;}
    //void setZValue(double value){zValue = value;}

private:
    double xValue;
    double yValue;
    //double zValue;
};

#endif // POSITION

