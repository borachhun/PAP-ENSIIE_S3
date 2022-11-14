#include <SDL.h>
#include <font.h>

class Sdl {
    private:
        SDL_Window *win;
        SDL_Renderer *ren;
    public:
        Sdl(); // initialize, create a window and a renderer
        void draw_bezier(Bezier b);
}
