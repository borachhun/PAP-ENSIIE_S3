#ifndef POINT2D_H
#define POINT2D_H

class Point2d {
    int x_;
    int y_;

    public:
        Point2d() : x_(0), y_(0) {}
        Point2d(int x, int y) : x_(x), y_(y) {}
        Point2d(const Point2d & p) : x_(p.get_x()), y_(p.get_y()) {}
        int get_x() const { return x_; }
        int get_y() const { return y_; }
        void set_x(int x) { x_ = x; }
        void set_y(int y) { y_ = y; }
};

#endif
