#ifndef NUMS_HH
#define NUMS_HH

#include <vector>
#include "window.hh"
#include "utils.hh"

const std::vector<std::vector<std::vector<int>>> nums_spr = {
    {

    },
    {

    },
};

void paint_score(pro2::Window& window, pro2::Pt pos, int x){
    const pro2::Pt top_left = {pos.x - width/2, pos.y - height/2+1};
    paint_sprite(window, top_left, nums_spr[x], false);
}
#endif