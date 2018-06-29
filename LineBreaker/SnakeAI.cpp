#include "SnakeAI.h"



SnakeAI::SnakeAI(GameBoard* gameBoard)
    : Snake(gameBoard)
{
}


SnakeAI::~SnakeAI()
{
#if _DEBUG
    printf("SnakeAI @ %p destroy\n", this);
#endif
}

Snake::EDirection SnakeAI::getControl()
{
    return EDirection::stop;
}
