#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class RenderItem
{
public:
    inline RenderItem() {};
    virtual inline ~RenderItem()
    {
#if _DEBUG
        printf("RenderItem @ %p destroy\n", this);
#endif
    }
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::Int64 deltaTime) = 0;
};