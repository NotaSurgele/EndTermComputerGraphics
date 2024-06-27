#pragma once
#include <string>
#include "raylib.h"

class Crosshair {
public:
    Crosshair() = delete;

    Crosshair(const std::string& path)
    {
        _texture = LoadTexture(path.data());
        _texture.width = 50;
        _texture.height = 50;
    }

    void draw()
    {
        Vector2 mousePosition = GetMousePosition();
        DrawTexture(_texture, mousePosition.x - (_texture.width / 2), mousePosition.y - (_texture.height / 2), WHITE);
    }

private:
    Texture2D _texture;
};