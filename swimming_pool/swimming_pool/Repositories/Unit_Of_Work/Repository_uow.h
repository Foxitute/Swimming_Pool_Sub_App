#pragma once
#ifndef Repository_uow_h
#define Repository_uow_h

#include "Pool_repository.h"
#include "Location_repository.h"
#include "Subscription_repository.h"
#include "Pool_subscription_repository.h"
#include "Subs_history_repository.h"

class Repository_uow // Abstract class
{
public:
    virtual ~Repository_uow() = default;
    virtual Pool_repository* get_pool_repository () = 0;
    virtual Location_repository* get_location_repository() = 0;
    virtual Subscription_repository* get_subscription_repository() = 0;
    virtual Pool_subscription_repository* get_pool_subscription_repository() = 0;
    virtual Subs_history_repository* get_subs_history_repository() = 0;
};

#endif /* Repository_uow_h */
