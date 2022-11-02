#include <SDL.h>

class Sdl {
    private:
        SDL_Window *win;
        SDL_Renderer *ren;
    public:
        Sdl(); // initialize, create a window and a renderer
}
