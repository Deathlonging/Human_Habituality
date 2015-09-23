#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "iupdateable.h"
#include "idrawable.h"
#include "game.h"

#define MAIN_WINDOW_INDENT_X 40
#define MAIN_WINDOW_INDENT_Y 40
#define MAIN_WINDOW_TITLE "Human Habituality"

class Application : public iUpdateable
{
public:
    Application();
    void init();
    void run();
    void processInput();
    void update(sf::Time timeDelta);
    void draw();
private:
    enum State {
        Undefined = 0,
        Initialization,
        Running,
        Pause,
        Closing
    };

    sf::RenderWindow mMainWindow;
    Game mGame;
    State mCurrentState;

    void setCurrentState(State nextState);
    void close();
};

#endif // APPLICATION_H
