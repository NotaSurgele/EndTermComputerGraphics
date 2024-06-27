#pragma once
#include <string>
#include "raylib.h"

class Window {
public:
    Window() = delete;
    Window(int width=800, int height=600, const std::string& name="Window");
    ~Window();

    bool shouldClose() const;
    void clearBackground(const Color& color) const;
    void begin() const ;
    void end() const;

private:
    int _height = 800;
    int _width = 600;
    std::string _name;
};

