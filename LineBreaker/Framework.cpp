#include "Framework.h"


Framework::Framework(string title, sf::VideoMode vm)
{
    font.loadFromFile("Resources/Fonts/Monospace.ttf");

    fps = 0.0f;
    fpsText.setFont(font);
    fpsText.setString(std::to_string(fps));
    fpsText.setFillColor(sf::Color(0, 128, 0, 255));
    fpsText.setPosition(16.0f, 16.0f);
    fpsText.setCharacterSize(10);

    isFullscreen = false;
    vmNonFS = vm;
    vmFS = sf::VideoMode::getDesktopMode();

    this->title = title;

    window.create(vmNonFS, this->title, styleNonFS);
    gs = new MainMenuGS(&font);
}


Framework::~Framework()
{
    if (!gs)
    {
        delete(gs);
        gs = NULL;
    }
    window.close();
}

void Framework::run()
{
    sf::Event evnt;
    while (window.isOpen())
    {
        update(clk.restart().asMicroseconds());
        if (gs)
        {
            while (window.pollEvent(evnt))
            {
                if (!handleEvent(evnt))
                {
                    gs->handleEvent(evnt);
                }
            }
            window.clear();
            draw();
            window.display();
        }
        else
        {
            window.close();
        }
    }
}


void Framework::update(sf::Int64 deltaTime)
{
    if (gs->hasGameStateChanged())
    {
        GameState::EGameState newState = gs->getState();
        delete(gs);
        gs = NULL;

        switch (newState)
        {
        case GameState::EGameState::Exit:
            break;
        case GameState::EGameState::MainMenu:
            gs = new MainMenuGS(&font);
        case GameState::EGameState::Game:
            gs = new MainMenuGS(&font);
        default:
            break;
        }
    }
    else
    {
        // fps = 1.0f / (static_cast<float>(deltaTime) * 1000000.0f);
        fps = 1000000.0f / static_cast<float>(deltaTime);
        fpsText.setString("FPS: " + to_string(fps));
        gs->update(deltaTime);
    }
}

void Framework::draw()
{
    // draw game state
    if (gs)
    {
        gs->draw(window);
    }
    // draw fps counter on top
    window.draw(fpsText);
}

bool Framework::handleEvent(sf::Event evnt)
{
    bool handled = false;
    // handle global events (closing, alt+f4, alt+enter, resize)
    switch (evnt.type)
    {
    case sf::Event::EventType::Closed:
        window.close();
        handled = true;
        break;
    case sf::Event::EventType::KeyPressed:
        switch (evnt.key.code)
        {
        case sf::Keyboard::F4:
            if (evnt.key.alt)
            {
                window.close();
                handled = true;
            }
            break;
        case sf::Keyboard::Enter:
            if (evnt.key.alt)
            {
                if (isFullscreen)
                {
                    window.create(vmNonFS, title, styleNonFS);
                    isFullscreen = false;
                }
                else
                {
                    window.create(vmFS, title, styleFS);
                    isFullscreen = true;
                }
                handled = true;
            }
            break;
        default:
            break;
        }
        break;
    case sf::Event::EventType::Resized:
        if (!isFullscreen)
        {
            vmNonFS.width = evnt.size.width;
            vmNonFS.height = evnt.size.height;
            window.create(vmNonFS, title, styleNonFS);
        }
        handled = true;
        break;
    default:
        break;
    }
    return handled;
}
