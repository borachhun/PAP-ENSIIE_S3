#include <vector>
#include "point2d.h"
#include "font.h"

Bezier::Bezier(Point2d end1, Point2d end2) {
    elements.push_back(end1);
    elements.push_back(end2);
}
Bezier::Bezier(Point2d end1, Point2d end2, Point2d control) {
    elements.push_back(end1);
    elements.push_back(end2);
    elements.push_back(control);
}
Bezier::Bezier(std::vector<Point2d> elts) : elements(elts) {}
int Bezier::get_degree() const {
    return elements.size()-1;
}
std::vector<Point2d> Bezier::get_drawing_points() {
    if (get_degree() == 1) {
        return elements;
    }
    else if (get_degree() == 2) {
        std::vector<Point2d> points{Point2d(0,0), Point2d(100,100)};
        return points;
    }
    throw "Error Bezier";
}

Glyph::Glyph(std::vector<Bezier> c) : curves(c) {}
std::vector<Point2d> Glyph::get_drawing_points() {
    std::vector<Point2d> res;
    for (int i=0; i<curves.size(); i++) {
        res.insert(...);
    }
    return res;
}

Glyph & Font::operator[](char c) {
    // small letter
    if (c >= 97 && c <= 122) {
        return alphabets[c-97];
    }
    // capital letter
    else if (c >= 65 && c <= 90) {
        return alphabets[c-65];
    }
    throw "Invalid character";
}
