#ifndef SDL_H
#define SDL_H

#include <SDL.h>
#include <vector>
#include <string>
#include "point2d.hpp"
#include "window.hpp"

namespace sdl {

/**
 * Manages graphical interface
 */
class Sdl {

    /**
     * A vector of windows to be displayed
     */
    std::vector<sdl::Window> wins;

    public:

        /**
         * Initialize the SDL library
         * @return 0 on success, or negative error code on failure
         */
        int init();

        /**
         * Clean up all initialized SDL elements
         */
        void quit();

        /**
         * Handling closing window events
         */
        void waiting();

        /**
         * Create a new window and add it to the vector of windows
         * @param title Title of the window
         * @param pos   Position of the window
         * @param w     Width of the window
         * @param h     Height of the window
         */
        void add_window(std::string title, Point2d pos, int w, int h);

        /**
         * Get window from the vector of windows
         * @param i Index of the window in the vector of windows
         * @return Reference to the respective window in the vector
         */
        Window & get_window(unsigned int i);
};

} // namespace sdl

#endif
