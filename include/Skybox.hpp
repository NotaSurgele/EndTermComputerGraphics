#pragma once

#include "raylib.h"
#include <string>

class TextureNotValid : public std::exception {
public:
   const char * what() const override
   {
       return "Texture is not valid";
   }
};

class Skybox {
public:
    Skybox() = delete;
    ~Skybox() = default;
    Skybox(const std::string& path);

    void draw();
    void unload();

private:
    Model _skybox;
    Texture2D _texture;
};