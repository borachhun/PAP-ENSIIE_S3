#include <iostream>
#include "rat.h"

using namespace std;

int main() {
    ensiie::Rat r1(12, 6);
    ensiie::Rat r2(3, 4);
    ensiie::Rat r3(5, 4);
    ensiie::Rat r4 = r2 + r3;
    cout << (r1 == r2) << endl;
    cout << (r1 == r4) << endl;
}