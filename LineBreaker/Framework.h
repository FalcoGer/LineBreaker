#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "GameGS.h"
//#include "MainMenuGS.h"
#include "RandomNumberGenerator.h"

class Framework
{
public:
    Framework(string title, sf::VideoMode vm = sf::VideoMode(800, 600));
    ~Framework();

    void run();

    void update(sf::Int64 deltaTime);
    void draw();
    // returns true if event handled, false otherwise
    bool handleEvent(sf::Event evnt);
    
    inline bool isEnd() { return gs == NULL; }

    static float getRandomFloat(float min, float max);
    static long int getRandomLong(long int min, long int max);
private:
    sf::RenderWindow window;
    sf::Clock clk;
    sf::Text fpsText;
    float fps;

    // video modes for nonFullscreen and for fullscreen
    bool isFullscreen;
    sf::VideoMode vmNonFS;
    sf::VideoMode vmFS;

    static const sf::Int32 styleNonFS = sf::Style::Default;
    static const sf::Int32 styleFS = sf::Style::None;

    string title;

    GameState* gs;
    sf::Font font;

    static RandomNumberGenerator<long int> RndGenLong;
    static RandomNumberGenerator<float> RndGenFloat;
};

