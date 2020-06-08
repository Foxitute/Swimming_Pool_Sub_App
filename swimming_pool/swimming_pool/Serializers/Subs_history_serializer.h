#pragma once
#ifndef Pool_subs_history_serializer_h
#define Pool_subs_history_serializer_h

#include "Serializer.h"
#include "Subs_history.h"

class Subs_history_serializer : public Serializer<Subs_history>
{
public:
    std::string to_string (Subs_history* entity) override;
    Subs_history* to_object (std::string const& source) override;
};

#endif /* Pool_subs_history_serializer_h */
