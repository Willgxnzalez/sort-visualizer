#include <iostream>
#include <vector>
#include "app.h"
#include "sort.h"

using namespace std;

App::App() :
    win(nullptr),
    ren(nullptr),
    _scaleX(7),
    _scaleY(7),
    _screenWidth(100 * _scaleX),
    _ScreenHeight(100 * _scaleY)
{
    Sorter::randomizeVector(v);
}

App::~App() {
    SDL_DestroyRenderer(ren);
    ren = nullptr;
    SDL_DestroyWindow(win);
    win = nullptr;
    SDL_Quit();
}

bool App::init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL system not initialized: " << SDL_GetError() << endl;
        success = false;
    }
    win = SDL_CreateWindow("Sorting Algorithm Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _ScreenHeight, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, 0);
    //SDL_CreateWindowAndRenderer(_screenWidth, _ScreenHeight, 0, &win, &ren);
    clear_screen();

    return success;
}

void App::clear_screen() {
    SDL_SetRenderDrawColor(ren, 0,0,0, 255);
    SDL_RenderClear(ren);
}

void App::delay(int t2delay) {  // wrapper method for delaying the next frame
    SDL_Delay(t2delay);
}

void App::visualize() {
    clear_screen(); // clear the screen before the next screen is drawn

    int len = v.size();
    int index = 0;
    for (int rect_height : v) {
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        //SDL_Rect rect{index * _scaleX, 0, _scaleX, rect_height * _scaleY};  //draw in top right corner
        SDL_Rect rect{index * _scaleX, _ScreenHeight - (rect_height * _scaleY), _scaleX, rect_height * _scaleY};
        SDL_RenderDrawRect(ren, &rect); // creates hollow rectangles
        //SDL_RenderFillRect(_ren, &rect);
        ++index;
    }

    SDL_RenderPresent(ren);
}

void App::run() {
    if (init()) {
        bool run = true;
        Sorter *sorter = nullptr;

        while (run) {
            SDL_Event E;

            while(SDL_PollEvent(&E)) {
                if (E.type == SDL_QUIT)
                    run = false;
                else if (E.type == SDL_KEYDOWN) {
                    auto key = E.key.keysym.sym;
                    if (key == SDLK_q) {
                        run = false;
                        break;
                    } else if (key == SDLK_0) {
                        Sorter::randomizeVector(v);
                        visualize();
                        break;

                    } else if (key == SDLK_1) {
                        sorter = new BubbleSorter(*this);
                    }
                    sorter->sort(v);
                    delete sorter;
                }
            }
        }
        return;
    } else {
        cout << "Visualizer failed to initialize" << endl;
    }

}