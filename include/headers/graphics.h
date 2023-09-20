#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <vector>
#include <../SDL2/SDL.h>
using namespace std;

class Graphics {
    public:
        Graphics();

        void init();
        void draw_state(vector<int> & vec);
        void clear_screen();
        void update();

        ~Graphics();

    private:
        SDL_Window * window;
        SDL_Renderer * renderer;

        int _scaleX;
        int _scaleY;

        int _screenWidth;
        int _ScreenHeight;

        int _drawDelay;
};

#endif