#ifndef FONT_H
#define FONT_H

#include <vector>
#include "point2d.h"

const int NUM_ALPHA = 26;

class Bezier {
    // linear: 2 elements, quadratic: 3 elements
    std::vector<Point2d> elements;

    public:
        Bezier(Point2d end1, Point2d end2);
        Bezier(Point2d end1, Point2d end2, Point2d control);
        Bezier(std::vector<Point2d> elts);

        int get_degree() const;
        std::vector<Point2d> get_drawing_points();
};
class Glyph {
    std::vector<Bezier> curves;

    public:
        Glyph(std::vector<Bezier> c);
        std::vector<Point2d> get_drawing_points();
};
class Font {
    Glyph alphabets[NUM_ALPHA];

    public:
        Glyph & operator[](char c);
};

#endif
