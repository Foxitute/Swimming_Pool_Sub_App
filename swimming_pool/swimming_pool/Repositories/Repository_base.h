#pragma once
#ifndef Repository_base_h
#define Repository_base_h

#include "File_provider.h"
#include "Entity_base.h"
#include "Int_id_tracker.h"

template <typename T> class Repository_base
{
protected:
    File_provider<T>* provider_;
    Int_id_tracker* tracker_;
    
protected:
    Repository_base (File_provider<T>* provider, Int_id_tracker* tracker);
    
public:
    virtual ~Repository_base() = default;
    
    virtual void add (T* entity);
    virtual std::vector<T*> get_collection ();
};

template<typename T> inline Repository_base<T>
::Repository_base (File_provider<T>* provider, Int_id_tracker* tracker)
   : tracker_(tracker)
{
    static_assert(std::is_base_of<Entity_base, T>::value, "T must derive from Entity_base");
    provider_ = provider;
}

template<typename T> inline void Repository_base<T>
::add (T* entity)
{
    entity->id_ = tracker_->get_id();
    provider_->append(entity);
}

template<typename T> inline std::vector<T*> Repository_base<T>
::get_collection ()
{
    return provider_->get_collection();
}

#endif /* Repository_base_h */
