#pragma once
#ifndef Subscription_serializer_h
#define Subscription_serializer_h

#include "Serializer.h"
#include "Customer_Subscription.h"

class Subscription_serializer : public Serializer<Customer_Subscription>
{
    std::string to_string(Customer_Subscription* entity) override;
    Customer_Subscription* to_object(std::string const& source) override;
};

#endif /* Subscription_serializer_h */
