#pragma once
#ifndef File_provider_h
#define File_provider_h
#include "Serializer.h"

#include <iostream>
#include <fstream>

template <typename T> class File_provider
{
private:
    Serializer<T>* serializer_ = nullptr;
    std::string file_name_ = {};
    
public:
    File_provider (Serializer<T>& serializer, std::string const&);
    File_provider (File_provider&&);
    ~File_provider() { delete serializer_; };
    
    std::vector<T*> get_collection ();
    void append (T* entity);
    void append_range (std::vector<T*>);
    void clear ();
    
private:
    File_provider (File_provider const&) = delete;
    File_provider& operator = (File_provider const&) = delete;
};


template <typename T> inline File_provider<T>
::File_provider(Serializer<T>& serializer, std::string const& file_name)
    : serializer_(&serializer)
    , file_name_ (file_name) {}

template <typename T> inline File_provider<T>
::File_provider (File_provider&& other)
    : serializer_(std::move(other.serializer_))
    , file_name_(std::move(other.file_name_)) {}

/*
 * Get all entities from file
 */
template <typename T> inline std::vector<T*> File_provider<T>
::get_collection()
{
    std::ifstream reader;
    std::vector<T*> entities;
    
    try {
        reader.open(file_name_);
    }
    catch (std::ifstream::failure const& ex) {
        std::cerr << "Something wrong happened : " << ex.what()
                  << "\nCODE : " << ex.code() << "\n";
    }
    
    if (reader.is_open())
    {
        std::string line;
        while (getline(reader, line))
        {
            T* entity = serializer_->to_object(line);
            if (entity != nullptr) {
                entities.push_back(entity);
            }
        }
        reader.close();
    }
    return entities;
}
/*
 * Append file with one new object
 */
template <typename T> inline void File_provider<T>
::append (T* entity)
{
    std::ofstream writer(file_name_, std::ios::app);
    if (writer.is_open())
    {
        std::string line = serializer_->to_string(entity);
        writer << line << std::endl;
    }
}
/*
 * Append file with vector of new object
 */
template <typename T> inline void File_provider<T>
::append_range (std::vector<T*> entities)
{
    std::ofstream writer (file_name_, std::ios::app);
    if (writer.is_open())
    {
        for (auto const& entity : entities)
        {
            std::string line = serializer_->to_string(entity);
            writer << line << std::endl;
        }
        writer.close();
    }
}
/*
 * Truncate all the content of current file
 */
template <typename T> inline void File_provider<T>
::clear()
{
    std::ofstream ofs (file_name_, std::ios::out | std::ios::trunc);
    ofs.close();
}
#endif /* File_provider_h */
