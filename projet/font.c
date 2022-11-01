const int NUM_ALPHA = 26;

class Point2d {
    int x;
    int y;
}
// Only 2 types of Bezier curves: linear and quadratic
class Bezier {
    Point2d ends[2];
    Point2d *control;
}
class Glyph {
    Bezier *curves;
}
class Font {
    Glyph alphabet[NUM_ALPHA];
}