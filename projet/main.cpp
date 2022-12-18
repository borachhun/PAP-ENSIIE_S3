#include <vector>
#include "sdl.h"

int main() {
    sdl::Sdl sdl;

    if (sdl.init() != 0) {
        return -1;
    }

    std::vector<sdl::Window> wins;

    /* === WINDOW 1 === */
    wins.push_back(
        sdl::Window("Font 1", 100, 100, 640, 480)
    );
    wins[0].draw_line(10, 10, 100, 100);
    wins[0].present();



    sdl.waiting(wins);

    sdl.quit();
    return 0;
}