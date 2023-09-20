#include "graphics.h"
#include <iostream>
#include <vector>
using namespace std;

Graphics::Graphics() :
    window(nullptr),
    renderer(nullptr),
    _scaleX(7),
    _scaleY(7),
    _screenWidth(100 * _scaleX),
    _ScreenHeight(100 * _scaleY),
    _drawDelay(5)
{}

Graphics::~Graphics() {}

void Graphics::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL not initialized: " << SDL_GetError() << endl;
    } 
    SDL_CreateWindowAndRenderer(_screenWidth, _ScreenHeight, 0, &window, &renderer);
}

void Graphics::clear_screen() {
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);
}

void Graphics::update() {
    SDL_RenderPresent(renderer);
    SDL_Event e;
    SDL_PollEvent(&e);
    SDL_Delay(_drawDelay);
}

void Graphics::draw_state(vector<int> & vec) {
    int len = vec.size();
    int index = 0;
    for (int rect_height : vec) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect rect{index * _scaleX, _ScreenHeight - (rect_height * _scaleY), _scaleX, rect_height * _scaleY};
        SDL_RenderDrawRect(renderer, &rect); // creates hollow rectangles
        //SDL_RenderFillRect(renderer, &rect);
        ++index;
    }
}