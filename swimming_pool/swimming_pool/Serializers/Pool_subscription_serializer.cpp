#include "Pool_subscription_serializer.h"

/*
 * Override of Serializer function for proper converting a Pool_subscription object to string
 */
std::string Pool_subscription_serializer::to_string(Pool_subscription* entity)
{
    return std::to_string(entity->id_) + delimeter_ +
    std::to_string(entity->pool_id)    + delimeter_ +
    std::to_string(entity->sub_id) + delimeter_ +
    ( entity->created_at == nullptr ? "" : entity->created_at->to_string() ) + delimeter_ +
    ( entity->effective_from == nullptr ? "" : entity->effective_from->to_string() ) + delimeter_ +
    ( entity->effective_to == nullptr ? "" : entity->effective_to->to_string() ) + delimeter_ +
    std::to_string(entity->unit_count);
}

/*
 * Override of Serializer function for proper converting a string to Pool_subscription object
 */
Pool_subscription* Pool_subscription_serializer::to_object(std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 7) {
        return nullptr;
    }
    
    auto pools = new Pool_subscription;
    pools->id_ = std::stoi(parts[0]);
    pools->pool_id = std::stoi(parts[1]);
    pools->sub_id = std::stoi(parts[2]);
    if (!parts[3].empty()) {
        pools->created_at = &date_time::parse(parts[3]);
    }
    if (!parts[4].empty()) {
        pools->effective_from = &date_time::parse(parts[4]);
    }
    if (!parts[5].empty()) {
        pools->effective_to = &date_time::parse(parts[5]);
    }
    pools->unit_count = std::stoi(parts[6]);
    
    return pools;
}
