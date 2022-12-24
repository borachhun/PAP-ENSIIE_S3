#ifndef FONT_H
#define FONT_H

#include <vector>
#include "point2d.hpp"

/**
 * Represents a Bezier curve
 */
class Bezier {

    /**
     * A list of extremities and control points of the Bezier curve
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
         * @param elts A list of extremities and control points of the curve
         */
        Bezier(std::vector<Point2d> elts);

        /**
         * Get the degree of the Bezier curve
         * @return The degree of the curve
         */
        int get_degree() const;

        /**
         * Get discrete points on the Bezier curve
         * @return A vector containing even numbers of points representing the extremities
         *         of lines approximating segments of the curve
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
     * A list of Bezier curves that make up the outlines
     */
    std::vector<Bezier> curves;

    public:

        /**
         * Initialize a glyph
         * @param c A list of Bezier curves that make up the outlines
         */
        Glyph(std::vector<Bezier> c);

        /**
         * Get discrete points on the outlines
         * @return A vector containing even numbers of points representing the extremities
         *         of lines approximating segments of the outlines
         */
        std::vector<Point2d> get_drawing_points() const;
};



/**
 * Represents a font
 */
class Font {

    /**
     * A list of glyphs of characters
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
         * @return Reference to the glyph of the alphabet
         */
        const Glyph operator[](char C) const;
};

#endif
