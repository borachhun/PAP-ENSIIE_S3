#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <vector>
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
        Window(char *title, Point2d pos, int w, int h);

        /**
         * Get ID of a SDL window
         * @return The ID of the window
         */
        Uint32 get_window_id();

        /**
         * Update the window with any rendering performed since the previous call
         */
        void present();

        /**
         * Destroy the window
         */
        void destroy_window();

        /**
         * Draw lines with the renderer
         * @param points    A vector containing even numbers of points representing the extremities
         *                  of lines to be drawn
         * @param offset_x  Horizontal translation added to the drawing lines
         * @param offset_y  Vertical translation added to the drawing lines
         */
        void draw_lines(std::vector<Point2d> points, int offset_x, int offset_y);
};

} // namespace sdl

#endif
