#pragma once
#include "GameAction.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


class MenuItem
{
public:
    void draw(sf::RenderWindow& window, sf::Vector2f pos, bool selected);
    inline void callCallback() { if (action != NULL) { action->invoke(); } }

    inline sf::FloatRect getRect() { return text.getGlobalBounds(); }

    MenuItem(GameAction* action, std::string textString, const sf::Font* font);
    ~MenuItem();

private:
    // callback to what happens when the item is clicked
    GameAction* action;
    // the actual text
    sf::Text text;
};

