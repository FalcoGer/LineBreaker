#pragma once
#include "GameAction.h"
class ActionChangeGameState :
    public GameAction
{
public:
    ActionChangeGameState(GameState* gs, GameState::EGameState newState);
    ~ActionChangeGameState();

    void invoke();
private:
    GameState::EGameState newState;
};

