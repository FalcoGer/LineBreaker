#include "MenuItem.h"

void MenuItem::draw(sf::RenderWindow& window)
{
    text.setFillColor(isSelected ? sf::Color(0, 255, 0, 255) : sf::Color(255, 255, 255, 255));
    window.draw(text);
}

MenuItem::MenuItem(GameAction* action, std::string textString, const sf::Font* font)
{
    this->action = action;

    text.setFont(*font);
    text.setString(textString);
    text.setPosition(0.0f, 0.0f);

    animationCycle = 0;
    isSelected = 0;
}


MenuItem::~MenuItem()
{
#if _DEBUG
    printf("MenuItem @ %p destroy\n", this);
#endif
    if (action)
    {
        delete(action);
        action = NULL;
    }
}

void MenuItem::update(sf::Int64 deltaTime)
{
    if (isSelected)
    {
        // animate selected item (pulse smaller and larger)
        animationCycle += deltaTime;
        const unsigned int cylcleTime = 1500000; // microseconds
        if (animationCycle >= cylcleTime)
        {
            animationCycle -= cylcleTime; // setting 0 would cause hicky animations
        }
        // multiply with 2*pi to get 1 full sine wave within 1 second range
        // then divide by cycle time to stretch it over the desired time frame
        float newScale = 1.0f + (sin(static_cast<float>(animationCycle) * static_cast<float>(2.0 * M_PI) / cylcleTime) / 8.0f);

        // apply animation
        this->text.setScale(newScale, 1.0f);
    }
    else
    {
        animationCycle = 0;
    }
}
