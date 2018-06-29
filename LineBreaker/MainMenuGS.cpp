#include "MainMenuGS.h"

MainMenuGS::MainMenuGS(sf::Font* font)
    : MenuGS(GameState::EGameState::MainMenu)
{
    // create the menu here
    items.push_back(new MenuItem(new ActionChangeGameState(this, GameState::EGameState::Game), "Start", font));
    items.push_back(new MenuItem(new ActionCoutExample(this, "Hello World!") , "Print Helloworld", font));
    items.push_back(new MenuItem(new ActionRandTest(this, 0.0f, 25.0f), "RNG Float Test", font));
    items.push_back(new MenuItem(new ActionChangeGameState(this, GameState::EGameState::Exit), "Exit", font));
}


MainMenuGS::~MainMenuGS()
{
#if _DEBUG
    printf("MainMenuGS @ %p destroy\n", this);
#endif
}