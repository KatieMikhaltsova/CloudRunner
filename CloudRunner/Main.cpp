#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(960, 540), "CloudRunner");

    gameRunning (window);

    while (window.isOpen())
    {
        if (!gameRunning (window))
        {gameRunning(window);}
    }

    return 0;
}