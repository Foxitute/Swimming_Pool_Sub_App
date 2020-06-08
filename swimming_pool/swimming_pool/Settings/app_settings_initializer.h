#pragma once
#ifndef app_settings_initializer_h
#define app_settings_initializer_h

#include <map>

#include "app_setting_manager.h"
#include "app_setting_keys.h"

using namespace app_setting_keys;

class app_settings_initializer
{
private:
    std::map<std::string, std::string> default_settings_ =
    {
        {POOL_FILEPATH_KEY,"pool.txt"},
        {LOCATION_FILEPATH_KEY,"location.txt"},
        {SUBSCRIPTION_FILEPATH_KEY,"subs.txt"},
        {POOL_SUBSCRIPTION_FILEPATH_KEY,"pool_subs.txt"},
        {SUBS_HISTORY_FILEPATH_KEY,"subs_history.txt"}
    };
    
public:
    void check_and_init_settings ();
};

/*
 * Function checks values of all the settings :
 *          if the value is empty, adds setting to the settings' container
 */
inline void app_settings_initializer::check_and_init_settings ()
{
    auto settings = app_setting_manager::get_instance();
    
    for (auto const& default_setting : default_settings_)
    {
        std::string value = settings.get_value(default_setting.first);
        
        if (value.empty())
        {
            settings.add_value(default_setting.first, default_setting.second);
        }
    }
}

#endif /* app_settings_initializer_h */
