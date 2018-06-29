#include "MainMenuGS.h"

MainMenuGS::MainMenuGS(sf::Font* font)
    : GameState(GameState::EGameState::MainMenu)
{
    // create the menu here
    items.push_back(new MenuItem(NULL, "Start", font));
    items.push_back(new MenuItem(new ActionCoutExample(this, "Hello World!") , "Print Helloworld", font));
    items.push_back(new MenuItem(NULL, "Exit", font));
}


MainMenuGS::~MainMenuGS()
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

void MainMenuGS::draw(sf::RenderWindow& window)
{
    // draw all the menu items underneath each other
    sf::Vector2f pos((window.getSize().x / 3.0f), (window.getSize().y / 4.0f));
    for (int i = 0; i < items.size(); i++)
    {
        items[i]->draw(window, pos, i == selectedItem);
        pos.y += 32.0f;
    }
}

void MainMenuGS::handleEvent(sf::Event evnt)
{
    switch (evnt.type)
    {
    case sf::Event::EventType::KeyPressed:
    {
        switch (evnt.key.code)
        {
        case sf::Keyboard::Escape:      // set game mode to exit
            state = GameState::Exit;
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

void MainMenuGS::update(sf::Int64 deltaTime)
{
    // nothing to do, animation of cursor or suchlike that is dependent on time would go here
}
