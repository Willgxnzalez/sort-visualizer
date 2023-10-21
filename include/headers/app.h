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
        void visualize(int h1 = -1, int h2 = -1, int h3 = -1, bool complete = false);
        void render_background();
        void delay(int t2delay);
        ~App();

    private:

        bool init();
        void menu();

        SDL_Window *win;
        SDL_Renderer *ren;

        const int scale;
        const int sidebarWidth;
        const int visWidth;

        const int screenWidth;
        const int screenHeight;

};

#endif