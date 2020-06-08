#include "Location_serializer.h"

/*
* Override of Serializer function for proper converting a Location object to string
*/
std::string Location_serializer::to_string(Location* entity)
{
    return std::to_string(entity->id_) + delimeter_ + entity->name +
           delimeter_ + entity->address;
}

/*
* Override of Serializer function for proper converting a string to Location object
*/
Location* Location_serializer::to_object(std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 3) {
        return nullptr;
    }
    
    auto locate = new Location;
    locate->id_   = std::stoi(parts[0]);
    locate->name = parts[1];
    locate->address = parts[2];
    
    return locate;
}
