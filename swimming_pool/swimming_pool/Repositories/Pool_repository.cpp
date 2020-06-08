#include "Pool_repository.h"

Pool_repository::Pool_repository (File_provider<Pool>* provider, Int_id_tracker* tracker)
    : Repository_base(provider, tracker) {}

Pool* Pool_repository::get_by_number (std::string const& number) const
{
    auto pools = provider_->get_collection();
    for (auto const& pool : pools)
    {
        if (pool->serial_number_ == number){
            return pool;
        }
    }
    return nullptr;
}
