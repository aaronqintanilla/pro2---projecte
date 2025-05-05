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

void Objecte::update(pro2::Window& window){}

pro2::Rect Objecte::get_rect() const{
    int l = pos_.x - 5;
    int t = pos_.y - 4;
    int r = pos_.x + 5;
    int b = pos_.y + 5;
    return pro2::Rect({l,t,r,b});
}