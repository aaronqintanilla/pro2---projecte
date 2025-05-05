#ifndef MARIO_HH
#define MARIO_HH

#include <iostream>
#include <vector>
#include "platform.hh"
#include "window.hh"

class Mario {
 private:
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};
    int      accel_time_ = 0;

    int jumpkey_, left_key, right_key;

    bool grounded_ = false;
	bool looking_left_ = false;

	void apply_physics_();
	
 public:
    Mario(pro2::Pt pos, int jumpkey, int leftkey, int rightkey) : pos_(pos),
         last_pos_(pos), jumpkey_(jumpkey), left_key(leftkey), right_key(rightkey) {}

    void paint(pro2::Window& window) const;

    void paint2(pro2::Window& window) const;

    pro2::Pt pos() const {
        return pos_;
    }

    void set_y(int y) {
        pos_.y = y;
    }

    bool is_grounded() const {
        return grounded_;
    }

    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    void toggle_grounded() {
        set_grounded(!grounded_);
    }

    void jump();

    void update(pro2::Window& window, const std::vector<Platform>& platforms);

 private:
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    static const std::vector<std::vector<int>> mario_sprite_normal_2;
};

#endif