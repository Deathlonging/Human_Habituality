#ifndef CONTROLELEMENTS
#define CONTROLELEMENTS

#include "timeclass.h"

class PT1{
public:
    PT1(double k, double t,double y0=0.0) : mK(k), mT(t), mYLast(y0) {}
    double ynext(Time timeDelta, double u)
    {
        const double t_tmp = mT/timeDelta.asSeconds();
        mYLast = (1/(1+t_tmp)) * (mK*u + (t_tmp * mYLast));
        return mYLast;
    }
private:
    const double mK;
    const double mT;
    double mYLast;
};

#endif // CONTROLELEMENTS

