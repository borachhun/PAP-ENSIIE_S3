#include <iostream>
#include "vect.h"

int main() {
    ensiie::Vect v(5);
    v[0] = 7.0;
    v[1] = 11.0;
    v[2] = 13.0;
    v[3] = 17.0;
    v[4] = 19.0;

    std::cout << v << std::endl;

    return 0;
}