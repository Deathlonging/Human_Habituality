#ifndef GAME_H
#define GAME_H

#include <list>

#include "idrawable.h"
#include "iupdateable.h"
#include "map.h"
#include "visitor.h"

#define FREQUENCE_OF_VISITOR_CREATE_CALLS 0.5
#define CHANCE_OF_CREATING_VISITOR_IN_PERCENT 3

class Game : public iDrawable, public iUpdateable
{
public:
    Game(sf::RenderWindow& window);
    void init();
    void update(sf::Time timeDelta);
    void draw() const;
private:
    Map mMap;
    std::list<Visitor*> mVisitors;
    sf::Time mGameTime;

    sf::Time mTimeSinceLastCreateVisitorCall;
    void createVisitor();
};

#endif // GAME_H
