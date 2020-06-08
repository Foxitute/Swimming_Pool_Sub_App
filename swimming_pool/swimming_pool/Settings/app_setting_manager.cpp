#include "app_setting_manager.h"

/*
 * Function that creates instance of app_setting_manager type
 */
app_setting_manager& app_setting_manager::get_instance ()
{
    static app_setting_manager* instance_;
    if (instance_ == nullptr)
    {
        instance_ = new app_setting_manager;
    }
    return *instance_;
}

/*
 * Function gets value of app_setting object by given key
 */
std::string app_setting_manager::get_value (std::string const& key)
{
    app_setting const* setting = find(std::move(key));
    return ( setting != nullptr ? setting->value : "" );
}

/*
 * Function adds new app_setting object with current key and value
 */
void app_setting_manager::add_value (std::string key, std::string value)
{
    auto setting = new app_setting;
    setting->key   = std::move(key);
    setting->value = std::move(value);
    
    settings_.push_back(setting);
    save_and_reload();
}

/*
 * Function ADDS new app_setting object if object with such a key DOESN'T exist
 *       OR UPDATES value of the existing setting if object with such a key EXISTS
 */
void app_setting_manager::add_or_update_value (std::string const& key, std::string const& value)
{
    app_setting* setting = find(key);
    
    if (setting == nullptr) {
        // add a new setting
        add_value(key, value);
    } else {
        // update the existing setting
        setting->value = value;
    }
    
    save_and_reload();
}

/*
 * Function returns : app_setting object if setting with such a key EXISTS
 *               OR : nullptr if it's not found
 */
app_setting* app_setting_manager::find (std::string const& key)
{
    for (auto setting : get_settings())
    {
        if (equal_ignore_case(setting->key, key))
        {
            return setting;
        }
    }
    return nullptr;
}

/*
 * Function returns vector of settings and uploads them if current settings' vector is empty
 */
vsettings_t& app_setting_manager::get_settings ()
{
    if (settings_.empty())
    {
        load_settings();
    }
    return settings_;
}

/*
 * Function saves and reloads the vector of current settings
 */
void app_setting_manager::save_and_reload ()
{
    save_settings();
    load_settings();
}

/*
 * Function saves vector of current settings into the "settings" file
 */
void app_setting_manager::save_settings ()
{
    std::ofstream writter(file_name_);
    for (const auto setting : settings_)
    {
        writter << setting->key << "|";
        writter << setting->value << std::endl;
    }
}

/*
 * Function reads the vector of settings from file and saves it
 */
void app_setting_manager::load_settings ()
{
    settings_.clear();
    std::string line;
    std::ifstream reader(file_name_);
    
    if (reader.is_open())
    {
        while (getline(reader, line))
        {
            vstring_t parts = split(line, '|');
            auto item = new app_setting;
            
            item->key   = parts[0];
            item->value = (parts.size() > 1) ? parts[1] : "";
            
            settings_.push_back(item);
        }
        reader.close();
    }
}
