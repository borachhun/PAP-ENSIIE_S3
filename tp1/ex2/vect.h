#ifndef VECT_H
#define VECT_H

#include <ostream>

namespace ensiie {
    class Vect {
        private:
            double *data_;
            int size_;
        public:
            Vect(int size);
            ~Vect();
            Vect(const Vect & v);

            int get_size() const;

            double & operator[](int index);
            double operator[](int index) const;
    };

    std::ostream & operator<<(std::ostream & st, const Vect & v);
    Vect operator+(const Vect & v1, const Vect & v2);
};

#endif