#pragma once
#ifndef Pool_subs_history_h
#define Pool_subs_history_h

#include "date_time.h"
#include "Entity_base.h"

class Subs_history : public Entity_base
{
public:
    int pool_subscription_id = 0;
    date_time* created_at = nullptr;
    int units_used = 0;
};

#endif /* Pool_subs_history_h */
