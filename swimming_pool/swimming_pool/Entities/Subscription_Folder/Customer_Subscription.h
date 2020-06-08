#pragma once
#ifndef Customer_Subscription_h
#define Customer_Subscription_h

#include "date_time.h"
#include "Entity_base.h"

class Customer_Subscription : public Entity_base
{
public:
    std::string name = {};
    std::string type = {};
    date_time* effective_from = nullptr;
    date_time* effective_to = nullptr;
    int hours = 0;
    int max_unit_count = 0;
    std::string unit_title = {};
};

#endif /* Customer_Subscription_h */
