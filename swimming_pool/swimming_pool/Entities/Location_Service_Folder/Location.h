#pragma once
#ifndef Location_h
#define Location_h

#include <string>
#include "Entity_base.h"

class Location : public Entity_base
{
public:
    std::string name = {};
    std::string address = {};
};

#endif /* Location_h */
