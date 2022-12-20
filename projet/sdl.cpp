#include <SDL.h>
#include <vector>
#include "point2d.h"
#include "sdl.h"

namespace sdl {

Window::Window(char *title, Point2d pos, int w, int h) {
    win = SDL_CreateWindow(title, pos.get_x(), pos.get_y(),
                            w, h, SDL_WINDOW_OPENGL);
    ren = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(ren);
}
Uint32 Window::get_window_id() {
    return SDL_GetWindowID(win);
}
void Window::present() {
    SDL_RenderPresent(ren);
}
void Window::destroy_window() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}
void Window::draw_lines(std::vector<Point2d> points, int offset_x, int offset_y) {
    SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
    for (int i=0; i<points.size()-1; i+=2) {
        Point2d start = points[i];
        Point2d end = points[i+1];
        SDL_RenderDrawLine(ren, start.get_x()+offset_x, start.get_y()+offset_y,
                                end.get_x()+offset_x, end.get_y()+offset_y);
    }
}









int Sdl::init() {
    return SDL_Init(SDL_INIT_EVERYTHING);
}
void Sdl::quit() {
    SDL_Quit();
}
void Sdl::waiting(std::vector<Window> wins) {
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
                for (int i=0; i<wins.size(); i++) {
                    if (wins[i].get_window_id() == event.window.windowID) {
                        wins[i].destroy_window();
                        break;
                    }
                }
            }
        }
    }
}

} // namespace sdl
