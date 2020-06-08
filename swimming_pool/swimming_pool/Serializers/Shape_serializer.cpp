#include "Shape_serializer.h"

Shape_serializer::Shape_serializer ()
{
    delimeter_ = '-';
}

/*
* Override of Serializer function for proper converting a P_Shape object to string
*/
std::string Shape_serializer::to_string (Pool_Shape* shape)
{
    return std::to_string(shape->length_) + delimeter_ +
           std::to_string(shape->width_)  + delimeter_ +
           std::to_string(shape->depth_)  + delimeter_ +
           shape->shape_to_string();
}

/*
* Override of Serializer function for proper converting a string to P_Shape object
*/
Pool_Shape* Shape_serializer::to_object(std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 4) {
        return nullptr;
    }
    
    Pool_Shape* p_shape = new Pool_Shape;
    p_shape->length_ = std::stod(parts[0]);
    p_shape->width_  = std::stod(parts[1]);
    p_shape->depth_  = std::stod(parts[2]);
    p_shape->shape_  = Shapes::to_shape(parts[3]);
    return p_shape;
}
