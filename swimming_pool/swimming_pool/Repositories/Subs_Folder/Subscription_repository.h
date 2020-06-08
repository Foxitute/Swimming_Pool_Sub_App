#pragma once
#ifndef Subscription_repository_h
#define Subscription_repository_h

#include "Repository_base.h"
#include "Customer_Subscription.h"

class Subscription_repository : public Repository_base<Customer_Subscription>
{
public:
    Subscription_repository (File_provider<Customer_Subscription>* provider, Int_id_tracker* tracker)
        : Repository_base<Customer_Subscription>(provider, tracker) {}
};

#endif /* Subscription_repository_h */
