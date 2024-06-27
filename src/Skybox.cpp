#include "Skybox.hpp"
#include <filesystem>
#include <iostream>
#include <GLFW/glfw3.h>

Skybox::Skybox(const std::string &path) {
    Mesh cube = GenMeshCube(1, 1, 1);

    _skybox = LoadModelFromMesh(cube);
    std::cout << std::filesystem::current_path() << std::endl;

    _texture = LoadTexture(path.data());
    if (!IsTextureReady(_texture)) {
        throw TextureNotValid();
    }
    _skybox.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

void Skybox::draw() {
    glDisable(GL_CULL_FACE);
    DrawModel(_skybox, { 0.0f, 0.0f, 0.0f }, 1000.0f, WHITE);   // Draw skybox cube
    glEnable(GL_CULL_FACE);
}

void Skybox::unload() {
    UnloadTexture(_texture);
    UnloadModel(_skybox);
}
