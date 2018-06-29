#include "GameGS.h"

GameGS::GameGS()
    : GameState(GameState::EGameState::Game)
{
    gameBoard = new GameBoard(60, 40);
}


GameGS::~GameGS()
{
#if _DEBUG
    printf("GameGS @ %p destroy\n", this);
#endif
    if (gameBoard)
    {
        delete(gameBoard);
        gameBoard = NULL;
    }
}

void GameGS::draw(sf::RenderWindow & window)
{
    gameBoard->draw(window);
}

void GameGS::handleEvent(sf::Event evnt)
{
    switch (evnt.type)
    {
    case sf::Event::EventType::KeyPressed:
        switch (evnt.key.code)
        {
        case sf::Keyboard::Escape:
            this->setState(GameState::EGameState::MainMenu);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void GameGS::update(sf::Int64 deltaTime)
{
    gameBoard->update(deltaTime);

}