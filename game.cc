#include "game.hh"
using namespace pro2;

Game::Game(int width, int height)
    : mario_({width / 2, 150},Keys::Up, Keys::Left, Keys::Right),
      mario2_({width / 2 -30 , 150}, 'W', 'A', 'D'),
      platforms_{
          Platform(100, 300, 200, 211),
          Platform(0, 200, 250, 261),
          Platform(250, 400, 150, 161),
      },
      paused_ (false),
      finished_(false) {
    for (int i = 1; i < 20; i++) {
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
    }
}

void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(Keys::Escape)) {
        finished_ = true;
        return;
    }
    if (window.was_key_pressed('P')) {
        paused_ = !paused_;
        return;
    }

}

void Game::update_objects(pro2::Window& window) {
    mario_.update(window, platforms_);
    mario2_.update(window, platforms_);
}

void Game::update_camera(pro2::Window& window) {
    const Pt pos = mario_.pos();
    const Pt cam = window.camera_center();

    /*
    const int left = cam.x - window.width() / 4;
    const int right = cam.x + window.width() / 4;
    const int top = cam.y - window.height() / 4;
    const int bottom = cam.y + window.height() / 4;

    int dx = 0, dy = 0;
    if (pos.x > right) {
        dx = pos.x - right;
    } else if (pos.x < left) {
        dx = pos.x - left;
    }
    if (pos.y < top) {
        dy = pos.y - top;
    } else if (pos.y > bottom) {
        dy = pos.y - bottom;
    }
    */

    int dx = pos.x - cam.x;
    int dy = pos.y - cam.y;
    window.move_camera({dx, dy});
}

void Game::update(pro2::Window& window) {
    process_keys(window);
    if (!paused_) {
        update_objects(window);
        update_camera(window);
    }
}

void Game::paint(pro2::Window& window) {
    window.clear(sky_blue);
    Pt cam = window.camera_center(); 
    Rect rect;
    int left, right, top, bottom;
    int w = 50;
    int h = 40;
    left = cam.x - w/2;
    right = cam.x + w/2;
    top = cam.y - h/2;
    bottom = cam.y + h/2;
    rect = Rect({left, top, right, bottom});
    bool show = true;
    int fr_showing = 30;
    int frame = window.frame_count();
    if (frame%fr_showing == 0) show = !show;
    if (show) paint_rect(window, rect, yellow);

    for (const Platform& p : platforms_) {
        p.paint(window);
    }
    mario_.paint(window);
    mario2_.paint2(window);

    int size = 4;
    Pt topleft = window.topleft();
    left = topleft.x;
    right = topleft.x + window.width();
    top = topleft.y;
    bottom = topleft.y + window.height();
    rect = {left, top, right, bottom};
    paint_square(window, rect, red, size);


}
