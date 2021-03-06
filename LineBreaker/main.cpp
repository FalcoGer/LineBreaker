#include <iostream>
#include <SFML/graphics.hpp>
#include <SFML/Window.hpp>
#include "Framework.h"

const unsigned int MIN_FPS = 15;
const sf::Int64 MIN_DELTATIME = 1000000 / MIN_FPS;          // 10^6 microseconds in a second

using namespace std;

int main(int argc, char** argv)
{
    sf::VideoMode vm(640, 400);
    string title = "LineBreaker";
    Framework* framework = new Framework(title, vm);
    if (framework)
    {
        framework->run();
        delete(framework);
        framework = NULL;
    }
#if _DEBUG
    cout << "Enter to Exit" << flush;
    cin.get();
#endif
    return EXIT_SUCCESS;
}

