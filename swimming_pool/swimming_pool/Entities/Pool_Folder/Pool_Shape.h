#pragma once
#ifndef P_Shape_h
#define P_Shape_h

#include <iostream>
#include <cmath>

#include "Shape.h"

using namespace Shapes;

class Pool_Shape
{
public:
    double length_, width_, depth_;
    Shapes::Shape shape_;
    
public:
    Pool_Shape ();
    Pool_Shape (double l, double w, double d, Shape const& s);
    Pool_Shape(Pool_Shape&& other);

    bool operator == (Pool_Shape const&);
    double calc_volume ();
    
    void choice_to_shape (size_t const& choice);
    std::string shape_to_string();
    
    void set_shape (Shape const& shape);
    void set_length (double);
    void set_width  (double);
    void set_depth  (double);
};

#endif /* P_Shape_h */
