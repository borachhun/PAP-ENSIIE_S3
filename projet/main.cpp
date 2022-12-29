#include <vector>
#include "point2d.hpp"
#include "font.hpp"
#include "window.hpp"
#include "sdl.hpp"

int main() {

    // Initialize a font
    Font my_font;

    // Adding information to the font for all alphabets
    my_font['A'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(0,100), Point2d(38,0)),      Bezier(Point2d(38,0), Point2d(62,0)),
            Bezier(Point2d(62,0), Point2d(100,100)),    Bezier(Point2d(100,100), Point2d(76,100)),
            Bezier(Point2d(76,100), Point2d(67,76)),    Bezier(Point2d(67,76), Point2d(33,76)),
            Bezier(Point2d(33,76), Point2d(24,100)),    Bezier(Point2d(24,100), Point2d(0,100))
        },
        {   // Inner triangle
            Bezier(Point2d(41,56), Point2d(50,32)),     Bezier(Point2d(50,32), Point2d(59,56)),
            Bezier(Point2d(59,56), Point2d(41,56))
        }
    });
    my_font['B'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(0,100), Point2d(0,0)),                           Bezier(Point2d(0,0), Point2d(50,0)),
            Bezier(Point2d(50,0), Point2d(100,25), Point2d(100,0)),         Bezier(Point2d(100,25), Point2d(80,50), Point2d(100,50)),
            Bezier(Point2d(80,50), Point2d(100,75), Point2d(100,50)),       Bezier(Point2d(100,75), Point2d(50,100), Point2d(100,100)),
            Bezier(Point2d(50,100), Point2d(0,100))
        },
        {   // Upper inner hole
            Bezier(Point2d(20,40), Point2d(20,20)),                         Bezier(Point2d(20,20), Point2d(50,20)),
            Bezier(Point2d(50,20), Point2d(80,30), Point2d(80,20)),         Bezier(Point2d(80,30), Point2d(50,40), Point2d(80,40)),
            Bezier(Point2d(50,40), Point2d(20,40))
        },
        {   // Lower inner hole
            Bezier(Point2d(20,80), Point2d(20,60)),                         Bezier(Point2d(20,60), Point2d(50,60)),
            Bezier(Point2d(50,60), Point2d(80,70), Point2d(80,60)),         Bezier(Point2d(80,70), Point2d(50,80), Point2d(80,80)),
            Bezier(Point2d(50,80), Point2d(20,80))
        }
    });
    my_font['C'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(100,0), Point2d(50,0)),                          Bezier(Point2d(50,0), Point2d(0,50), Point2d(0,0)),
            Bezier(Point2d(0,50), Point2d(50,100), Point2d(0,100)),         Bezier(Point2d(50,100), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(100,80)),                      Bezier(Point2d(100,80), Point2d(50,80)),
            Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20)),
            Bezier(Point2d(50,20), Point2d(100,20)),                        Bezier(Point2d(100,20), Point2d(100,0))
        }
    });
    my_font['D'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(0,0), Point2d(50,0)),                            Bezier(Point2d(50,0), Point2d(100,50), Point2d(100,0)),
            Bezier(Point2d(100,50), Point2d(50,100), Point2d(100,100)),     Bezier(Point2d(50,100), Point2d(0,100)),
            Bezier(Point2d(0,100), Point2d(0,0))
        },
        {   // Inner hole
            Bezier(Point2d(20,20), Point2d(50,20)),                         Bezier(Point2d(50,20), Point2d(80,50), Point2d(80,20)),
            Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),         Bezier(Point2d(50,80), Point2d(20,80)),
            Bezier(Point2d(20,80), Point2d(20,20))
        }
    });
    my_font['E'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(100,80)),  Bezier(Point2d(100,80), Point2d(20,80)),
            Bezier(Point2d(20,80), Point2d(20,60)),     Bezier(Point2d(20,60), Point2d(100,60)),
            Bezier(Point2d(100,60), Point2d(100,40)),   Bezier(Point2d(100,40), Point2d(20,40)),
            Bezier(Point2d(20,40), Point2d(20,20)),     Bezier(Point2d(20,20), Point2d(100,20)),
            Bezier(Point2d(100,20), Point2d(100,0)),    Bezier(Point2d(100,0), Point2d(0,0))
        }
    });
    my_font['F'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
            Bezier(Point2d(20,100), Point2d(20,60)),    Bezier(Point2d(20,60), Point2d(100,60)),
            Bezier(Point2d(100,60), Point2d(100,40)),   Bezier(Point2d(100,40), Point2d(20,40)),
            Bezier(Point2d(20,40), Point2d(20,20)),     Bezier(Point2d(20,20), Point2d(100,20)),
            Bezier(Point2d(100,20), Point2d(100,0)),    Bezier(Point2d(100,0), Point2d(0,0))
        }
    });
    my_font['G'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(100,0), Point2d(50,0)),                          Bezier(Point2d(50,0), Point2d(0,50), Point2d(0,0)),
            Bezier(Point2d(0,50), Point2d(50,100), Point2d(0,100)),         Bezier(Point2d(50,100), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(100,40)),                      Bezier(Point2d(100,40), Point2d(50,40)),
            Bezier(Point2d(50,40), Point2d(50,60)),                         Bezier(Point2d(50,60), Point2d(80,60)),
            Bezier(Point2d(80,60), Point2d(80,80)),                         Bezier(Point2d(80,80), Point2d(50,80)),
            Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20)),
            Bezier(Point2d(50,20), Point2d(100,20)),                        Bezier(Point2d(100,20), Point2d(100,0))
        }
    });
    my_font['H'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
            Bezier(Point2d(20,100), Point2d(20,60)),    Bezier(Point2d(20,60), Point2d(80,60)),
            Bezier(Point2d(80,60), Point2d(80,100)),    Bezier(Point2d(80,100), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(100,0)),   Bezier(Point2d(100,0), Point2d(80,0)),
            Bezier(Point2d(80,0), Point2d(80,40)),      Bezier(Point2d(80,40), Point2d(20,40)),
            Bezier(Point2d(20,40), Point2d(20,0)),      Bezier(Point2d(20,0), Point2d(0,0))
        }
    });
    my_font['I'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
            Bezier(Point2d(100,20), Point2d(60,20)),    Bezier(Point2d(60,20), Point2d(60,80)),
            Bezier(Point2d(60,80), Point2d(100,80)),    Bezier(Point2d(100,80), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(0,100)),   Bezier(Point2d(0,100), Point2d(0,80)),
            Bezier(Point2d(0,80), Point2d(40,80)),      Bezier(Point2d(40,80), Point2d(40,20)),
            Bezier(Point2d(40,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0))
        }
    });
    my_font['J'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(100,0)),                           Bezier(Point2d(100,0), Point2d(100,20)),
            Bezier(Point2d(100,20), Point2d(60,20)),                        Bezier(Point2d(60,20), Point2d(60,70)),
            Bezier(Point2d(60,70), Point2d(30,100), Point2d(60,100)),       Bezier(Point2d(30,100), Point2d(0,70), Point2d(0,100)),
            Bezier(Point2d(0,70), Point2d(20,70)),                          Bezier(Point2d(20,70), Point2d(30,80), Point2d(20,80)),
            Bezier(Point2d(30,80), Point2d(40,70), Point2d(40,80)),         Bezier(Point2d(40,70), Point2d(40,20)),
            Bezier(Point2d(40,20), Point2d(0,20)),                          Bezier(Point2d(0,20), Point2d(0,0))
        }
    });
    my_font['K'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
            Bezier(Point2d(20,100), Point2d(20,61)),    Bezier(Point2d(20,61), Point2d(70,100)),
            Bezier(Point2d(70,100), Point2d(100,100)),  Bezier(Point2d(100,100), Point2d(35,49)),
            Bezier(Point2d(35,49), Point2d(100,0)),     Bezier(Point2d(100,0), Point2d(70,0)),
            Bezier(Point2d(70,0), Point2d(20,39)),      Bezier(Point2d(20,39), Point2d(20,0)),
            Bezier(Point2d(20,0), Point2d(0,0))
        }
    });
    my_font['L'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(100,80)),  Bezier(Point2d(100,80), Point2d(20,80)),
            Bezier(Point2d(20,80), Point2d(20,0)),      Bezier(Point2d(20,0), Point2d(0,0))
        }
    });
    my_font['M'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,100), Point2d(0,0)),       Bezier(Point2d(0,0), Point2d(20,0)),
            Bezier(Point2d(20,0), Point2d(50,50)),      Bezier(Point2d(50,50), Point2d(80,0)),
            Bezier(Point2d(80,0), Point2d(100,0)),      Bezier(Point2d(100,0), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(80,100)),  Bezier(Point2d(80,100), Point2d(80,40)),
            Bezier(Point2d(80,40), Point2d(50,90)),     Bezier(Point2d(50,90), Point2d(20,40)),
            Bezier(Point2d(20,40), Point2d(20,100)),    Bezier(Point2d(20,100), Point2d(0,100))
        }
    });
    my_font['N'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,100), Point2d(0,0)),       Bezier(Point2d(0,0), Point2d(20,0)),
            Bezier(Point2d(20,0), Point2d(80,70)),      Bezier(Point2d(80,70), Point2d(80,0)),
            Bezier(Point2d(80,0), Point2d(100,0)),      Bezier(Point2d(100,0), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(80,100)),  Bezier(Point2d(80,100), Point2d(20,30)),
            Bezier(Point2d(20,30), Point2d(20,100)),    Bezier(Point2d(20,100), Point2d(0,100))
        }
    });
    my_font['O'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(50,0), Point2d(100,50), Point2d(100,0)),         Bezier(Point2d(100,50), Point2d(50,100), Point2d(100,100)),
            Bezier(Point2d(50,100), Point2d(0,50), Point2d(0,100)),         Bezier(Point2d(0,50), Point2d(50,0), Point2d(0,0))
        },
        {   // Inner hole
            Bezier(Point2d(50,20), Point2d(80,50), Point2d(80,20)),         Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),
            Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20))
        }
    });
    my_font['P'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(0,100), Point2d(0,0)),                           Bezier(Point2d(0,0), Point2d(70,0)),
            Bezier(Point2d(70,0), Point2d(100,30), Point2d(100,0)),         Bezier(Point2d(100,30), Point2d(70,60), Point2d(100,60)),
            Bezier(Point2d(70,60), Point2d(20,60)),                         Bezier(Point2d(20,60), Point2d(20,100)),
            Bezier(Point2d(20,100), Point2d(0,100))
        },
        {   // Inner hole
            Bezier(Point2d(20,20), Point2d(70,20)),                         Bezier(Point2d(70,20), Point2d(80,30), Point2d(80,20)),
            Bezier(Point2d(80,30), Point2d(70,40), Point2d(80,40)),         Bezier(Point2d(70,40), Point2d(20,40)),
            Bezier(Point2d(20,40), Point2d(20,20))
        }
    });
    my_font['Q'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(50,0), Point2d(100,50), Point2d(100,0)),         Bezier(Point2d(100,50), Point2d(87,83), Point2d(100,75)),
            Bezier(Point2d(87,83), Point2d(100,100)),                       Bezier(Point2d(100,100), Point2d(80,100)),
            Bezier(Point2d(80,100), Point2d(75,93)),                        Bezier(Point2d(75,93), Point2d(50,100), Point2d(70,100)),
            Bezier(Point2d(50,100), Point2d(0,50), Point2d(0,100)),         Bezier(Point2d(0,50), Point2d(50,0), Point2d(0,0))
        },
        {   // Inner hole
            Bezier(Point2d(50,20), Point2d(80,50), Point2d(80,20)),         Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),
            Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),         Bezier(Point2d(20,50), Point2d(50,20), Point2d(20,20))
        }
    });
    my_font['R'] = Glyph(std::vector<std::vector<Bezier>>{
        {   // Outer outline
            Bezier(Point2d(0,100), Point2d(0,0)),                           Bezier(Point2d(0,0), Point2d(70,0)),
            Bezier(Point2d(70,0), Point2d(100,30), Point2d(100,0)),         Bezier(Point2d(100,30), Point2d(70,60), Point2d(100,60)),
            Bezier(Point2d(70,60), Point2d(100,100)),                       Bezier(Point2d(100,100), Point2d(76,100)),
            Bezier(Point2d(76,100), Point2d(46,60)),                        Bezier(Point2d(46,60), Point2d(20,60)),
            Bezier(Point2d(20,60), Point2d(20,100)),                        Bezier(Point2d(20,100), Point2d(0,100))
        },
        {   // Inner hole
            Bezier(Point2d(20,20), Point2d(70,20)),                         Bezier(Point2d(70,20), Point2d(80,30), Point2d(80,20)),
            Bezier(Point2d(80,30), Point2d(70,40), Point2d(80,40)),         Bezier(Point2d(70,40), Point2d(20,40)),
            Bezier(Point2d(20,40), Point2d(20,20))
        }
    });
    my_font['S'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(100,0), Point2d(30,0)),                          Bezier(Point2d(30,0), Point2d(0,30), Point2d(0,0)),
            Bezier(Point2d(0,30), Point2d(30,60), Point2d(0,60)),           Bezier(Point2d(30,60), Point2d(70,60)),
            Bezier(Point2d(70,60), Point2d(80,70), Point2d(80,60)),         Bezier(Point2d(80,70), Point2d(70,80), Point2d(80,80)),
            Bezier(Point2d(70,80), Point2d(0,80)),                          Bezier(Point2d(0,80), Point2d(0,100)),
            Bezier(Point2d(0,100), Point2d(70,100)),                        Bezier(Point2d(70,100), Point2d(100,70), Point2d(100,100)),
            Bezier(Point2d(100,70), Point2d(70,40), Point2d(100,40)),       Bezier(Point2d(70,40), Point2d(30,40)),
            Bezier(Point2d(30,40), Point2d(20,30), Point2d(20,40)),         Bezier(Point2d(20,30), Point2d(30,20), Point2d(20,20)),
            Bezier(Point2d(30,20), Point2d(100,20)),                        Bezier(Point2d(100,20), Point2d(100,0))
        }
    });
    my_font['T'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
            Bezier(Point2d(100,20), Point2d(60,20)),    Bezier(Point2d(60,20), Point2d(60,100)),
            Bezier(Point2d(60,100), Point2d(40,100)),   Bezier(Point2d(40,100), Point2d(40,20)),
            Bezier(Point2d(40,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0))
        }
    });
    my_font['U'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(0,50)),                            Bezier(Point2d(0,50), Point2d(50,100), Point2d(0,100)),
            Bezier(Point2d(50,100), Point2d(100,50), Point2d(100,100)),     Bezier(Point2d(100,50), Point2d(100,0)),
            Bezier(Point2d(100,0), Point2d(80,0)),                          Bezier(Point2d(80,0), Point2d(80,50)),                          
            Bezier(Point2d(80,50), Point2d(50,80), Point2d(80,80)),         Bezier(Point2d(50,80), Point2d(20,50), Point2d(20,80)),
            Bezier(Point2d(20,50), Point2d(20,0)),                          Bezier(Point2d(20,0), Point2d(0,0))
        }
    });
    my_font['V'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(38,100)),      Bezier(Point2d(38,100), Point2d(62,100)),
            Bezier(Point2d(62,100), Point2d(100,0)),    Bezier(Point2d(100,0), Point2d(76,0)),
            Bezier(Point2d(76,0), Point2d(50,68)),      Bezier(Point2d(50,68), Point2d(24,0)),
            Bezier(Point2d(24,0), Point2d(0,0))
        }
    });
    my_font['W'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(20,100)),      Bezier(Point2d(20,100), Point2d(40,100)),
            Bezier(Point2d(40,100), Point2d(50,50)),    Bezier(Point2d(50,50), Point2d(60,100)),
            Bezier(Point2d(60,100), Point2d(80,100)),   Bezier(Point2d(80,100), Point2d(100,0)),
            Bezier(Point2d(100,0), Point2d(80,0)),      Bezier(Point2d(80,0), Point2d(70,50)),
            Bezier(Point2d(70,50), Point2d(60,0)),      Bezier(Point2d(60,0), Point2d(40,0)),
            Bezier(Point2d(40,0), Point2d(30,50)),      Bezier(Point2d(30,50), Point2d(20,0)),
            Bezier(Point2d(20,0), Point2d(0,0))
        }
    });
    my_font['X'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(24,0)),        Bezier(Point2d(24,0), Point2d(50,34)),
            Bezier(Point2d(50,34), Point2d(76,0)),      Bezier(Point2d(76,0), Point2d(100,0)),
            Bezier(Point2d(100,0), Point2d(62,50)),     Bezier(Point2d(62,50), Point2d(100,100)),
            Bezier(Point2d(100,100), Point2d(76,100)),  Bezier(Point2d(76,100), Point2d(50,66)),
            Bezier(Point2d(50,66), Point2d(24,100)),    Bezier(Point2d(24,100), Point2d(0,100)),
            Bezier(Point2d(0,100), Point2d(38,50)),     Bezier(Point2d(38,50), Point2d(0,0))
        }
    });
    my_font['Y'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(24,0)),        Bezier(Point2d(24,0), Point2d(50,39)),
            Bezier(Point2d(50,39), Point2d(76,0)),      Bezier(Point2d(76,0), Point2d(100,0)),
            Bezier(Point2d(100,0), Point2d(60,60)),     Bezier(Point2d(60,60), Point2d(60,100)),
            Bezier(Point2d(60,100), Point2d(40,100)),   Bezier(Point2d(40,100), Point2d(40,60)),
            Bezier(Point2d(40,60), Point2d(0,0))
        }
    });
    my_font['Z'] = Glyph(std::vector<std::vector<Bezier>>{
        {
            Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
            Bezier(Point2d(100,20), Point2d(30,80)),    Bezier(Point2d(30,80), Point2d(100,80)),
            Bezier(Point2d(100,80), Point2d(100,100)),  Bezier(Point2d(100,100), Point2d(0,100)),
            Bezier(Point2d(0,100), Point2d(0,80)),      Bezier(Point2d(0,80), Point2d(70,20)),
            Bezier(Point2d(70,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0))
        }
    });


    // Initialize SDL
    sdl::Sdl sdl;

    if (sdl.init() != 0) {
        return -1;
    }
    
    const int WIN_WIDTH = 1100;
    const int WIN_HEIGHT = 380;

    // Create windows
    sdl.add_window("FONT 1", Point2d(100, 100), WIN_WIDTH, WIN_HEIGHT);
    sdl.add_window("FONT 2", Point2d(200, 200), WIN_WIDTH, WIN_HEIGHT);
    sdl.add_window("FONT 3", Point2d(300, 300), WIN_WIDTH, WIN_HEIGHT);

    // Draw alphabets on the windows
    int row = 0;
    int col = 0;
    for (char C='A'; C<='Z'; C++) {
        if (col == 9) {
            row++;
            col = 0;
        }
        std::vector<std::vector<Point2d>> outlines = my_font[C].get_drawing_points();
        for (int i=0; i<outlines.size(); i++) {

            // Draw outlines
            sdl.get_window(0).draw_lines(outlines[i], 120*col+20, 120*row+20, 0, 0, 0);
            sdl.get_window(1).draw_lines(outlines[i], 120*col+20, 120*row+20, 0, 0, 0);
            sdl.get_window(2).draw_lines(outlines[i], 120*col+20, 120*row+20, 0, 0, 0);
            
            // Fill alphabets
            if (i == 0) {   // Outer outline
                sdl.get_window(1).fill_polygon(outlines[i], 120*col+20, 120*row+20, 0, 0, 0);
                sdl.get_window(2).fill_polygon(outlines[i], 120*col+20, 120*row+20, 0, 0, 0);
            }
            else {          // Inner holes
                sdl.get_window(1).fill_polygon(outlines[i], 120*col+20, 120*row+20, 255, 255, 255);
                sdl.get_window(2).fill_polygon(outlines[i], 120*col+20, 120*row+20, 255, 255, 255);
            }
        }
        col++;
    }

    // Display the alphabets on the window
    sdl.get_window(0).present();
    sdl.get_window(1).present();
    sdl.get_window(2).present();

    // Waiting for all windows to be closed
    sdl.waiting();

    // Close SDL
    sdl.quit();

    return 0;
}