#ifndef RAT_H
#define RAT_H

#include <ostream>

namespace ensiie {
    class Rat {
        private:
            int num_;
            int den_;

        public:
            Rat(int num, int den = 1);
            Rat(const Rat & r);

            int get_num() const;
            int get_den() const;

            Rat & operator+=(const Rat & r);
            Rat & operator+=(int i);
            Rat & operator-=(const Rat & r);
            Rat & operator-=(int i);
            Rat & operator*=(const Rat & r);
            Rat & operator*=(int i);
            Rat & operator/=(const Rat & r);
            Rat & operator/=(int i);
    };

    std::ostream & operator<<(std::ostream & st, const Rat & r);

    Rat operator+(const Rat & r1, const Rat & r2);
    Rat operator+(int i, const Rat & r);
    Rat operator+(const Rat & r, int i);

    Rat operator-(const Rat & r1, const Rat & r2);
    Rat operator-(int i, const Rat & r);
    Rat operator-(const Rat & r, int i);

    Rat operator*(const Rat & r1, const Rat & r2);
    Rat operator*(int i, const Rat & r);
    Rat operator*(const Rat & r, int i);

    Rat operator/(const Rat & r1, const Rat & r2);
    Rat operator/(int i, const Rat & r);
    Rat operator/(const Rat & r, int i);

    bool operator==(const Rat & r1, const Rat & r2);
    bool operator==(int i, const Rat & r);
    bool operator==(const Rat & r, int i);

    bool operator!=(const Rat & r1, const Rat & r2);
    bool operator!=(int i, const Rat & r);
    bool operator!=(const Rat & r, int i);

    bool operator<(const Rat & r1, const Rat & r2);
    bool operator<(int i, const Rat & r);
    bool operator<(const Rat & r, int i);

    bool operator<=(const Rat & r1, const Rat & r2);
    bool operator<=(int i, const Rat & r);
    bool operator<=(const Rat & r, int i);

    bool operator>(const Rat & r1, const Rat & r2);
    bool operator>(int i, const Rat & r);
    bool operator>(const Rat & r, int i);

    bool operator>=(const Rat & r1, const Rat & r2);
    bool operator>=(int i, const Rat & r);
    bool operator>=(const Rat & r, int i);
}

#endif