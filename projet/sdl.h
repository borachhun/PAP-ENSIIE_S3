#ifndef SDL_H
#define SDL_H

#include <SDL.h>
#include <vector>

namespace sdl {

class Window {
    SDL_Window *win;
    SDL_Renderer *ren;

    public:
        Window(char *title, int pos_x, int pos_y, int w, int h);
        Uint32 get_window_id();
        void present();
        void destroy_window();
        void draw_line(int start_x, int start_y, int end_x, int end_y);
};

class Sdl {
    public:
        int init();
        void quit();
        void waiting(std::vector<Window> wins);
};

} // namespace sdl

#endif
