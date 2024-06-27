#include <iostream>
#include "Window.hpp"
#include "Arrow.hpp"

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

    // Create an instance of Arrow
    cyclone::Vector3 arrowPosition = { 0.0f, 0.0f, 0.0f };
    cyclone::Vector3 arrowDirection = { 1.0f, 0.0f, 0.0f };
    float arrowSpeed = 5.0f;
    float arrowMass = 1.0f;
    Arrow arrow(arrowPosition, arrowDirection, arrowSpeed, arrowMass);

    arrow.launch();
    while (!window.shouldClose())  {
        float delta = GetFrameTime();

        window.clearBackground(RAYWHITE);

        window.begin();
        {
            window.begin3D(camera);

            // Draw arrow
            {
                if (delta > 0.0f) {
                    std::cout << delta << std::endl;
                    arrow.update(delta);
                }
                Vector3 arrowPositionRayLib = arrow.getPositionRayLib();
                cyclone::Vector3 position = arrow.getPosition();

                std::cout << "Position " << position.x << " " << position.y << " " << position.z << std::endl;
                DrawCube(arrowPositionRayLib, 0.2f, 0.2f, 0.2f, BLUE);
            }
            window.end3D();
        }
        window.end();
    }
    return 0;
}