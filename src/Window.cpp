#include "Window.hpp"

Window::Window(int width, int height, const std::string &name) : _height(height),
                                                                _width(width),
                                                                _name(name)
{
    InitWindow(width, height, name.data());
}

Window::~Window()
{
    CloseWindow();
}

bool Window::shouldClose() const
{
    return WindowShouldClose();
}

void Window::clearBackground(const Color& color) const
{
    ClearBackground(color);
}

void Window::begin() const
{
    BeginDrawing();
}

void Window::end() const
{
    EndDrawing();
}
