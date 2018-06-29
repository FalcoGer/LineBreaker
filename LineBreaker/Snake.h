#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameBoard.h"

#include <list>

using namespace std;

class GameBoard;

class Snake
    : public RenderItem
{
public:
    Snake(GameBoard* gameBoard);
    virtual ~Snake();

    enum EDirection
    {
        up,
        right,
        down,
        left,
        stop
    };

    void draw(sf::RenderWindow& window);
    void update(sf::Int64 deltaTime);

    // for snake local check keyboard
    // for snake network read network package for new direction
    // for snake ai call ai decision making and return new direction
    virtual EDirection getControl() = 0;

    inline void setDirection(EDirection direction) { this->direction = direction; }
    inline void setSpeed(float speed) { this->speed = speed; }
    inline void kill() { alive = false; }
    inline bool getAlive() { return alive; }
    EDirection getLastTravelDirection();
protected:
    GameBoard* gameBoard;
    list<sf::Vector2i> body;        // list of the body parts in order
    sf::Vector2i headPos;           // position of the head on the grid
    float animationPos;             // position in the animation
    float speed;                    // speed in tiles per second
    EDirection direction;           // direction of movement
    sf::Color color;                // color of the snake body
    bool alive;                     // is the snake alive, used for update
};

