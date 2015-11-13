#ifndef IDRAWABLE
#define IDRAWABLE

#include <SFML/Graphics.hpp>

class iDrawable{
public:
    virtual void draw(sf::RenderTarget& target) const=0;
protected:
    iDrawable()
    {}
};

#endif // IDRAWABLE

