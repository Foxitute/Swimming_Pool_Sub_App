#pragma once
#ifndef Subs_history_repository_h
#define Subs_history_repository_h

#include "Repository_base.h"
#include "Subs_history.h"

class Subs_history_repository : public Repository_base<Subs_history>
{
public:
    explicit Subs_history_repository (File_provider<Subs_history>* provider, Int_id_tracker* tracker)
        : Repository_base<Subs_history>(provider, tracker) {}
};

#endif /* Subs_history_repository_h */
