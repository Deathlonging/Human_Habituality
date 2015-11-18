#ifndef GAME_H
#define GAME_H

#include <list>

#include "idrawable.h"
#include "iupdateable.h"
#include "map.h"
#include "mapobject.h"

#define COUNT_OF_VISITORS 10

class Game : public iUpdateable
{
public:
    Game(sf::RenderWindow& window);
    ~Game();
    void init();
    void update(sf::Time timeDelta);
    void draw() const;
private:
    Map mMap;
    std::list<MapObject*> mMapObjects;
    sf::Time mGameTime;
    sf::RenderWindow& mWindow;

    void createTestszenario();
};

#endif // GAME_H
