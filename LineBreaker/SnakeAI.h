#pragma once

#include "Snake.h"


class SnakeAI :
    public Snake
{
public:
    SnakeAI(GameBoard* gameBoard);
    ~SnakeAI();

    // Geerbt �ber Snake
    EDirection getControl();
};

