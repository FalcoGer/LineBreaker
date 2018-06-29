#include "ActionChangeGameState.h"

ActionChangeGameState::ActionChangeGameState(GameState * gs, GameState::EGameState newState)
    : GameAction(gs)
{
    this->newState = newState;
}

ActionChangeGameState::~ActionChangeGameState()
{
}

void ActionChangeGameState::invoke()
{
    this->getGameState()->setState(newState);
}