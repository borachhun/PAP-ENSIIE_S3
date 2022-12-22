#include <vector>
#include "point2d.hpp"
#include "font.hpp"
#include "window.hpp"
#include "sdl.hpp"

int main() {

    Font font1;
    font1['A'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,100), Point2d(38,0)),      Bezier(Point2d(38,0), Point2d(62,0)),
        Bezier(Point2d(62,0), Point2d(100,100)),    Bezier(Point2d(100,100), Point2d(76,100)),
        Bezier(Point2d(76,100), Point2d(67,76)),    Bezier(Point2d(67,76), Point2d(33,76)),
        Bezier(Point2d(33,76), Point2d(24,100)),    Bezier(Point2d(24,100), Point2d(0,100)),

        Bezier(Point2d(41,56), Point2d(50,32)),     Bezier(Point2d(50,32), Point2d(59,56)),
        Bezier(Point2d(59,56), Point2d(41,56))
    });
    font1['B'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,100), Point2d(0,0)),                           Bezier(Point2d(0,0), Point2d(50,0)),
        Bezier(Point2d(50,0), Point2d(100,25), Point2d(100,0)),         Bezier(Point2d(100,25), Point2d(80,50), Point2d(100,50)),
        Bezier(Point2d(80,50), Point2d(100,75), Point2d(100,50)),       Bezier(Point2d(100,75), Point2d(50,100), Point2d(100,100)),
        Bezier(Point2d(50,100), Point2d(0,100)),

        Bezier(Point2d(20,40), Point2d(20,20)),                         Bezier(Point2d(20,20), Point2d(50,20)),
        Bezier(Point2d(50,20), Point2d(80,30), Point2d(80,20)),         Bezier(Point2d(80,30), Point2d(50,40), Point2d(80,40)),
        Bezier(Point2d(50,40), Point2d(20,40)),

        Bezier(Point2d(20,80), Point2d(20,60)),                         Bezier(Point2d(20,60), Point2d(50,60)),
        Bezier(Point2d(50,60), Point2d(80,70), Point2d(80,60)),         Bezier(Point2d(80,70), Point2d(50,80), Point2d(80,80)),
        Bezier(Point2d(50,80), Point2d(20,80))
    });
    font1['C'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(100,0), Point2d(50,0)),                          Bezier(Point2d(50,0), Point2d(0,50), Point2d(0,0)),
        Bezier(Point2d(0,50), Point2d(50,100), Point2d(0,100)),         Bezier(Point2d(50,100), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(100,80)),                      Bezier(Point2d(100,80), Point2d(50,80)),
        Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20)),
        Bezier(Point2d(50,20), Point2d(100,20)),                        Bezier(Point2d(100,20), Point2d(100,0))
    });
    font1['D'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(50,0)),                            Bezier(Point2d(50,0), Point2d(100,50), Point2d(100,0)),
        Bezier(Point2d(100,50), Point2d(50,100), Point2d(100,100)),     Bezier(Point2d(50,100), Point2d(0,100)),
        Bezier(Point2d(0,100), Point2d(0,0)),

        Bezier(Point2d(20,20), Point2d(50,20)),                         Bezier(Point2d(50,20), Point2d(80,50), Point2d(80,20)),
        Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),         Bezier(Point2d(50,80), Point2d(20,80)),
        Bezier(Point2d(20,80), Point2d(20,20))
    });
    font1['E'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(100,80)),  Bezier(Point2d(100,80), Point2d(20,80)),
        Bezier(Point2d(20,80), Point2d(20,60)),     Bezier(Point2d(20,60), Point2d(100,60)),
        Bezier(Point2d(100,60), Point2d(100,40)),   Bezier(Point2d(100,40), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,20)),     Bezier(Point2d(20,20), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(100,0)),    Bezier(Point2d(100,0), Point2d(0,0))
    });
    font1['F'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
        Bezier(Point2d(20,100), Point2d(20,60)),    Bezier(Point2d(20,60), Point2d(100,60)),
        Bezier(Point2d(100,60), Point2d(100,40)),   Bezier(Point2d(100,40), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,20)),     Bezier(Point2d(20,20), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(100,0)),    Bezier(Point2d(100,0), Point2d(0,0))
    });
    font1['G'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(100,0), Point2d(50,0)),                          Bezier(Point2d(50,0), Point2d(0,50), Point2d(0,0)),
        Bezier(Point2d(0,50), Point2d(50,100), Point2d(0,100)),         Bezier(Point2d(50,100), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(100,40)),                      Bezier(Point2d(100,40), Point2d(50,40)),
        Bezier(Point2d(50,40), Point2d(50,60)),                         Bezier(Point2d(50,60), Point2d(80,60)),
        Bezier(Point2d(80,60), Point2d(80,80)),                         Bezier(Point2d(80,80), Point2d(50,80)),
        Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20)),
        Bezier(Point2d(50,20), Point2d(100,20)),                        Bezier(Point2d(100,20), Point2d(100,0))
    });
    font1['H'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
        Bezier(Point2d(20,100), Point2d(20,60)),    Bezier(Point2d(20,60), Point2d(80,60)),
        Bezier(Point2d(80,60), Point2d(80,100)),    Bezier(Point2d(80,100), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(100,0)),   Bezier(Point2d(100,0), Point2d(80,0)),
        Bezier(Point2d(80,0), Point2d(80,40)),      Bezier(Point2d(80,40), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,0)),      Bezier(Point2d(20,0), Point2d(0,0))
    });
    font1['I'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(60,20)),    Bezier(Point2d(60,20), Point2d(60,80)),
        Bezier(Point2d(60,80), Point2d(100,80)),    Bezier(Point2d(100,80), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(0,100)),   Bezier(Point2d(0,100), Point2d(0,80)),
        Bezier(Point2d(0,80), Point2d(40,80)),      Bezier(Point2d(40,80), Point2d(40,20)),
        Bezier(Point2d(40,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0))
    });
    font1['J'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(100,0)),                           Bezier(Point2d(100,0), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(60,20)),                        Bezier(Point2d(60,20), Point2d(60,70)),
        Bezier(Point2d(60,70), Point2d(30,100), Point2d(60,100)),       Bezier(Point2d(30,100), Point2d(0,70), Point2d(0,100)),
        Bezier(Point2d(0,70), Point2d(20,70)),                          Bezier(Point2d(20,70), Point2d(30,80), Point2d(20,80)),
        Bezier(Point2d(30,80), Point2d(40,70), Point2d(40,80)),         Bezier(Point2d(40,70), Point2d(40,20)),
        Bezier(Point2d(40,20), Point2d(0,20)),                          Bezier(Point2d(0,20), Point2d(0,0))
    });
    font1['K'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
        Bezier(Point2d(20,100), Point2d(20,61)),    Bezier(Point2d(20,61), Point2d(70,100)),
        Bezier(Point2d(70,100), Point2d(100,100)),  Bezier(Point2d(100,100), Point2d(35,49)),
        Bezier(Point2d(35,49), Point2d(100,0)),     Bezier(Point2d(100,0), Point2d(70,0)),
        Bezier(Point2d(70,0), Point2d(20,39)),      Bezier(Point2d(20,39), Point2d(20,0)),
        Bezier(Point2d(20,0), Point2d(0,0))
    });
    font1['L'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(100,80)),  Bezier(Point2d(100,80), Point2d(20,80)),
        Bezier(Point2d(20,80), Point2d(20,0)),      Bezier(Point2d(20,0), Point2d(0,0))
    });
    font1['M'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,100), Point2d(0,0)),       Bezier(Point2d(0,0), Point2d(20,0)),
        Bezier(Point2d(20,0), Point2d(50,50)),      Bezier(Point2d(50,50), Point2d(80,0)),
        Bezier(Point2d(80,0), Point2d(100,0)),      Bezier(Point2d(100,0), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(80,100)),  Bezier(Point2d(80,100), Point2d(80,40)),
        Bezier(Point2d(80,40), Point2d(50,90)),     Bezier(Point2d(50,90), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,100)),    Bezier(Point2d(20,100), Point2d(0,100))
    });
    font1['N'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,100), Point2d(0,0)),       Bezier(Point2d(0,0), Point2d(20,0)),
        Bezier(Point2d(20,0), Point2d(80,70)),      Bezier(Point2d(80,70), Point2d(80,0)),
        Bezier(Point2d(80,0), Point2d(100,0)),      Bezier(Point2d(100,0), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(80,100)),  Bezier(Point2d(80,100), Point2d(20,30)),
        Bezier(Point2d(20,30), Point2d(20,100)),    Bezier(Point2d(20,100), Point2d(0,100))
    });
    font1['O'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(50,0), Point2d(100,50), Point2d(100,0)),         Bezier(Point2d(100,50), Point2d(50,100), Point2d(100,100)),
        Bezier(Point2d(50,100), Point2d(0,50), Point2d(0,100)),         Bezier(Point2d(0,50), Point2d(50,0), Point2d(0,0)),

        Bezier(Point2d(50,20), Point2d(80,50), Point2d(80,20)),         Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),
        Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20))
    });
    font1['P'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,100), Point2d(0,0)),                           Bezier(Point2d(0,0), Point2d(70,0)),
        Bezier(Point2d(70,0), Point2d(100,30), Point2d(100,0)),         Bezier(Point2d(100,30), Point2d(70,60), Point2d(100,60)),
        Bezier(Point2d(70,60), Point2d(20,60)),                         Bezier(Point2d(20,60), Point2d(20,100)),
        Bezier(Point2d(20,100), Point2d(0,100)),

        Bezier(Point2d(20,20), Point2d(70,20)),                         Bezier(Point2d(70,20), Point2d(80,30), Point2d(80,20)),
        Bezier(Point2d(80,30), Point2d(70,40), Point2d(80,40)),         Bezier(Point2d(70,40), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,20))
    });
    font1['Q'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(50,0), Point2d(100,50), Point2d(100,0)),         Bezier(Point2d(100,50), Point2d(87,83), Point2d(100,75)),
        Bezier(Point2d(87,83), Point2d(100,100)),                       Bezier(Point2d(100,100), Point2d(80,100)),
        Bezier(Point2d(80,100), Point2d(75,93)),                        Bezier(Point2d(75,93), Point2d(50,100), Point2d(70,100)),
        Bezier(Point2d(50,100), Point2d(0,50), Point2d(0,100)),         Bezier(Point2d(0,50), Point2d(50,0), Point2d(0,0)),

        Bezier(Point2d(50,20), Point2d(80,50), Point2d(80,20)),         Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),
        Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20)),
    });
    font1['R'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,100), Point2d(0,0)),                           Bezier(Point2d(0,0), Point2d(70,0)),
        Bezier(Point2d(70,0), Point2d(100,30), Point2d(100,0)),         Bezier(Point2d(100,30), Point2d(70,60), Point2d(100,60)),
        Bezier(Point2d(70,60), Point2d(100,100)),                       Bezier(Point2d(100,100), Point2d(76,100)),
        Bezier(Point2d(76,100), Point2d(46,60)),                        Bezier(Point2d(46,60), Point2d(20,60)),
        Bezier(Point2d(20,60), Point2d(20,100)),                        Bezier(Point2d(20,100), Point2d(0,100)),

        Bezier(Point2d(20,20), Point2d(70,20)),                         Bezier(Point2d(70,20), Point2d(80,30), Point2d(80,20)),
        Bezier(Point2d(80,30), Point2d(70,40), Point2d(80,40)),         Bezier(Point2d(70,40), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,20))
    });
    font1['S'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(100,0), Point2d(30,0)),                          Bezier(Point2d(30,0), Point2d(0,30), Point2d(0,0)),
        Bezier(Point2d(0,30), Point2d(30,60), Point2d(0,60)),           Bezier(Point2d(30,60), Point2d(70,60)),
        Bezier(Point2d(70,60), Point2d(80,70), Point2d(80,60)),         Bezier(Point2d(80,70), Point2d(70,80), Point2d(80,80)),
        Bezier(Point2d(70,80), Point2d(0,80)),                          Bezier(Point2d(0,80), Point2d(0,100)),
        Bezier(Point2d(0,100), Point2d(70,100)),                        Bezier(Point2d(70,100), Point2d(100,70), Point2d(100,100)),
        Bezier(Point2d(100,70), Point2d(70,40), Point2d(100,40)),       Bezier(Point2d(70,40), Point2d(30,40)),
        Bezier(Point2d(30,40), Point2d(20,30), Point2d(20,40)),         Bezier(Point2d(20,30), Point2d(30,20), Point2d(20,20)),
        Bezier(Point2d(30,20), Point2d(100,20)),                        Bezier(Point2d(100,20), Point2d(100,0))
    });
    font1['T'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(60,20)),    Bezier(Point2d(60,20), Point2d(60,100)),
        Bezier(Point2d(60,100), Point2d(40,100)),   Bezier(Point2d(40,100), Point2d(40,20)),
        Bezier(Point2d(40,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0))
    });
    font1['U'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,50)),                            Bezier(Point2d(0,50), Point2d(50,100), Point2d(0,100)),
        Bezier(Point2d(50,100), Point2d(100,50), Point2d(100,100)),     Bezier(Point2d(100,50), Point2d(100,0)),
        Bezier(Point2d(100,0), Point2d(80,0)),                          Bezier(Point2d(80,0), Point2d(80,50)),                          
        Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),         Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),
        Bezier(Point2d(20,50), Point2d(20,0)),                          Bezier(Point2d(20,0), Point2d(0,0))
    });
    font1['V'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(38,100)),      Bezier(Point2d(38,100), Point2d(62,100)),
        Bezier(Point2d(62,100), Point2d(100,0)),    Bezier(Point2d(100,0), Point2d(76,0)),
        Bezier(Point2d(76,0), Point2d(50,68)),      Bezier(Point2d(50,68), Point2d(24,0)),
        Bezier(Point2d(24,0), Point2d(0,0))
    });
    font1['W'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(20,100)),      Bezier(Point2d(20,100), Point2d(40,100)),
        Bezier(Point2d(40,100), Point2d(50,50)),    Bezier(Point2d(50,50), Point2d(60,100)),
        Bezier(Point2d(60,100), Point2d(80,100)),   Bezier(Point2d(80,100), Point2d(100,0)),
        Bezier(Point2d(100,0), Point2d(80,0)),      Bezier(Point2d(80,0), Point2d(70,50)),
        Bezier(Point2d(70,50), Point2d(60,0)),      Bezier(Point2d(60,0), Point2d(40,0)),
        Bezier(Point2d(40,0), Point2d(30,50)),      Bezier(Point2d(30,50), Point2d(20,0)),
        Bezier(Point2d(20,0), Point2d(0,0))
    });
    font1['X'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(24,0)),        Bezier(Point2d(24,0), Point2d(50,34)),
        Bezier(Point2d(50,34), Point2d(76,0)),      Bezier(Point2d(76,0), Point2d(100,0)),
        Bezier(Point2d(100,0), Point2d(62,50)),     Bezier(Point2d(62,50), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(76,100)),  Bezier(Point2d(76,100), Point2d(50,66)),
        Bezier(Point2d(50,66), Point2d(24,100)),    Bezier(Point2d(24,100), Point2d(0,100)),
        Bezier(Point2d(0,100), Point2d(38,50)),     Bezier(Point2d(38,50), Point2d(0,0))
    });
    font1['Y'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(24,0)),        Bezier(Point2d(24,0), Point2d(50,39)),
        Bezier(Point2d(50,39), Point2d(76,0)),      Bezier(Point2d(76,0), Point2d(100,0)),
        Bezier(Point2d(100,0), Point2d(60,60)),     Bezier(Point2d(60,60), Point2d(60,100)),
        Bezier(Point2d(60,100), Point2d(40,100)),   Bezier(Point2d(40,100), Point2d(40,60)),
        Bezier(Point2d(40,60), Point2d(0,0))
    });
    font1['Z'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(30,80)),    Bezier(Point2d(30,80), Point2d(100,80)),
        Bezier(Point2d(100,80), Point2d(100,100)),  Bezier(Point2d(100,100), Point2d(0,100)),
        Bezier(Point2d(0,100), Point2d(0,80)),      Bezier(Point2d(0,80), Point2d(70,20)),
        Bezier(Point2d(70,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0))
    });


    sdl::Sdl sdl;

    if (sdl.init() != 0) {
        return -1;
    }
    
    const int WIN_WIDTH = 1100;
    const int WIN_HEIGHT = 380;

    /* === WINDOW 1 === */
    sdl.add_window("FONT 1", Point2d(100, 100), WIN_WIDTH, WIN_HEIGHT);

    int row = 0;
    int col = 0;
    for (char C='A'; C<='Z'; C++) {
        if (col == 9) {
            row++;
            col = 0;
        }
        sdl.get_window(0).draw_lines(font1[C].get_drawing_points(), 120*col+20, 120*row+20);
        col++;
    }

    sdl.get_window(0).present();

    sdl.waiting();

    sdl.quit();
    return 0;
}