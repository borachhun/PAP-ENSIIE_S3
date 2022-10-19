#include "vect.h"

namespace ensiie {

    // (a)
    Vect::Vect(int size) {
        if (size < 1)
            throw "Bad size argument"
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
        for (int i=0; i<size_; i++) {
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

    // ii. TODO

    // (f)

    // i.
    std::ostream & operator<<(std::ostream & st, const Vect & v) {
        st << '(';
        int i;
        for (i=0; i<v.get_size()-1; i++) {
            st << v[i] << ',';
        }
        st << v[i+1] <<  ')';
    }

    // ii.
    Vect operator+(const Vect & v1, const Vect & v2) {
        if (v1.get_size() != v2.get_size())
            throw "Vectors with different sizes"
        // ...
    }
}
