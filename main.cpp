#include <iostream>
#include "Window.hpp"

int main(void)
{
    Window window(800, 600, "Archery");

    while (!window.shouldClose())  {

        window.begin();
        {
           window.clearBackground(RAYWHITE);
        }
        window.end();
    }
    return 0;
}