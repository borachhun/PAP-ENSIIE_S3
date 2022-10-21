#include <iostream>
#include "vect.h"

int main() {
    ensiie::Vect v(5);
    v[0] = 7.0;
    v[1] = 11.0;
    v[2] = 13.0;
    v[3] = 17.0;
    v[4] = 19.0;

    ensiie::Vect v2(4);
    v2[0] = 7.1;
    v2[1] = 11.0;
    v2[2] = 13.0;
    v2[3] = 17.0;

    std::cout << v << v2 << std::endl;

    ensiie::Vect v3 = v2;

    std::cout << v3 << v2 << std::endl;

    return 0;
}