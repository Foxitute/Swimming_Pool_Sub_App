#pragma once
#ifndef Location_serializer_h
#define Location_serializer_h
#include "Location.h"
#include "Serializer.h"

class Location_serializer : public Serializer<Location>
{
    std::string to_string(Location* entity) override;
    Location* to_object(std::string const& source) override;
};

#endif /* Location_serializer_h */
