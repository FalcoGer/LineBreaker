#pragma once
#include "MenuItem.h"
#include <iostream>
#include "Framework.h"

using namespace std;

class Framework;

class ActionRandTest :
    public GameAction
{
public:
    inline ActionRandTest(GameState* gs, float min, float max) : GameAction(gs) { this->min = min; this->max = max; }
    inline ~ActionRandTest() {}

    // inline void invoke() { cout << Framework::getRandomFloat(min, max) << endl; }
    inline void invoke() { cout << "Fixme" << endl; }
private:
    float min;
    float max;
};
