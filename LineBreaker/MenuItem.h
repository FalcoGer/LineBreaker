#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class MenuItem
{
public:
    void draw(sf::RenderWindow& window, sf::Vector2f pos, bool selected);
    inline void callCallback() { if (callback != NULL) { callback(); } }

    inline sf::FloatRect getRect() { return text.getGlobalBounds(); }

    MenuItem(void (*callback)(), std::string textString, const sf::Font* font);
    ~MenuItem();

private:
    // callback to what happens when the item is clicked (Function pointer, return type void, no arguments)
    void (*callback)();
    // the actual text
    sf::Text text;
};

