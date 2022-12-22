#ifndef SDL_H
#define SDL_H

#include <SDL.h>
#include <vector>
#include "point2d.h"
#include "window.h"

namespace sdl {

class Sdl {
    std::vector<sdl::Window> wins;

    public:
        int init();
        void quit();
        void waiting();
        void add_window(char *title, Point2d pos, int w, int h);
        Window & get_window(unsigned int i);
};

} // namespace sdl

#endif
