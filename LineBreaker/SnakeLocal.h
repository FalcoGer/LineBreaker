#pragma once
#include "Snake.h"


class SnakeLocal :
    public Snake
{
public:
    SnakeLocal(GameBoard* gameBoard);
    ~SnakeLocal();

    EDirection getControl();
};

