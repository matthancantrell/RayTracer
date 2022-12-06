#include <iostream>
#include "Renderer/Renderer.h"
#include "Renderer/Canvas.h"
#include "Objects/Sphere.h"

int main(int, char**)
{
    std::cout << "Hello World!\n";

    Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow(1000, 500);

    Canvas canvas(1000, 500, renderer);

    auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, nullptr);

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

        renderer.Render(canvas, sphere.get());

        canvas.Update();

        renderer.CopyCanvas(canvas);

        renderer.Present();
    }

    renderer.Shutdown();
    return 0;
}