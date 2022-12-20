#ifndef SDL_H
#define SDL_H

#include <SDL.h>
#include <vector>
#include "point2d.h"

namespace sdl {

class Window {
    SDL_Window *win;
    SDL_Renderer *ren;

    public:
        Window(char *title, Point2d pos, int w, int h);
        Uint32 get_window_id();
        void present();
        void destroy_window();
        void draw_lines(std::vector<Point2d> points, int offset_x, int offset_y);
};

class Sdl {
    public:
        int init();
        void quit();
        void waiting(std::vector<Window> wins);
};

} // namespace sdl

#endif
