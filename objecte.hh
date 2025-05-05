#ifndef OBJECTE_HH
#define OBJECTE_HH

#include <iostream>
#include <vector>
#include "platform.hh"
#include "window.hh"

class Objecte {
    private:
        pro2::Pt pos_;
        
	    static const std::vector<std::vector<int>> object_texture_;

    public:
        Objecte() : pos_({0,0}) {}

        Objecte(pro2::Pt pos): pos_(pos){}
        
        void paint(pro2::Window& window) const;
        void update(pro2::Window& window);

        pro2::Pt pos() const {
            return pos_;
            
        }

        pro2::Rect get_rect() const;



};

#endif