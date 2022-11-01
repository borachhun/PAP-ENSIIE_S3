const int NUM_ALPHA = 26;

class Point2d {
    int x;
    int y;
}
class Bezier {
    Point2d ends[2];
    Point2d *controls;
}
class Glyph {
    Bezier *curves;
}
class Font {
    Glyph alphabet[NUM_ALPHA];
}