#pragma once
#ifndef Pool_repository_h
#define Pool_repository_h
#include "Repository_base.h"
#include "Pool.h"

class Pool_repository : public Repository_base<Pool>
{
public:
    Pool_repository (File_provider<Pool>* provider, Int_id_tracker* tracker);
    Pool* get_by_number (std::string const& number) const;
};

#endif /* Pool_repository_h */
