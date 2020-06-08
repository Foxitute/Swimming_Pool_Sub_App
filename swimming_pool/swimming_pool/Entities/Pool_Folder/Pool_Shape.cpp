#include "Pool_Shape.h"

Pool_Shape::Pool_Shape(double length, double width, double depth, Shape const& shape)
    : length_(length)
    , width_(width)
    , depth_(depth)
    , shape_(shape) {
}

Pool_Shape::Pool_Shape() : Pool_Shape(0,0,0,Undefined) {}

Pool_Shape::Pool_Shape(Pool_Shape&& other)
    : length_(std::move(other.length_))
    , width_ (std::move(other.width_ ))
    , depth_ (std::move(other.depth_ ))
    , shape_ (std::move(other.shape_ )) {
}

bool Pool_Shape::operator == (Pool_Shape const& p_shape)
{
    return (length_ == p_shape.length_ &&
            width_  == p_shape.width_  &&
            depth_  == p_shape.depth_  &&
            shape_  == p_shape.shape_  );
}

double Pool_Shape::calc_volume()
{
    if (shape_ == Round)
        return 2 * M_PI * pow((length_/2.), 2.) * depth_;
    else if (shape_ == Rectangle)
        return length_ * width_ * depth_;
    else if (shape_ == Square)
        return pow(length_, 2.) * depth_;
    
    throw std::runtime_error("Undefined Shape!!! in calc_volume function");
}

void Pool_Shape::choice_to_shape(size_t const& choice)
{
    shape_ = (choice == 1 ? Round :
              choice == 2 ? Rectangle :
              choice == 3 ? Square : Undefined);
    if (shape_ == Undefined)
        throw std::runtime_error("Undefined Shape!!! in choice_to_shape function");
}

std::string Pool_Shape::shape_to_string() { return Shapes::to_string(shape_); }
void Pool_Shape::set_length(double length){ length_= length; }
void Pool_Shape::set_width (double width) { width_ = width;  }
void Pool_Shape::set_depth (double depth) { depth_ = depth;  }
void Pool_Shape::set_shape (Shape const& shape) { shape_ = shape; }
