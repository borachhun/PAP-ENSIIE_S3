#include "vect.h"

#include <cmath>

namespace ensiie {

    // (a)
    Vect::Vect(int size) {
        if (size < 1)
            throw "Bad size argument";
        data_ = new double[size];
        size_ = size;
    }

    // (b)
    Vect::~Vect() {
        delete[] data_;
    }

    // (c)
    Vect::Vect(const Vect & v) {
        size_ = v.size_;
        data_ = new double[v.size_];
        for (int i=0; i<v.size_; i++) {
            data_[i] = v.data_[i];
        }
    }

    // (d)
    int Vect::get_size() const {
        return size_;
    }

    // (e)

    // i.
    double & Vect::operator[](int index) {
        if (index < 0 || index >= size_)
            throw "bad index";
        return data_[index];
    }
    double Vect::operator[](int index) const {
        if (index < 0 || index >= size_)
            throw "bad index";
        return data_[index];
    }

    // ii. (https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom)
    Vect & Vect::operator=(const Vect & v) {
        if (this != &v) {
            Vect tmp = v;

            // Swap data between this and tmp (selon cours)
            int tmp_size = this->size_;
            double *tmp_data = this->data_;

            this->size_ = tmp.size_;
            this->data_ = tmp.data_;

            tmp.size_ = tmp_size;
            tmp.data_ = tmp_data;
        }
        return *this;
    }

    // (f)

    // i.
    std::ostream & operator<<(std::ostream & st, const Vect & v) {
        st << '(';
        int i;
        for (i=0; i<v.get_size()-1; i++)
            st << v[i] << ',';
        st << v[i] <<  ')';
        return st;
    }

    // ii.
    Vect operator+(const Vect & v1, const Vect & v2) {
        if (v1.get_size() != v2.get_size())
            throw "Vectors with different sizes";
        int size = v1.get_size();
        Vect v(size);
        for (int i=0; i<size; i++)
            v[i] = v1[i] + v2[i];
        return v;
    }

    // iii.
    Vect operator-(const Vect & v1, const Vect & v2) {
        return v1 + (-1 * v2);
    }

    // iv.
    Vect operator*(const Vect & v1, const Vect & v2) {
        if (v1.get_size() != v2.get_size())
            throw "Vectors with different sizes";
        int size = v1.get_size();
        Vect v(size);
        for (int i=0; i<size; i++)
            v[i] = v1[i] * v2[i];
        return v;
    }

    // v.
    Vect operator*(const Vect & v, int n) {
        int size = v.get_size();
        Vect v1(size);
        for (int i=0; i<size; i++)
            v1[i] = v[i] * n;
        return v1;
    }
    Vect operator*(int n, const Vect & v) {
        return v * n;
    }

    // vi.
    Vect operator/(const Vect & v, int n) {
        int size = v.get_size();
        Vect v1(size);
        for (int i=0; i<size; i++)
            v1[i] = v[i] / n;
        return v1;
    }

    // (g)
    double Vect::norm(double p) {
        double res = 0;
        for (int i=0; i<size_; i++)
            res += pow(abs(data_[i]), p);
        return pow(res, 1/p);
    }
}
