#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(640, 400), "Title", sf::Style::Default);
	sf::Event evnt;
	while (window.isOpen())
	{
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
			default:
				break;
			}
		}
		window.clear();
		window.display();
	}
    return 0;
}

