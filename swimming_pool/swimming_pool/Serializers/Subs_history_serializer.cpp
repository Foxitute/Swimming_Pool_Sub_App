#include "Subs_history_serializer.h"

/*
 * Override of Serializer function for proper converting a Subs_history object to string
 */
std::string Subs_history_serializer::to_string (Subs_history* entity)
{
    return std::to_string(entity->id_) + delimeter_ +
           std::to_string(entity->pool_subscription_id) + delimeter_ +
           entity->created_at->to_string() + delimeter_ +
           std::to_string(entity->units_used);
}

/*
 * Override of Serializer function for proper converting a string to Subs_history object
 */
Subs_history* Subs_history_serializer::to_object (std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 4) {
        return nullptr;
    }
    
    auto subs_history = new Subs_history;
    subs_history->id_ = std::stoi(parts[0]);
    subs_history->pool_subscription_id = std::stoi(parts[1]);
    subs_history->created_at = &date_time::parse(parts[2]);
    subs_history->units_used = stoi(parts[3]);

    return subs_history;
}
