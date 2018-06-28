#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(640, 400), "LineBreaker", sf::Style::Default);
	sf::Event evnt;
	while (window.isOpen())
	{
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
		}
		window.clear();
		window.display();
	}
    return EXIT_SUCCESS;
}

