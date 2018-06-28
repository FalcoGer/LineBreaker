#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "MainMenuGS.h"

class Game
{
public:
    Game();
    ~Game();

    void update(sf::Int64 deltaTime);
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event evnt);
    
    inline bool isEnd() { return gs == NULL; }
private:
    GameState* gs;
    float fps;
    sf::Text fpsText;
    sf::Font font;
};

