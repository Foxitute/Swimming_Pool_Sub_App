#pragma once
#ifndef Pool_serializer_h
#define Pool_serializer_h

#include "Pool.h"
#include "Shape_serializer.h"

class Pool_serializer : public Serializer<Pool>
{    
public:
    std::string to_string (Pool* pool) override;
    Pool* to_object (std::string const& source) override;
};

#endif /* Pool_serializer_h */
