#include "graphics.h"
#include <iostream>
using namespace std;

Graphics::Graphics() :
    window(nullptr),
    renderer(nullptr),
    _screenWidth(1000),
    _ScreenHeight(1000) 
{}

Graphics::~Graphics() {}

void Graphics::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(_screenWidth, _ScreenHeight, 0, &window, &renderer);

}