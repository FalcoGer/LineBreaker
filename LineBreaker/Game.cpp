#include "Game.h"

Game::Game()
{
    gs = new MainMenuGS(&font);
    font.loadFromFile("Resources/Fonts/Monospace.ttf");

    fps = 0.0f;
    fpsText.setFont(font);
    fpsText.setString(std::to_string(fps));
    fpsText.setFillColor(sf::Color(0, 128, 0, 255));
    fpsText.setPosition(16.0f, 16.0f);
    fpsText.setCharacterSize(10);
}


Game::~Game()
{
    if (!gs)
    {
        delete(gs);
        gs = NULL;
    }
}

void Game::update(sf::Int64 deltaTime)
{
    if (gs->hasGameStateChanged())
    {
        GameState::EGameState newState = gs->getState();
        // TODO: make safe
        delete(gs);
        gs = NULL;

        switch (newState)
        {
        case GameState::EGameState::Exit:
            break;
        case GameState::EGameState::MainMenu:
            gs = new MainMenuGS(&font);
        default:
            break;
        }
    }
    // fps = 1.0f / (static_cast<float>(deltaTime) * 1000000.0f);
    fps = 1000000.0f / static_cast<float>(deltaTime);
    fpsText.setString("FPS: " + to_string(fps));
    if (gs)
    {
        gs->update(deltaTime);
    }
}

void Game::draw(sf::RenderWindow& window)
{
    // draw game state
    if (gs)
    {
        gs->draw(window);
    }
    // draw fps counter
    window.draw(fpsText);
}

void Game::handleEvent(sf::Event evnt)
{
    if (gs)
    {
        gs->handleEvent(evnt);
    }
}
