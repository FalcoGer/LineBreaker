#include "MenuItem.h"

void MenuItem::draw(sf::RenderWindow& window, sf::Vector2f pos, bool selected)
{
    text.setPosition(pos);
    text.setFillColor(selected ? sf::Color(0, 255, 0, 255) : sf::Color(255, 255, 255, 255));
    window.draw(text);
}

MenuItem::MenuItem(GameAction* action, std::string textString, const sf::Font* font)
{
    this->action = action;

    text.setFont(*font);
    text.setString(textString);
    text.setPosition(0.0f, 0.0f);
}


MenuItem::~MenuItem()
{
    if (action)
    {
        delete(action);
        action = NULL;
    }
}
