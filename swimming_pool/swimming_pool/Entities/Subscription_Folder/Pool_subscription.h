#pragma once
#ifndef Pool_subscription_h
#define Pool_subscription_h

#include "date_time.h"
#include "Entity_base.h"

class Pool_subscription : public Entity_base
{
public:
    int pool_id = 0;
    int sub_id = 0;
    date_time* effective_from = nullptr;
    date_time* effective_to = nullptr;
    date_time* created_at = nullptr;
    int unit_count = 0;
};

#endif /* Pool_subscription_h */
