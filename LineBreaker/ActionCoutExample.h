#pragma once
#include "GameAction.h"
#include <iostream>

using namespace std;

class ActionCoutExample :
    public GameAction
{
public:
    inline ActionCoutExample(GameState* gs, string text) : GameAction(gs) { this->text = text; }
    inline ~ActionCoutExample()
    {
#if _DEBUG
        printf("ActionCoutExample @ %p destroy\n", this);
#endif
    }

    inline void invoke() { cout << text << endl; }
private:
    string text;
};