#ifndef FONT_H
#define FONT_H

#include <vector>
#include "point2d.hpp"

/**
 * Represents a Bezier curve
 */
class Bezier {

    /**
     * A vector of extremities and control points of the Bezier curve
     */
    std::vector<Point2d> elements;

    public:

        /**
         * Initialize a linear Bezier curve (a line)
         * @param end1 One extremity of the curve
         * @param end2 The other extremity of the curve
         */
        Bezier(Point2d end1, Point2d end2);

        /**
         * Initialize a quadratic Bezier curve
         * @param end1 One extremity of the curve
         * @param end2 The other extremity of the curve
         * @param control Control point of the curve
         */
        Bezier(Point2d end1, Point2d end2, Point2d control);

        /**
         * Initialize a Bezier curve
         * @param elts A vector of extremities and control points of the curve
         */
        Bezier(std::vector<Point2d> elts);

        /**
         * Get the degree of the Bezier curve
         * @return The degree of the curve
         */
        int get_degree() const;

        /**
         * Get discrete points on the Bezier curve
         * @return A vector of points on the curve
         *         - If degree 1, returns the 2 extremities of the line
         *         - If degree 2, returns 21 points on the curve
         */
        std::vector<Point2d> get_drawing_points() const;

        /**
         * Apply De Casteljau's algorithm to the Bezier curve at a given point
         * @param t A double between 0 and 1 inclusive
         * @return A point on the curve
         */
        Point2d de_casteljau(double t) const;
};



/**
 * Represents outlines of a character
 */
class Glyph {

    /**
     * A vector, an element of which is a vector of Bezier curves that
     * represents a single continuous outline of the character
     */
    std::vector<std::vector<Bezier>> curves;

    public:

        /**
         * Initialize a glyph
         * @param c A vector, an element of which is a vector of Bezier curves that
         *          represents a single continuous outline of the character
         */
        Glyph(std::vector<std::vector<Bezier>> c);

        /**
         * Get discrete points on the outlines
         * @return A vector with elements being vectors containing points on a single continuous outline
         */
        std::vector<std::vector<Point2d>> get_drawing_points() const;
};



/**
 * Represents a font
 */
class Font {

    /**
     * A vector of glyphs of characters
     */
    std::vector<Glyph> alphabets;

    public:

        /**
         * Default constructor: initialize an empty font
         */
        Font();

        /**
         * Access an alphabet of the font
         * @param C Character of the alphabet to access
         * @return Reference to the glyph of the alphabet
         */
        Glyph & operator[](char C);

        /**
         * Access an alphabet of the font
         * @param C Character of the alphabet to access
         * @return The glyph of the alphabet
         */
        const Glyph operator[](char C) const;
};

#endif
