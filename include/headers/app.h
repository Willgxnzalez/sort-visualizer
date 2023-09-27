#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <../SDL2/SDL.h>
using namespace std;

class App {
    public:
        vector<int> v;

        App();
        void run();
        void visualize(int h1 = -1, int h2 = -1, int h3 = -1);
        void clear_screen();
        void delay(int t2delay);
        ~App();

    private:

        bool init();

        SDL_Window *win;
        SDL_Renderer *ren;

        int _scaleX;
        int _scaleY;

        int _screenWidth;
        int _ScreenHeight;

};

#endif