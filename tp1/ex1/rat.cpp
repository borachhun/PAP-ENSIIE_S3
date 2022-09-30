#include "rat.h"
#include <algorithm> // gcd
#include <cstdlib> // abs

namespace ensiie {
    // (a)
    Rat::Rat(int num, int den) {
        if (den <= 0)
            throw "denominateur nul ou negatif";
        int gcd = std::__gcd(abs(num), den);
        num_ = num / gcd;
        den_ = den / gcd;
    }
    Rat::Rat(const Rat & r) {
        num_ = r.num_;
        den_ = r.den_;
    }

    // (b)
    int Rat::get_num() const {
        return num_;
    }
    int Rat::get_den() const {
        return den_;
    }

    // (c)

    // i.
    Rat & Rat::operator+=(const Rat & r) {
        this->num_ = (this->num_ * r.den_) + (this->den_ * r.num_);
        this->den_ = this->den_ * r.den_;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }
    Rat & Rat::operator+=(int i) {
        this->num_ += i * this->den_;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }

    // ii.
    Rat & Rat::operator-=(const Rat & r) {
        this->num_ = (this->num_ * r.den_) - (this->den_ * r.num_);
        this->den_ = this->den_ * r.den_;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }
    Rat & Rat::operator-=(int i) {
        this->num_ -= i * this->den_;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }

    // iii.
    Rat & Rat::operator*=(const Rat & r) {
        this->num_ = this->num_ * r.num_;
        this->den_ = this->den_ * r.den_;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }
    Rat & Rat::operator*=(int i) {
        this->num_ *= i;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }

    // iv.
    Rat & Rat::operator/=(const Rat & r) {
        this->num_ = this->num_ * r.den_; 
        this->den_ = this->den_ * r.num_;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }
    Rat & Rat::operator/=(int i) {
        this->den_ *= i;

        int gcd = std::__gcd(abs(this->num_), this->den_);
        this->num_ /= gcd;
        this->den_ /= gcd;

        return *this;
    }

    // (d)

    // i.
    std::ostream & operator<<(std::ostream & st, const Rat & r) {
        st << r.get_num();
        if (r.get_den() != 1)
            st << '/' << r.get_den();
        return st;
    }

    // ii.
    Rat operator+(const Rat & r1, const Rat & r2) {
        int new_num = (r1.get_den() * r2.get_num()) + (r1.get_num() * r2.get_den());
        int new_den = r1.get_den() * r2.get_den();
        Rat r(new_num, new_den);
        return r;
    }
    Rat operator+(int i, const Rat & r) {
        int new_num = i * r.get_den() + r.get_num();
        Rat r_new(new_num, r.get_den());
        return r_new;
    }
    Rat operator+(const Rat & r, int i) {
        return i + r;
    }

    // iii.
    Rat operator-(const Rat & r1, const Rat & r2) {
        return r1 + (-1 * r2);
    }
    Rat operator-(int i, const Rat & r) {
        Rat r_i(i);
        return r_i - r;
    }
    Rat operator-(const Rat & r, int i) {
        return -i + r;
    }

    // iv.
    Rat operator*(const Rat & r1, const Rat & r2) {
        int new_num = r1.get_num() * r2.get_num();
        int new_den = r1.get_den() * r2.get_den();
        Rat r(new_num, new_den);
        return r;
    }
    Rat operator*(int i, const Rat & r) {
        int new_num = i * r.get_num();
        Rat r_new(new_num, r.get_den());
        return r_new;
    }
    Rat operator*(const Rat & r, int i) {
        return i * r;
    }

    // v.
    Rat operator/(const Rat & r1, const Rat & r2) {
        int new_num = r1.get_num() * r2.get_den();
        int new_den = r1.get_den() * r2.get_num();
        Rat r(new_num, new_den);
        return r;
    }
    Rat operator/(int i, const Rat & r) {
        Rat r_new(i * r.get_den(), r.get_num());
        return r_new;
    }
    Rat operator/(const Rat & r, int i) {
        Rat r_new(r.get_num(), r.get_den() * i);
        return r_new;
    }

    // vi.
    bool operator==(const Rat & r1, const Rat & r2) {
        return (r1.get_num() == r2.get_num()) && (r1.get_den() == r2.get_den());
    }
    bool operator==(int i, const Rat & r) {
        return (i == r.get_num()) && (r.get_den() == 1);
    }
    bool operator==(const Rat & r, int i) {
        return i == r;
    }

    // vii.
    bool operator!=(const Rat & r1, const Rat & r2) {
        return !(r1 == r2);
    }
    bool operator!=(int i, const Rat & r) {
        return !(i == r);
    }
    bool operator!=(const Rat & r, int i) {
        return !(r == i);
    }

    // viii.
    bool operator<(const Rat & r1, const Rat & r2) {
        
    }
    bool operator<(int i, const Rat & r) {
        
    }
    bool operator<(const Rat & r, int i) {
        
    }

    // ix.
    bool operator<=(const Rat & r1, const Rat & r2) {
        return (r1 < r2) || (r1 == r2);
    }
    bool operator<=(int i, const Rat & r) {
        return (i < r) || (i == r);
    }
    bool operator<=(const Rat & r, int i) {
        return (r < i) || (r == i);
    }
}
