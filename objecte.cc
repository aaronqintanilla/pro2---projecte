#include "objecte.hh"
#include "utils.hh"
using namespace std;
using namespace pro2;

using pro2::Color;
const int _ = -1;
const int y = pro2::yellow;
const int h = pro2::black;
const int w = pro2::white;
const int t = 0x5c94fc;

const std::vector<std::vector<int>> Objecte::object_texture_ = {
    {t,t,h,h,h,h,h,h,t,t},
    {t,h,w,w,y,y,y,y,h,t},
    {t,h,w,w,y,y,y,y,h,t},
    {t,h,w,w,y,y,y,y,h,t},
    {t,h,y,y,y,y,y,y,h,t},
    {t,h,y,y,y,y,y,y,h,t},
    {t,h,y,y,y,y,y,y,h,t},
    {t,h,y,y,y,y,y,y,h,t},
    {t,h,y,y,y,y,y,y,h,t},
    {t,h,y,y,y,y,y,y,h,t},
    {t,t,h,h,h,h,h,h,t,t},
};

void Objecte::paint(pro2::Window& window) const {
    //10 por 10
    const Pt top_left = {pos_.x - 10/2, pos_.y - 10/2-1};
    paint_sprite(window, top_left, object_texture_, false);
}

void Objecte::update(pro2::Window& window, const std::vector<Platform>& platforms){}