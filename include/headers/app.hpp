#ifndef APP_HPP
#define APP_HPP

#include <vector>
#include <../SDL2/SDL.h>
#include "const.hpp"
#include "sort.hpp"

class App {
    public:
        vector<int> v;

        App();
        void run();
        ~App();

    private:

        bool init();
        void menu();
        void mainloop();
        void render_background();

        SDL_Window *win;
        SDL_Renderer *ren;

        Sorter * sorter;
};

#endif