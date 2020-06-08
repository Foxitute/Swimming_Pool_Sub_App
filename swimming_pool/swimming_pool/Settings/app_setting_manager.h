#pragma once
#ifndef app_setting_manager_h
#define app_setting_manager_h

#include <ostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

#include "app_setting.h"
#include "string_helpers.h"

typedef std::vector<app_setting*> vsettings_t;

class app_setting_manager
{
private:
    std::string file_name_ = "settings.config";
    vsettings_t settings_;
    
private:
    app_setting_manager () = default;
    
public:
    static app_setting_manager& get_instance ();
    std::string get_value (std::string const& key);
    
    void add_value (std::string, std::string);
    void add_or_update_value (std::string const& key, std::string const& value);
    
private:
    app_setting* find (std::string const& key);
    vsettings_t& get_settings ();
    void save_and_reload ();
    void save_settings ();
    void load_settings ();
};

#endif /* app_setting_manager_h */
