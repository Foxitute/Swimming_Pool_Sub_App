#pragma once
#ifndef Serializer_h
#define Serializer_h

#include <string>
#include <sstream>
#include <vector>

typedef std::vector<std::string> vstring_t;

template <typename T> class Serializer // Abstract class
{
protected:
    char delimeter_ = '|';
    
public:
    virtual T* to_object(std::string const& source) = 0; // PVF
    virtual std::string to_string(T* entity) = 0; // PVF
    
protected:
    Serializer () = default;
    Serializer (char delimeter) : delimeter_(delimeter) { }
    
    vstring_t split(std::string const& source, char const& delimeter);
};

/*
 * Function splits source string into container of smaler parts
 *                                divided by a proper delimeter
 */
template<typename T> inline vstring_t Serializer<T>
::split(std::string const& source, char const& delimeter)
{
    vstring_t splittedStrings;
    std::stringstream ss(source);
    std::string item;
    
    while (getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

#endif /* Serializer_h */
