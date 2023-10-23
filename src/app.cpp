#include <iostream>
#include <vector>
#include "app.hpp"
#include "sort.hpp"

using namespace std;

App::App() :
    win(nullptr),
    ren(nullptr),
    sorter(nullptr)
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

    win = SDL_CreateWindow("Sorting Algorithm Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    render_background();
    SDL_RenderPresent(ren);

    return true;
}

void App::render_background() {
    SDL_SetRenderDrawColor(ren, 24,24,24, 255);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 40, 40, 40, 255);
    SDL_Rect sidebar{visWidth, 0, sidebarWidth, screenHeight};
    SDL_RenderFillRect(ren, &sidebar);
}

void App::menu() {
    cout << "\n            SORTING VISUALIZER            \n"
    << "------------------------------------------\n"
    << "   Q/ESC: exit the sorting visualizer.\n"
    << "   0: Generate a new randomized array.\n"
    << "   1: Start Bubble Sort Algorithm.\n"
    << "   2: Start Quick Sort Algorithm.\n"
    << "   3: Start Insertion Sort Algorithm.\n"
    << "   4: Start Selection Sort Algorithm.\n"
    << "   SPACE: Cancel the visualization.\n\n\n";
}

void App::run() {
    if (init())
        mainloop();
    else
        cout << "[ERROR]Visualizer failed to initialize" << endl;
}

void App::mainloop() {
    
    menu();

    bool run = true;
    while (run) {

        SDL_Event E;
        while(SDL_PollEvent(&E)) {
            if (E.type == SDL_QUIT)
                run = false;
            else if (E.type == SDL_KEYDOWN) {
                auto key = E.key.keysym.sym;
                if (key == SDLK_q  || key == SDLK_ESCAPE) {
                    run = false;
                    break;
                } else if (key == SDLK_0) {
                    Sorter::randomizeVector(v);
                    sorter = new BubbleSorter();
                    sorter->setRenderer(ren);
                    sorter->visualize(v);
                    delete sorter;
                    break;
                } else if (key == SDLK_1) {
                    sorter = new BubbleSorter();
                } else if (key == SDLK_2) {
                    sorter = new QuickSorter();
                } else if (key == SDLK_3) {
                    sorter = new InsertionSorter();
                }  else if (key == SDLK_4) {
                    sorter = new SelectionSorter();
                } else if (key == SDLK_5) {
                    sorter = new MergeSorter();
                } else break;
                
                sorter->setRenderer(ren);
                sorter->sort(v); 

                if (Sorter::isSorted(v)) {
                    sorter->visualize(v, -1,-1,-1,true);

                } else {
                    std::cout << "[ABORT]User force quit the current sort\n";
                }
                Sorter::randomizeVector(v);
                delete sorter;
                
            }
        }
    } 
}