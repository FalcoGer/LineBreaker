#include "MenuGS.h"

MenuGS::MenuGS(GameState::EGameState state)
    : GameState(state)
{
    animationCycle = 0;
    selectedItem = 0;
}

MenuGS::~MenuGS()
{
    // cleanup of the menu items created with new
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i])
        {
            delete(items[i]);
            items[i] = NULL;
        }
    }
    items.clear();
}

void MenuGS::draw(sf::RenderWindow & window)
{
    // draw all the menu items underneath each other
    sf::Vector2f pos((window.getSize().x / 3.0f), (window.getSize().y / 4.0f));
    for (int i = 0; i < items.size(); i++)
    {
        items[i]->draw(window, pos, i == selectedItem);
        pos.y += 32.0f;
    }
}

void MenuGS::handleEvent(sf::Event evnt)
{
    switch (evnt.type)
    {
    case sf::Event::EventType::KeyPressed:
    {
        switch (evnt.key.code)
        {
        case sf::Keyboard::Escape:      // set game mode to exit
            setState(GameState::Exit);
            break;
        case sf::Keyboard::Enter:       // call the callback for the currently selected item
            items[selectedItem]->callCallback();
            break;
        case sf::Keyboard::S:           // move one option down, loop from bottom to top
        case sf::Keyboard::Down:
            selectedItem = (selectedItem >= items.size() - 1) ? 0 : (selectedItem + 1);
            break;
        case sf::Keyboard::W:           // move one option up, loop from top to bottom
        case sf::Keyboard::Up:
            selectedItem = (selectedItem == 0) ? static_cast<unsigned int>(items.size() - 1) : (selectedItem - 1);
            break;
        default:
            break;
        }
        break;
    }// end keypress
    case sf::Event::EventType::MouseMoved:
    {
        // get mouse pos from time of event
        sf::Vector2f mousePos(static_cast<float>(evnt.mouseMove.x), static_cast<float>(evnt.mouseMove.y));
        for (int i = 0; i < items.size(); i++)
        {
            // if mouse over item, then select it
            if (items[i]->getRect().contains(mousePos))
            {
                selectedItem = i;
                break;
            }
        }
        break;
    } // end mouse moved
    case sf::Event::EventType::MouseButtonPressed:
    {
        if (evnt.mouseButton.button == sf::Mouse::Button::Left)
        {
            // get mouse pos from time of event
            sf::Vector2f mousePos(static_cast<float>(evnt.mouseButton.x), static_cast<float>(evnt.mouseButton.y));
            for (int i = 0; i < items.size(); i++)
            {
                // if mouse over item, then select it
                if (items[i]->getRect().contains(mousePos))
                {
                    selectedItem = i;
                    // and execute
                    items[selectedItem]->callCallback();
                    break;
                }
            }
            // note: if you put execute call here, the selected item will be
            // executed regardless of if the mouse is actually over it or not
        }
        break;
    } // end mouse button pressed
    default:
        break;
    }
}

void MenuGS::update(sf::Int64 deltaTime)
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
    for (int i = 0; i < items.size(); i++)
    {
        items[i]->setTextScale((i == selectedItem) ? newScale : 1.0f, 1.0f);
    }
}
