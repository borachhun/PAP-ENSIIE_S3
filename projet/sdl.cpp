#include <SDL.h>
#include <vector>
#include "point2d.h"
#include "window.h"
#include "sdl.h"

namespace sdl {

int Sdl::init() {
    return SDL_Init(SDL_INIT_EVERYTHING);
}
void Sdl::quit() {
    SDL_Quit();
}
void Sdl::waiting() {
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
                for (unsigned int i=0; i<wins.size(); i++) {
                    if (wins[i].get_window_id() == event.window.windowID) {
                        wins[i].destroy_window();
                        break;
                    }
                }
            }
        }
    }
}
void Sdl::add_window(char *title, Point2d pos, int w, int h) {
    wins.push_back(sdl::Window(title, pos, w, h));
}
Window & Sdl::get_window(unsigned int i) {
    if (i >= wins.size()) {
        throw "bad index";
    }
    return wins[i];
}

} // namespace sdl
