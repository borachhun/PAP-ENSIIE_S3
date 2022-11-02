const int NUM_ALPHA = 26;

class Point2d {
    private:
        int x;
        int y;
    public:
        Point2d(int x, int y);
}
// Only 2 types of Bezier curves: linear and quadratic
class Bezier {
    private:
        int degree;
        Point2d *control_points[3];
    public:
        Bezier(Point2d *control1, Point2d *control2);
        Bezier(Point2d *control1, Point2d *control2, Point2d *control3);
}
class Glyph {
    private:
        Bezier *curves;
}
class Font {
    private:
        Glyph alphabet[NUM_ALPHA];
}
