#include "Subscription_serializer.h"

/*
 * Override of Serializer function for proper converting a Subscription object to string
 */
std::string Subscription_serializer::to_string (Customer_Subscription* entity) {
    return std::to_string(entity->id_) + delimeter_ +
    entity->name + delimeter_ + entity->type + delimeter_ +
    entity->unit_title + delimeter_ + std::to_string(entity->max_unit_count) + delimeter_ +
    ( entity->effective_from == nullptr ? "" : entity->effective_from->to_string() ) + delimeter_ +
    ( entity->effective_to == nullptr ? "" : entity->effective_to->to_string() ) + delimeter_ +
    std::to_string(entity->hours);
}

/*
 * Override of Serializer function for proper converting a string to Subscription object
 */
Customer_Subscription* Subscription_serializer::to_object (std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 8) {
        return nullptr;
    }
    
    auto subs = new Customer_Subscription;
    subs->id_ = std::stoi(parts[0]);
    subs->name = parts[1];
    subs->type = parts[2];
    subs->unit_title = parts[3];
    subs->max_unit_count = std::stoi(parts[4]);
    if (!parts[5].empty()) {
        subs->effective_from = &date_time::parse(parts[5]);
    }
    if (!parts[6].empty()) {
        subs->effective_to = &date_time::parse(parts[6]);
    }
    subs->hours = std::stoi(parts[7]);
    
    return subs;
}
