#include "Default_id_tracker.h"

Default_id_tracker::Default_id_tracker (app_setting_manager& settings_manager, std::string& track_key)
    : settings_manager_(settings_manager)
    , track_key_(track_key) {
}

Default_id_tracker* Default_id_tracker::create_instance(std::string& key)
{
    return new Default_id_tracker(app_setting_manager::get_instance(), key);
}

int Default_id_tracker::get_id()
{
    int integer = 0;
    std::string const value = settings_manager_.get_value(track_key_);
    
    if (!value.empty())
    {
        integer = std::stoi(value);
    }

    ++integer;
    settings_manager_.add_or_update_value(track_key_, std::to_string(integer));
    
    return integer;
}
