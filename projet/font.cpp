#include <vector>
#include "point2d.hpp"
#include "font.hpp"

const int NUM_ALPHABET = 26;

Bezier::Bezier(Point2d end1, Point2d end2) {
    elements.push_back(end1);
    elements.push_back(end2);
}
Bezier::Bezier(Point2d end1, Point2d end2, Point2d control) {
    elements.push_back(end1);
    elements.push_back(control);
    elements.push_back(end2);
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
        std::vector<Point2d> points;
        for (int i=0; i<=20; i++) {
            Point2d res = de_casteljau(double(i)/20);
            points.push_back(res);
            if (i>0 && i<20) {
                points.push_back(res);
            }
        }
        return points;
    }
    throw "Error Bezier";
}
Point2d Bezier::de_casteljau(double t) const {
    std::vector<Point2d> res = elements;
    int n = res.size();
    for (int j=1; j<n; j++) {
        for (int i=0; i<n-j; i++) {
            res[i].set_x((res[i].get_x() * (1-t)) + (res[i+1].get_x() * t));
            res[i].set_y((res[i].get_y() * (1-t)) + (res[i+1].get_y() * t));
        }
    }
    return res[0];
}



Glyph::Glyph(std::vector<Bezier> c) : curves(c) {}
std::vector<Point2d> Glyph::get_drawing_points() const {
    std::vector<Point2d> res;
    for (unsigned int i=0; i<curves.size(); i++) {
        std::vector<Point2d> current_drawing_points = curves[i].get_drawing_points();
        for (unsigned int j=0; j<current_drawing_points.size(); j++) {
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
