#include <iostream>
#include <vector>
#include "app.h"
#include "sort.h"

using namespace std;

App::App() :
    win(nullptr),
    ren(nullptr),
    _scaleX(10),
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
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL system not initialized: " << SDL_GetError() << endl;
        return false;
    }

    win = SDL_CreateWindow("Sorting Algorithm Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _ScreenHeight, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(ren, 255,255,255, 255);
    SDL_RenderClear(ren);
    
    visualize();

    return true;
}

void App::clear_screen() {
    SDL_SetRenderDrawColor(ren, 40,40,40, 5);
    SDL_RenderClear(ren);
}

void App::delay(int t2delay) {  // wrapper method for delaying the next frame
    SDL_Delay(t2delay);
}

void App::visualize(int h1, int h2, int h3, bool complete) {
    clear_screen(); // clear the screen before the next screen is drawn

    int len = v.size();
    for (int i=0; i < len; ++i) {
        SDL_Rect rect{i * _scaleX, _ScreenHeight - (v[i] * _scaleY) + 1, _scaleX, v[i] * _scaleY};
        if (complete) {
            SDL_SetRenderDrawColor(ren, 90,113,155, 255);
            SDL_RenderFillRect(ren, &rect);
            SDL_SetRenderDrawColor(ren, 100,255,100, 255);
            SDL_RenderDrawRect(ren, &rect);
        } else if (i == h1) {
            SDL_SetRenderDrawColor(ren, 111,241,236, 255);
            SDL_RenderFillRect(ren, &rect);
        } else if (i == h2 || i == h3) {
            SDL_SetRenderDrawColor(ren, 237,27,118, 255);
            SDL_RenderFillRect(ren, &rect);
        } else {
            SDL_SetRenderDrawColor(ren, 90,113,155, 255);
            SDL_RenderFillRect(ren, &rect);
            SDL_SetRenderDrawColor(ren, 40,40,40, 255);
            SDL_RenderDrawRect(ren, &rect);
        }
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
                    } else if (key == SDLK_2) {
                        sorter = new QuickSorter(*this);
                    } else if (key == SDLK_3) {
                        sorter = new InsertionSorter(*this);
                    } else break;

                    sorter->sort(v);
                    delete sorter;

                    if (Sorter::isSorted(v))
                        visualize(-1,-1,-1,true);
                }
            }
        } 
    } else {
        cout << "Visualizer failed to initialize" << endl;
    
    }
}