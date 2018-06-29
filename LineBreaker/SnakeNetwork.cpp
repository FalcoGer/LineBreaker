#include "SnakeNetwork.h"

SnakeNetwork::SnakeNetwork(GameBoard* gameBoard)
    : Snake(gameBoard)
{
}


SnakeNetwork::~SnakeNetwork()
{
#if _DEBUG
    printf("SnakeNetwork @ %p destroy\n", this);
#endif
}

Snake::EDirection SnakeNetwork::getControl()
{
    return EDirection::stop;
}
