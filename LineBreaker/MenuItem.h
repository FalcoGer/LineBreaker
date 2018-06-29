#pragma once
#include "GameAction.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "RenderItem.h"

#define _USE_MATH_DEFINES
#include <math.h>

class MenuItem
    : public RenderItem
{
public:
    inline void callCallback() { if (action != NULL) { action->invoke(); } }

    inline sf::FloatRect getRect() { return text.getGlobalBounds(); }
    inline void setPos(sf::Vector2f pos) { text.setPosition(pos); }
    inline void setSelected(bool isSelected) { this->isSelected = isSelected; }

    MenuItem(GameAction* action, std::string textString, const sf::Font* font);
    ~MenuItem();

    void update(sf::Int64 deltaTime);
    void draw(sf::RenderWindow& window);
private:
    // callback to what happens when the item is clicked
    GameAction* action;
    // the actual text
    sf::Text text;
    sf::Int64 animationCycle;
    bool isSelected;
};

