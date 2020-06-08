#include "Pool_serializer.h"

/*
* Override of Serializer function for proper converting a Pool object to string
*/
std::string Pool_serializer::to_string (Pool* pool)
{
    Shape_serializer shape_serializer;
    return std::to_string(pool->id_) + delimeter_ +
           pool->serial_number_      + delimeter_ +
           shape_serializer.to_string(pool->pshape_);
}

/*
* Override of Serializer function for proper converting a string to Pool object
*/
Pool* Pool_serializer::to_object (std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 3) {
        return nullptr;
    }
        
    Pool* pool = new Pool;
    pool->id_ = std::stoi(parts[0]);
    pool->serial_number_ = parts[1];
    Shape_serializer shape_serializer;
    pool->pshape_ = shape_serializer.to_object(parts[2]);
    
    return pool;
}
