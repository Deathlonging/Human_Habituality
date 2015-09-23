#ifndef IDRAWABLE
#define IDRAWABLE

#include <SFML/Graphics.hpp>

class iDrawable{
public:
    iDrawable(sf::RenderWindow& window) : mWindow(window)
    {}
    virtual void draw() const=0;
protected:
    sf::RenderWindow& mWindow;
};

#endif // IDRAWABLE

