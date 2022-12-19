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
        void draw_line(Point2d start, Point2d end);
        void draw_curve(std::vector<Point2d> points);
};

class Sdl {
    public:
        int init();
        void quit();
        void waiting(std::vector<Window> wins);
};

} // namespace sdl

#endif
