#pragma once
#include "GameAction.h"
class ActionChangeGameState :
    public GameAction
{
public:
    inline ActionChangeGameState(GameState* gs, GameState::EGameState newState) : GameAction(gs) { this->newState = newState; }
    inline ~ActionChangeGameState()
    {
#if _DEBUG
        printf("ActionChangeGameState @ %p destroy\n", this);
#endif
    }

    inline void invoke() { this->getGameState()->setState(newState); }
private:
    GameState::EGameState newState;
};

