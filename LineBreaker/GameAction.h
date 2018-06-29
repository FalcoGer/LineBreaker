#pragma once
#include "GameState.h"

// abstract class for game actions
// give arguments to constructor of derrived classes and call invoke without arguments
// example, GameLoadAction(string filename, GameBoard& board), invoke would load the game from file into board
class GameAction
{
public:
    inline GameAction(GameState* gs) { this->gs = gs; }
    inline ~GameAction() {}

    virtual void invoke() = 0;
protected:
    inline GameState* getGameState() { return gs; }
private:
    GameState* gs;
};