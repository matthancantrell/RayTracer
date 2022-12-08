#include <iostream>
#include "Renderer/Renderer.h"
#include "Renderer/Canvas.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include "Renderer/Camera.h"

int main(int, char**)
{
    std::cout << "Hello World!\n";

    const int width = 1000;
    const int height = 500;
    const int samples = 100;

    Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow(width, height);

    Canvas canvas(width, height, renderer);
    Camera camera({ 0, 1, 2 }, { 0, 0, 0 }, { 0, 1, 0 }, 70.0f, width / (float)height);
    Scene scene;

    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ 0, 1, 0 })));
    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 1, 0, -1 }, 0.5f, std::make_unique<Metal>(color3{ 1, 1, 1 }, 0.1f)));
    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5, -1 }, 100.0f, std::make_unique<Lambertian>(color3{ 0.2f, 0.2f, 0.2f })));

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT: 
            {

                quit = true;
                break;
            }

            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
                break;
            }
        }


        // For Static Use This Code
       canvas.Clear( { 0, 0, 0, 1} );

        //for (int i = 0; i < 1000; i++)
        //{
        //    canvas.DrawPoint({ random(0, 1000), random(0, 600)}, {1, 1, 1, 1});
        //}

        renderer.Render(canvas, scene, camera, samples);

        canvas.Update();

        renderer.CopyCanvas(canvas);

        renderer.Present();
    }

    renderer.Shutdown();
    return 0;
}