#pragma once
#ifndef Pool_subscription_serializer_h
#define Pool_subscription_serializer_h

#include "Serializer.h"
#include "Pool_subscription.h"

class Pool_subscription_serializer : public Serializer<Pool_subscription>
{
public:
    std::string to_string(Pool_subscription* entity) override;
    Pool_subscription* to_object(std::string const& source) override;
};

#endif /* Pool_subscription_serializer_h */
