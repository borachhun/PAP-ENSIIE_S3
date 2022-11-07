#include "font.h"

int Bezier::get_degree() {
    return degree;
}
Point2d *Bezier::get_drawing_points() {
    Point2d *points;
    if (degree == 1) {
        points = new Point2d[2];
        // ...
    }
    else if (degree == 2) {
        points = new Point2d[1001];
        // ...
    }
    return points;
}
