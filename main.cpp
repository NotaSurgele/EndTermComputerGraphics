#include <iostream>
#include <vector>

#include "Window.hpp"
#include "Arrow.hpp"
#include "Skybox.hpp"
#include "Crosshair.hpp"
#include "Target.hpp"
#include "raymath.h"

int main(void)
{
    Window window(1280, 720, "Archery");
    std::vector<Arrow *> arrows;

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = Vector3{ 0.0f, 10.0f, 25.0f };
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Skybox skybox("./assets/skybox.png");
    Crosshair crosshair("./assets/crosshair.png");
    Target target("./assets/target.obj", "./assets/target_texture.png");

    // Create an instance of Arrow
    cyclone::Vector3 arrowPosition = { 0.0f, 0.0f, 0.0f };
    cyclone::Vector3 arrowDirection = { 1.0f, 0.0f, 0.0f };
    float arrowSpeed = 5.0f;
    float arrowMass = 1.0f;

    DisableCursor();
    while (!window.shouldClose())  {
        float delta = GetFrameTime();

        window.clearBackground(SKYBLUE);

        //UpdateCamera(&camera, CAMERA_THIRD_PERSON);

        window.begin();

        //3D
        {
            window.begin3D(camera);
            // Draw arrow
            {
                DrawGrid(100, 1.0f);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    Vector2 mousePosition = GetMousePosition(); // Get the 2D screen coordinates of the mouse
                    Ray mouseRay = GetMouseRay(mousePosition, camera); // Get the ray from the camera through the mouse position

                    Vector3 groundPlaneNormal = {0.0f, 1.0f, 0.0f};
                    Vector3 groundPlanePoint = {0.0f, 0.0f, 0.0f};

                    float t = (Vector3DotProduct(groundPlaneNormal, Vector3Subtract(groundPlanePoint, mouseRay.position)) / Vector3DotProduct(groundPlaneNormal, mouseRay.direction));
                    Vector3 mouseWorldPosition = Vector3Add(mouseRay.position, Vector3Scale(mouseRay.direction, t));

                    cyclone::Vector3 fixedPos = {  mouseWorldPosition.x, mouseWorldPosition.y,  mouseWorldPosition.z + 20 };
                    auto instance = new Arrow(fixedPos, { 0.0f, 0.0f, -1.0f }, 20.0f, 1.0);

                    instance->launch();
                    arrows.push_back(instance);
                }

                if (delta > 0.0f) {
                    for (auto& arrow : arrows) {
                        arrow->update(delta);
                        Vector3 arrowPositionRayLib = arrow->getPositionRayLib();

                        cyclone::Vector3 position = arrow->getPosition();

                        DrawCube(arrowPositionRayLib, 0.2f, 0.2f, 0.2f, BLUE);
                    }
                }
                target.draw();
            }
            window.end3D();
        }

        //2D
        {
            crosshair.draw();
        }

        window.end();
    }
    skybox.unload();
    CloseWindow();
    return 0;
}