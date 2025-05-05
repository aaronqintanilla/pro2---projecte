#include "utils.hh"
using namespace std;

namespace pro2 {

void paint_hline(pro2::Window& window, int xini, int xfin, int y, Color color) {
    for (int x = xini; x <= xfin; x++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_vline(pro2::Window& window, int x, int yini, int yfin, Color color) {
    for (int y = yini; y <= yfin; y++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_sprite(pro2::Window&              window,
                  pro2::Pt                   orig,
                  const vector<vector<int>>& sprite,
                  bool                       mirror) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            const int _j = mirror ? line.size() - j - 1 : j;
            if (line[_j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[_j]);
            }
        }
    }
}

void paint_square(pro2::Window& window, Rect& r, pro2::Color color, int size) {
    //Top line, bottom line: 
    for (int i = 0; i < size; ++i) {
        paint_hline(window, r.left, r.right, r.top + i, color);
        paint_hline(window, r.left, r.right, r.bottom - i - 1, color);
    }

    for (int i = 0; i < size; ++i) {
        paint_vline(window, r.left + i, r.top, r.bottom, color);
        paint_vline(window, r.right - i - 1, r.top, r.bottom, color);
    }
}

void paint_rect(pro2::Window& window, Rect& r, pro2::Color color) {
    //Opción 1: horizontales.
    for (int y = r.top; y < r.bottom; ++y) {
        paint_hline(window, r.left, r.right, y, color);
    } 
    /*
    //Opción 2: verticales.
    for (int x = r.left; x < r.right; ++x) {
        paint_vline(window, x, r.top, r.bottom-1, color);
    }
    //Opción 3: (por pixeles).
    for (int x = r.left; x < r.right; ++x) {
        for (int y = t.top()..)
    }
    */

    
}
}  // namespace pro2