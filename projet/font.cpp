#include <vector>
#include "point2d.h"
#include "font.h"

const int NUM_ALPHABET = 26;

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
std::vector<Point2d> Bezier::get_drawing_points() const {
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
std::vector<Point2d> Glyph::get_drawing_points() const {
    std::vector<Point2d> res;
    for (int i=0; i<curves.size(); i++) {
        std::vector<Point2d> current_drawing_points = curves[i].get_drawing_points();
        for (int j=0; j<current_drawing_points.size(); j++) {
            res.push_back(current_drawing_points[j]);
        }
    }
    return res;
}

Font::Font() {
    for (int i=0; i<NUM_ALPHABET; i++) {
        alphabets.push_back(
            Glyph(std::vector<Bezier>{Bezier(Point2d(0,0), Point2d(0,0))})
        );
    }
}
// C: capital letter
Glyph & Font::operator[](char C) {
    if (C >= 65 && C <= 90) {
        return alphabets[int(C-65)];
    }
    throw "Invalid character";
}
const Glyph Font::operator[](char C) const {
    if (C >= 65 && C <= 90) {
        return alphabets[int(C-65)];
    }
    throw "Invalid character";
}
