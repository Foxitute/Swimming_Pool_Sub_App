#pragma once
#ifndef Shape_h
#define Shape_h

#include <string>

namespace Shapes
{
    enum Shape {
        Round     = 1,
        Rectangle = 2,
        Square    = 3,
        Undefined = 4
    };

    inline Shape to_shape(std::string const& str)
    {
        return (str == "Round"     ? Round :
                str == "Rectangle" ? Rectangle :
                str == "Square"    ? Square : Undefined);
    }

    inline std::string to_string(Shape const& shape)
    {
        return (shape == Round     ? "Round" :
                shape == Rectangle ? "Rectangle" :
                shape == Square    ? "Square" : "Undefined");
    }
}
#endif /* Shape_h */
