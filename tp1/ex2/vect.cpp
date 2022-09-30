#include "vect.h"

namespace ensiie {

    // (a)
    Vect::Vect(int size) {
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

    // (f)

    // i.
    std::ostream & operator<<(std::ostream & st, const Vect & v) {
        st << '(';
        for (int i=0; i<v.get_size(); i++) {
            st << v[i];
            if (i < v.get_size() - 1) {
                st << ',';
            }
        }
        st << ')';
    }
}
