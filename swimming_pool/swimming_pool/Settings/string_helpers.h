#pragma once
#ifndef string_helpers_h
#define string_helpers_h

#include <string>
#include <vector>
#include <sstream>

typedef std::vector<std::string> vstring_t;

inline bool equal_ignore_case (std::string const& a, std::string const& b)
{
    return std::equal(a.begin(), a.end(), b.begin(), b.end(), [](char a, char b)
    {
        return std::tolower(a) == std::tolower(b);
    });
}

inline vstring_t split (std::string const& value, char const delimeter)
{
    std::stringstream ss(value);
    std::string item;
    vstring_t parts;
    while (getline(ss, item, delimeter))
    {
        parts.push_back(item);
    }
    return parts;
}

#endif /* string_helpers_hpp */
