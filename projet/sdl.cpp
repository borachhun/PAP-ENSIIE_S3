#include <SDL.h>
#include "sdl.h"

Sdl::Sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw "Unable to initialize SDL";
    }
    win = SDL_CreateWindow("Font", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
    ren = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(ren);
}
void Sdl::draw_bezier(Bezier b) {
    if (b.get_degree() == 2) {
        Point2d *points = get_drawing_points();
        SDL_RenderDrawLine(ren, point, , , );
    }
    SDL_RenderDrawLine(ren, , , , );
}
