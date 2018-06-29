#include "MainMenuGS.h"

MainMenuGS::MainMenuGS(sf::Font* font)
    : MenuGS(GameState::EGameState::MainMenu)
{
    // create the menu here
    items.push_back(new MenuItem(NULL, "Start", font));
    items.push_back(new MenuItem(new ActionCoutExample(this, "Hello World!") , "Print Helloworld", font));
    items.push_back(new MenuItem(new ActionChangeGameState(this, GameState::EGameState::Exit), "Exit", font));
}


MainMenuGS::~MainMenuGS()
{
}