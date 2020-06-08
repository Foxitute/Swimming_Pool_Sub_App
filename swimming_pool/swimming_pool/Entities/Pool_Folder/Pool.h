#pragma once
#ifndef Pool_h
#define Pool_h

#include "Pool_Shape.h"
#include "Entity_base.h"

class Pool : public Entity_base
{
public:
    std::string serial_number_ = {};
    Pool_Shape* pshape_ = nullptr;
    
public:
    ~Pool() = default;
};

#endif /* Pool_h */
