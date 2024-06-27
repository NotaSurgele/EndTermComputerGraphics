#pragma once
#include <string>
#include "raylib.h"

class Target {
public:
    Target() = delete;
    Target(const std::string& modelPath, const std::string& texturePath)
    {
        _model = LoadModel(modelPath.data());
        Texture2D texture = LoadTexture(texturePath.data());
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    }

    ~Target()
    {

    }

    void draw()
    {
        DrawModelEx(_model, {0, 0, 0}, {0, 1, 0}, -180.0f,
                    {1, 1, 1}, WHITE);
    }

private:
    Model _model;
};