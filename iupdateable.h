#ifndef IUPDATEABLE
#define IUPDATEABLE

#include "timeclass.h"

class iUpdateable{
public:
    virtual void update(Time timeDelta) = 0;
};

#endif // IUPDATEABLE

