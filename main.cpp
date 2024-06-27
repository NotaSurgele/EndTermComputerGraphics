#include <iostream>
#include "Window.hpp"

int main(void)
{
    Window window(800, 600, "Archery");
    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = Vector3{ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    while (!window.shouldClose())  {
        window.clearBackground(RAYWHITE);

        window.begin();
        {
            window.begin3D(camera);
            // DRaw cubes
            {
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
            }
            window.end3D();
        }
        window.end();
    }
    return 0;
}