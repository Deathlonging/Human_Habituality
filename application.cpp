#include "application.h"

#include "debughandling.h"

Application::Application() : mMainWindow(), mGame(mMainWindow), mCurrentState(Undefined)
{
    setCurrentState(Initialization);
    //Shorten VideoMode because of Scrollbar and Mainbar at the top
    sf::VideoMode currentUsedVideoMode = sf::VideoMode::getDesktopMode();
    unsigned int videoModeWidth = currentUsedVideoMode.width - MAIN_WINDOW_INDENT_X - MAIN_WINDOW_INDENT_X;
    unsigned int videoModeHeight = currentUsedVideoMode.height - MAIN_WINDOW_INDENT_Y - MAIN_WINDOW_INDENT_Y;
    sf::VideoMode shortenedVideoMode = sf::VideoMode(videoModeWidth,videoModeHeight);
    mMainWindow.create(shortenedVideoMode,MAIN_WINDOW_TITLE);
}

void Application::init()
{
    mGame.init();
    setCurrentState(Running);
}

void Application::run()
{
    Clock clock;
    Time processingTimeDelta = Time::Zero;
    while(mMainWindow.isOpen())
    {
        processingTimeDelta = clock.getElapsedTime();
        clock.restart();
        if(processingTimeDelta > Time::Zero)
        {
            processInput();
            update(processingTimeDelta);
            draw();
        }
    }
}

void Application::processInput()
{

    sf::Event event;
    while(mMainWindow.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed: setCurrentState(Closing); break;
        default: printWarning("Unimplemented sf::Event : " + (int) event.type); break;
        }
    }
}

void Application::update(Time timeDelta)
{
    switch(mCurrentState)
    {
    case Initialization: init(); break;
    case Running: mGame.update(timeDelta); break;
    case Closing: close(); break;
    default: printWarning("Unimplemented State : " + (int) mCurrentState); break;
    }
}

void Application::draw()
{
    mMainWindow.clear();
    mGame.draw();
    mMainWindow.display();
}

void Application::setCurrentState(Application::State nextState)
{
    if(mCurrentState != nextState)
    {
        mCurrentState = nextState;
#define PROCESS_VAL(p) case(p): printInformation("New State: " + std::string(#p)); break;
        switch (nextState) {
        PROCESS_VAL(Undefined)
        PROCESS_VAL(Initialization)
        PROCESS_VAL(Running)
        PROCESS_VAL(Pause)
        PROCESS_VAL(Closing)
#undef PROCESS_VAL
        default: printWarning("Unimplemented Application::State : " + (int) nextState);break;
        }
    }
}

void Application::close()
{
    mMainWindow.close();
}

