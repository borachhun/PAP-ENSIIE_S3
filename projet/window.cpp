#include <SDL.h>
#include <vector>
#include <string>
#include <cstring>
#include "point2d.hpp"
#include "window.hpp"

namespace sdl {

Window::Window(std::string title, Point2d pos, int w, int h) {
    win = SDL_CreateWindow(title.c_str(), pos.get_x(), pos.get_y(),
                            w, h, SDL_WINDOW_OPENGL);
    ren = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(ren);
}
Uint32 Window::get_window_id() const {
    return SDL_GetWindowID(win);
}
void Window::present() {
    SDL_RenderPresent(ren);
}
void Window::destroy_window() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
}
void Window::draw_lines(std::vector<Point2d> points, int offset_x, int offset_y, int r, int g, int b) {
    SDL_SetRenderDrawColor(ren, r, g, b, SDL_ALPHA_OPAQUE);
    for (unsigned int i=0; i<points.size()-1; i++) {
        Point2d start = points[i];
        Point2d end = points[i+1];
        SDL_RenderDrawLine(ren, start.get_x()+offset_x, start.get_y()+offset_y,
                                end.get_x()+offset_x, end.get_y()+offset_y);
    }
}

/**
 * Test whether a given point in the a polygon or not (auxiliary function for fill_polygon)
 * @param unique_vertices   Non-duplicated vertices of the polygon
 * @param x                 A coordinate of the point to be tested
 * @param y                 A coordinate of the point to be tested
 */
bool is_in_polygon(std::vector<Point2d> unique_vertices, int x, int y) {
    int j = unique_vertices.size() - 1;
    int num_intersection = 0;

    for (int i=0; i<unique_vertices.size(); i++) {
        if (unique_vertices[i].get_y() < y && unique_vertices[j].get_y() >= y ||
            unique_vertices[j].get_y() < y && unique_vertices[i].get_y() >= y) {

            if (x < float(y-unique_vertices[i].get_y()) * float(unique_vertices[j].get_x()-unique_vertices[i].get_x()) /
                    float(unique_vertices[j].get_y()-unique_vertices[i].get_y()) + unique_vertices[i].get_x()) {
                
                num_intersection++;
            }
        }
        j=i;
    }
    
    return (num_intersection % 2 != 0);
}

void Window::fill_polygon(std::vector<Point2d> vertices, int offset_x, int offset_y, int r, int g, int b) {

    if (vertices.size() < 4) {
        throw "Invalid polygon";
    }

    // Remove last duplicate vertex of polygon
    vertices.erase(vertices.end()-1);

    SDL_SetRenderDrawColor(ren, r, g, b, SDL_ALPHA_OPAQUE);

    // Specific case: a character is always in range [0,100]
    const int MIN_X = 0;
    const int MIN_Y = 0;
    const int MAX_X = 100;
    const int MAX_Y = 100;

    for (int i=MIN_X; i<=MAX_X; i++) {
        for (int j=MIN_Y; j<=MAX_Y; j++) {
            if (is_in_polygon(vertices, i, j)) {
                SDL_RenderDrawPoint(ren, i+offset_x, j+offset_y);
            }
        }
    }
}

} // namespace sdl
