#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <vector>
#include <string>
#include "point2d.hpp"

namespace sdl {

/**
 * Represents a SDL window with its renderer
 */
class Window {

    /**
     * SDL window
     */
    SDL_Window *win;

    /**
     * SDL renderer
     */
    SDL_Renderer *ren;

    public:

        /**
         * Initialize a window
         * @param title Title of the window
         * @param pos   Position of the window
         * @param w     Width of the window
         * @param h     Height of the window
         */
        Window(std::string title, Point2d pos, int w, int h);

        /**
         * Get ID of a SDL window
         * @return The ID of the window
         */
        Uint32 get_window_id() const;

        /**
         * Update the window with any rendering performed since the previous call
         */
        void present();

        /**
         * Destroy the window
         */
        void destroy_window();

        /**
         * Draw lines on the window with the renderer
         * @param points    A vector containing points whose connecting lines are to be drawn
         * @param offset_x  Horizontal translation added to the drawing lines
         * @param offset_y  Vertical translation added to the drawing lines
         * @param r         Red of RGB color of the drawing lines
         * @param g         Green of RGB color of the drawing lines
         * @param b         BLUE of RGB color of the drawing lines
         */
        void draw_lines(std::vector<Point2d> points, int offset_x, int offset_y, int r, int g, int b);

        /**
         * Fill a polygon with a given color on the window
         * @param vertices  Vertices of a polygon to be filled (first and last vertex are the same)
         * @param offset_x  Horizontal translation added to the vertices and filling
         * @param offset_y  Vertical translation added to the vertices and filling
         * @param r         Red of RGB color of the filling
         * @param g         Green of RGB color of the filling
         * @param b         BLUE of RGB color of the filling
         */
        void fill_polygon(std::vector<Point2d> vertices, int offset_x, int offset_y, int r, int g, int b);
};

} // namespace sdl

#endif
