#include "Window.hpp"

Window::Window(int width, int height, const std::string &name) : _height(height),
                                                                _width(width),
                                                                _name(name)
{
    InitWindow(width, height, name.data());
    SetTargetFPS(60);
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

void Window::begin3D(const Camera3D& camera) const
{
    BeginMode3D(camera);
}

void Window::end3D() const
{
    EndMode3D();
}

void Window::begin2D(const Camera2D& camera) const
{
    BeginMode2D(camera);
}

void Window::end2D() const
{
    EndMode3D();
}
