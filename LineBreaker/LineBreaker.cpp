#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"

const unsigned int MIN_FPS = 15;
const sf::Int64 MIN_DELTATIME = 1000000 / MIN_FPS;          // 10^6 microseconds in a second

using namespace std;

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "LineBreaker", sf::Style::Default);
    sf::Event evnt;
    sf::Clock clk;

    Game game;

    sf::Int64 deltaTime;
    while (window.isOpen())
    {
        deltaTime = clk.restart().asMicroseconds();
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::EventType::Closed:
                window.close();
            case sf::Event::EventType::KeyPressed:
                switch (evnt.key.code)
                {
                case sf::Keyboard::F4:
                    if (evnt.key.alt)
                    {
                        window.close();
                    }
                default:
                    break;
                }
            default:
                break;
            }
            game.handleEvent(evnt);
        }
        game.update(deltaTime);
        window.clear();
        game.draw(window);
        window.display();
        if (game.isEnd())
        {
            window.close();
        }
    }
    return EXIT_SUCCESS;
}

