#include <iostream>
#include "vect.h"

#include <algorithm>
#include <chrono>
#include <vector>

int main() {
    const int N = 100000000;

    ensiie::Vect v1(N), v2(N);
    std::vector<double> v3(N), v4(N);

    for (int i=0; i<N; i++) {
        v1[i] = i + 1.1;
        v3[i] = i + 1.1;

        v2[i] = i + 2.2;
        v4[i] = i + 2.2;
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    std::swap(v1, v2);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::swap(v3, v4);
    auto t3 = std::chrono::high_resolution_clock::now();

    std::cout << "First swap: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count() << " ns" << std::endl;
    std::cout << "Second swap: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t3-t2).count() << " ns" << std::endl;

    return 0;
}