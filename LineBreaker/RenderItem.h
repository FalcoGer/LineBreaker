#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class RenderItem
{
public:
    inline RenderItem() {};
    inline ~RenderItem() {};

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::Int64 deltaTime) = 0;
};