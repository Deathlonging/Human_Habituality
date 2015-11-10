#ifndef IDRAWABLE
#define IDRAWABLE

#include <SFML/Graphics.hpp>

class iDrawable{
public:
    virtual void draw() const=0;
protected:
    iDrawable(sf::RenderWindow& window) : mWindow(window)
    {}
    sf::RenderWindow& mWindow;
};

#endif // IDRAWABLE

