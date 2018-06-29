#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "MainMenuGS.h"

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
};

