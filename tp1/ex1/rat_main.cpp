#include <iostream>
#include "rat.h"

using namespace std;

int main() {
    ensiie::Rat r1(5, 6);
    ensiie::Rat r2(15, 18);
    cout << (r1 >= r2) << endl;
    cout << (r2 > r1) << endl;
}