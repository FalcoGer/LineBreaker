#include "Snake.h"



Snake::Snake(GameBoard* gameBoard)
{
    this->gameBoard = gameBoard;
}


Snake::~Snake()
{
#if _DEBUG
    printf("Snake @ %p destroy\n", this);
#endif
}

void Snake::draw(sf::RenderWindow & window)
{
}

void Snake::update(sf::Int64 deltaTime)
{
}

Snake::EDirection Snake::getLastTravelDirection()
{
    {
        sf::Int32 oldX = body.back().x;
        sf::Int32 oldY = body.back().y;

        if (headPos.x > oldX)
        {
            return EDirection::right;
        }
        else if (headPos.x < oldX)
        {
            return EDirection::left;
        }
        else // x stayed the same
        {
            if (headPos.y < oldY) // low y = high on screen
            {
                return EDirection::up;
            }
            else if (headPos.y > oldY)
            {
                return EDirection::down;
            }
            else // y is the same, too
            {
                return EDirection::stop;
            }
        }
    }
}
