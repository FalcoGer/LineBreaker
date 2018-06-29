#pragma once
#include "GameAction.h"
#include <iostream>

using namespace std;

class ActionCoutExample :
    public GameAction
{
public:
    ActionCoutExample(GameState* gs, string text);
    ~ActionCoutExample();

    void invoke();
private:
    string text;
};

