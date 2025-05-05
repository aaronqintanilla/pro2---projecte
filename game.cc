#include "game.hh"
#include <cmath>
using namespace std;
using namespace pro2;

Game::Game(int width, int height)
    : mario_({width / 2, 150},Keys::Up, Keys::Left, Keys::Right),
      mario2_({width / 2 -30 , 150}, 'W', 'A', 'D'),
      platforms_{
          Platform(100, 300, 200, 211),
          Platform(0, 200, 250, 261),
          Platform(250, 400, 150, 161),
      },
      coins_{
        Objecte({260,90}),
        Objecte({300,90}),
        Objecte({340,90}),
        Objecte({380,90}),
      },
      paused_ (false),
      finished_(false),
      coins_collected(0) {
    for (int i = 1; i < 20; i++) {
        platforms_.push_back(Platform(250 + i * 200, 400 + i * 200, 150, 161));
    }
    for (int i = 1; i < 20; i++) {
        coins_.push_back(Objecte({260 + i * 200, 90}));
        coins_.push_back(Objecte({300 + i * 200, 90}));
        coins_.push_back(Objecte({340 + i * 200, 90}));
        coins_.push_back(Objecte({380 + i * 200, 90}));
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

    if (not coins_.empty()) {
        list<Objecte>::iterator it = coins_.begin();
        while (it != coins_.end()) {
            it->update(window);
            
            pro2::Rect rmario = mario_.get_rect();
            pro2::Rect rcoin = it->get_rect();
            
            if (objects_collision(rmario, rcoin)) {
                ++coins_collected;
                it = coins_.erase(it);
            }
            else ++it;
        }
        cout << coins_collected << endl;
    }
    
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

    for(Objecte& coin : coins_){
        coin.paint(window);
    }
    
}

