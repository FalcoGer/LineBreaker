#include "SnakeLocal.h"



SnakeLocal::SnakeLocal(GameBoard* gameBoard)
    : Snake(gameBoard)
{
}


SnakeLocal::~SnakeLocal()
{
#if _DEBUG
    printf("SnakeLocal @ %p destroy\n", this);
#endif
}

Snake::EDirection SnakeLocal::getControl()
{
    return EDirection::stop;
}
