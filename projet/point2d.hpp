#ifndef POINT2D_H
#define POINT2D_H

/**
 * Represents coordinates of points on 2D plane
 */
class Point2d {

    /**
     * Horizontal coordinate of a point
     */
    int x_;

    /**
     * Vertical coordinate of a point
     */
    int y_;

    public:

        /**
         * Default constructor: initialize a point with (0,0) coordinate
         */
        Point2d() : x_(0), y_(0) {}

        /**
         * Initialize a point with custom coordinates
         * @param x Horizontal coordinate
         * @param y Vertical coordinate
         */
        Point2d(int x, int y) : x_(x), y_(y) {}

        /**
         * Copy constructor: initialize a point by copying the given point
         * @param p Reference to an existing point
         */
        Point2d(const Point2d & p) : x_(p.get_x()), y_(p.get_y()) {}

        /**
         * Get horizontal coordinate of the point
         * @return The horizontal coordinate of the point
         */
        int get_x() const { return x_; }

        /**
         * Get vertical coordinate of the point
         * @return The vertical coordinate of the point
         */
        int get_y() const { return y_; }

        /**
         * Set horizontal coordinate of the point
         * @param x The horizontal coordinate of the point
         */
        void set_x(int x) { x_ = x; }

        /**
         * Set vertical coordinate of the point
         * @param y The vertical coordinate of the point
         */
        void set_y(int y) { y_ = y; }
};

#endif
