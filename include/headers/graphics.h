#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <../SDL2/SDL.h>
using namespace std;

class Graphics {
    public:
        Graphics() {}

        void init() { cout << "initializing graphics engine" << endl; }
        void draw_state(vector<int> & vec);

        ~Graphics() {}

    private:
        SDL_Window * window;
        SDL_Renderer * renderer;

        int _screenWidth;
        int _ScreenHeight;
};

#endif