#pragma once
#ifndef Default_id_tracker_h
#define Default_id_tracker_h

#include "Int_id_tracker.h"
#include "app_setting_manager.h"

class Default_id_tracker : public Int_id_tracker
{
private:
    app_setting_manager& settings_manager_;
    std::string track_key_;
    
public:
    Default_id_tracker (app_setting_manager&, std::string&);
    
    static Default_id_tracker* create_instance (std::string& key);
    int get_id () override;
};

#endif /* Default_id_tracker_h */
