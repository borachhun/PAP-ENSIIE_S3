#include <vector>
#include "point2d.h"
#include "sdl.h"
#include "font.h"

int main() {
    sdl::Sdl sdl;

    if (sdl.init() != 0) {
        return -1;
    }

    std::vector<sdl::Window> wins;

    /* === WINDOW 1 === */
    // wins.push_back(
    //     sdl::Window("Circle", Point2d(200, 100), 640, 480)
    // );
    // std::vector<Point2d> circle{Point2d(443,240), Point2d(442,255), Point2d(440,271), Point2d(435,285),
    //                             Point2d(428,299), Point2d(420,313), Point2d(410,325), Point2d(399,335),
    //                             Point2d(386,344), Point2d(373,352), Point2d(358,357), Point2d(343,361),
    //                             Point2d(328,363), Point2d(312,363), Point2d(297,361), Point2d(282,357),
    //                             Point2d(267,352), Point2d(254,344), Point2d(241,335), Point2d(230,325),
    //                             Point2d(220,313), Point2d(212,299), Point2d(205,285), Point2d(200,271),
    //                             Point2d(198,255), Point2d(197,240), Point2d(198,225), Point2d(200,209), 
    //                             Point2d(205,195), Point2d(212,181), Point2d(220,167), Point2d(230,155),
    //                             Point2d(241,145), Point2d(254,136), Point2d(267,128), Point2d(282,123),
    //                             Point2d(297,119), Point2d(312,117), Point2d(328,117), Point2d(343,119),
    //                             Point2d(358,123), Point2d(373,128), Point2d(386,136), Point2d(399,145),
    //                             Point2d(410,155), Point2d(420,167), Point2d(428,181), Point2d(435,195), 
    //                             Point2d(440,209), Point2d(442,225), Point2d(443,240)};
    // wins[0].draw_curve(circle);
    // wins[0].present();

    /* === WINDOW 1 === */
    wins.push_back(
        sdl::Window("Font 1", Point2d(300, 200), 1280, 720)
    );

    Font font1;
    font1['A'] = Glyph(std::vector<Bezier>{
        // outside sides
        Bezier(Point2d(0,100), Point2d(50,0)), Bezier(Point2d(50,0), Point2d(100,100)),
        // feet
        Bezier(Point2d(0,100), Point2d(20,100)),Bezier(Point2d(80,100), Point2d(100,100)),
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
    font1['H'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(0,100)),       Bezier(Point2d(0,100), Point2d(20,100)),
        Bezier(Point2d(20,100), Point2d(20,60)),    Bezier(Point2d(20,60), Point2d(80,60)),
        Bezier(Point2d(80,60), Point2d(80,100)),    Bezier(Point2d(80,100), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(100,0)),   Bezier(Point2d(100,0), Point2d(80,0)),
        Bezier(Point2d(80,0), Point2d(80,40)),      Bezier(Point2d(80,40), Point2d(20,40)),
        Bezier(Point2d(20,40), Point2d(20,0)),      Bezier(Point2d(20,0), Point2d(0,0)),
    });
    font1['I'] = Glyph(std::vector<Bezier>{
        Bezier(Point2d(0,0), Point2d(100,0)),       Bezier(Point2d(100,0), Point2d(100,20)),
        Bezier(Point2d(100,20), Point2d(60,20)),    Bezier(Point2d(60,20), Point2d(60,80)),
        Bezier(Point2d(60,80), Point2d(100,80)),    Bezier(Point2d(100,80), Point2d(100,100)),
        Bezier(Point2d(100,100), Point2d(0,100)),   Bezier(Point2d(0,100), Point2d(0,80)),
        Bezier(Point2d(0,80), Point2d(40,80)),      Bezier(Point2d(40,80), Point2d(40,20)),
        Bezier(Point2d(40,20), Point2d(0,20)),      Bezier(Point2d(0,20), Point2d(0,0)),
    });

    // Bezier(Point2d(,), Point2d(,)),

    wins[0].draw_lines(font1['I'].get_drawing_points());
    wins[0].present();


    sdl.waiting(wins);

    sdl.quit();
    return 0;
}