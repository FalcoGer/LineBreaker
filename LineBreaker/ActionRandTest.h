#pragma once
#include "GameAction.h"
#include "GameState.h"
#include "Framework.h"

#include <iostream>

using namespace std;

class Framework;

class ActionRandTest :
    public GameAction
{
public:
    inline ActionRandTest(GameState* gs, float min, float max) : GameAction(gs) { this->min = min; this->max = max; }
    inline ~ActionRandTest() {}

    // FIXME
    // inline void invoke() { cout << Framework::getRandomFloat(min, max) << endl; }
    // Code     Beschreibung                                                                                    Zeile
    // C2027    Verwendung des undefinierten Typs "Framework" (Quelldatei wird kompiliert main.cpp)             17
    // C3861    "getRandomFloat": Bezeichner wurde nicht gefunden. (Quelldatei wird kompiliert main.cpp)        17
    // C2027    Verwendung des undefinierten Typs "Framework" (Quelldatei wird kompiliert Framework.cpp)        17
    // C3861    "getRandomFloat": Bezeichner wurde nicht gefunden. (Quelldatei wird kompiliert Framework.cpp)   17

    inline void invoke() { cout << "Fixme" << endl; }
private:
    float min;
    float max;
};
