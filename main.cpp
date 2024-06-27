#include <iostream>
#include "Window.hpp"
#include "Arrow.hpp"
#include "Skybox.hpp"
#include "Crosshair.hpp"
#include "Target.hpp"


int main(void)
{
    Window window(1280, 720, "Archery");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = Vector3{ 0.0f, 10.0f, 10.0f };  // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    Skybox skybox("./assets/skybox.png");
    Crosshair crosshair("./assets/crosshair.png");
    Target target("./assets/target.obj", "./assets/target_texture.png");

    // Create an instance of Arrow
    cyclone::Vector3 arrowPosition = { 0.0f, 0.0f, 0.0f };
    cyclone::Vector3 arrowDirection = { 1.0f, 0.0f, 0.0f };
    float arrowSpeed = 5.0f;
    float arrowMass = 1.0f;
    Arrow arrow(arrowPosition, arrowDirection, arrowSpeed, arrowMass);

    DisableCursor();
    arrow.launch();
    while (!window.shouldClose())  {
        float delta = GetFrameTime();

        window.clearBackground(SKYBLUE);

        UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        window.begin();

        //2D
        {
            crosshair.draw();
        }

        //3D
        {
            window.begin3D(camera);
            // Draw arrow
            {
                DrawGrid(100, 1.0f);
                if (delta > 0.0f) {
                    arrow.update(delta);
                }
                Vector3 arrowPositionRayLib = arrow.getPositionRayLib();
                cyclone::Vector3 position = arrow.getPosition();

                DrawCube(arrowPositionRayLib, 0.2f, 0.2f, 0.2f, BLUE);
                target.draw();
            }
            // Crosshair
            window.end3D();
        }
        window.end();
    }
    skybox.unload();
    CloseWindow();
    return 0;
}