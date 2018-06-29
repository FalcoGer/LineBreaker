#include "ActionCoutExample.h"



ActionCoutExample::ActionCoutExample(GameState* gs, string text)
    : GameAction(gs)
{
    this->text = text;
}


ActionCoutExample::~ActionCoutExample()
{
}

void ActionCoutExample::invoke()
{
    cout << text << endl;
}
