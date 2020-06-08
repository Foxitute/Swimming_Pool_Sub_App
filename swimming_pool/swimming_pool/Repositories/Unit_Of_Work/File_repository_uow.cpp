#include "File_repository_uow.h"
#include "app_setting_keys.h"
#include "Pool_serializer.h"
#include "Subs_history_serializer.h"
#include "Pool_subscription_serializer.h"
#include "Location_serializer.h"
#include "Subscription_serializer.h"
#include "Default_id_tracker.h"

using namespace app_setting_keys;
/*
 * Constructor creates an instance of app_setting_manager type
 */
File_repository_uow::File_repository_uow ()
    : app_setting_manager_(app_setting_manager::get_instance()) {}

/*
 * Function returns a Pool_repository object
 */
Pool_repository* File_repository_uow::get_pool_repository()
{
    // Create new - if not created
    if (pool_repository_ == nullptr)
    {
        const auto serializer = new Pool_serializer;
        const auto file_path  = app_setting_manager_.get_value(POOL_FILEPATH_KEY);
        const auto provider   = new File_provider<Pool>(*serializer, file_path);
        const auto tracker    = Default_id_tracker::create_instance(POOL_ID_TRACKER_KEY);
        pool_repository_ = new Pool_repository(provider, tracker);
    }
    
    return pool_repository_;
}

/*
 * Function returns a Location_repository object
 */
Location_repository* File_repository_uow::get_location_repository()
{
    // Create new - if not created
    if (location_repository_ == nullptr)
    {
        const auto serializer = new Location_serializer;
        const auto file_path  = app_setting_manager_.get_value(LOCATION_FILEPATH_KEY);
        const auto provider   = new File_provider<Location>(*serializer, file_path);
        const auto tracker    = Default_id_tracker::create_instance(LOCATION_ID_TRACKER_KEY);
        location_repository_ = new Location_repository(provider, tracker);
    }
    
    return location_repository_;
}

/*
 * Function returns a Subscription_repository object
 */
Subscription_repository* File_repository_uow::get_subscription_repository()
{
    // Create new - if not created
    if (subscription_repository_ == nullptr)
    {
        const auto serializer = new Subscription_serializer;
        const auto file_path  = app_setting_manager_.get_value(SUBSCRIPTION_FILEPATH_KEY);
        const auto provider   = new File_provider<Customer_Subscription>(*serializer, file_path);
        const auto tracker    = Default_id_tracker::create_instance(SUBSCRIPTION_ID_TRACKER_KEY);
        subscription_repository_ = new Subscription_repository(provider, tracker);
    }
    
    return subscription_repository_;
}

/*
 * Function returns a Pool_subscription_repository object
 */
Pool_subscription_repository* File_repository_uow::get_pool_subscription_repository()
{
    // Create new - if not created
    if (pool_subscription_repository_ == nullptr)
    {
        const auto serializer = new Pool_subscription_serializer;
        const auto file_path  = app_setting_manager_.get_value(POOL_SUBSCRIPTION_FILEPATH_KEY);
        const auto provider   = new File_provider<Pool_subscription>(*serializer, file_path);
        const auto tracker    = Default_id_tracker::create_instance(POOL_SUBSCRIPTION_ID_TRACKER_KEY);
        pool_subscription_repository_ = new Pool_subscription_repository(provider, tracker);
    }

    return pool_subscription_repository_;
}

/*
 * Function returns a Subs_history_repository object
 */
Subs_history_repository* File_repository_uow::get_subs_history_repository()
{
    // Create new - if not created
    if (subs_history_repository_ == nullptr)
    {
        const auto serializer = new Subs_history_serializer;
        const auto file_path  = app_setting_manager_.get_value(SUBS_HISTORY_FILEPATH_KEY);
        const auto provider   = new File_provider<Subs_history>(*serializer, file_path);
        const auto tracker    = Default_id_tracker::create_instance(SUBS_HISTORY_ID_TRACKER_KEY);
        subs_history_repository_ = new Subs_history_repository(provider, tracker);
    }
    
    return subs_history_repository_;
}
