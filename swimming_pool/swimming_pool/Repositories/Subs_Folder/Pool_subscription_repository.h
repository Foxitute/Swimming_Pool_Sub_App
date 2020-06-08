#pragma once
#ifndef Pool_subscription_repository_h
#define Pool_subscription_repository_h

#include "Pool_subscription.h"
#include "Repository_base.h"

class Pool_subscription_repository : public Repository_base<Pool_subscription>
{
public:
    explicit Pool_subscription_repository (File_provider<Pool_subscription>* provider, Int_id_tracker* tracker)
        : Repository_base(provider, tracker) {}
};

#endif /* Pool_subscription_repository_h */
