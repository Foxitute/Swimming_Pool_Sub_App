#pragma once
#ifndef app_setting_keys_h
#define app_setting_keys_h

#include <string>

namespace app_setting_keys
{
                    // FILE_PATH_KEYS
    static std::string POOL_FILEPATH_KEY = "pool_file_path";
    static std::string LOCATION_FILEPATH_KEY = "location_file_path";
    static std::string SUBSCRIPTION_FILEPATH_KEY = "subscription_file_path";
    static std::string POOL_SUBSCRIPTION_FILEPATH_KEY = "pool_subscription_file_path";
    static std::string SUBS_HISTORY_FILEPATH_KEY = "pool_subs_history_file_path";
                    // ID_TRACKER_KEYS
    static std::string POOL_ID_TRACKER_KEY = "latest_card_id";
    static std::string LOCATION_ID_TRACKER_KEY = "latest_location_id";
    static std::string SUBSCRIPTION_ID_TRACKER_KEY = "latest_subscription_id";
    static std::string POOL_SUBSCRIPTION_ID_TRACKER_KEY = "latest_pool_subscription_id";
    static std::string SUBS_HISTORY_ID_TRACKER_KEY = "latest_pool_subs_history_id";
}

#endif /* app_setting_keys_h */
