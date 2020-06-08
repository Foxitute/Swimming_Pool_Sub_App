#pragma once
#ifndef Shape_serializer_h
#define Shape_serializer_h

#include "Serializer.h"
#include "Pool_Shape.h"

class Shape_serializer : public Serializer<Pool_Shape>
{
public:
    Shape_serializer();
    virtual std::string to_string (Pool_Shape* shape) override;

    virtual Pool_Shape* to_object(std::string const& source) override;
};
#endif /* Shape_serializer_h */
