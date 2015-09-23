#ifndef IUPDATEABLE
#define IUPDATEABLE

#include <SFML/System/Time.hpp>

class iUpdateable{
public:
    virtual void update(sf::Time timeDelta) = 0;
};

#endif // IUPDATEABLE

