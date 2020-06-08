#pragma once
#ifndef File_repository_uow_h
#define File_repository_uow_h

#include "app_setting_manager.h"
#include "Repository_uow.h"

class File_repository_uow final : public Repository_uow
{
private:
    app_setting_manager& app_setting_manager_;
    Pool_repository* pool_repository_ = nullptr;
    Location_repository* location_repository_ = nullptr;
    Subscription_repository* subscription_repository_ = nullptr;
    Pool_subscription_repository* pool_subscription_repository_ = nullptr;
    Subs_history_repository* subs_history_repository_ = nullptr;

public:
    File_repository_uow();
    Pool_repository* get_pool_repository() override;
    Location_repository* get_location_repository() override;
    Subscription_repository* get_subscription_repository() override;
    Pool_subscription_repository* get_pool_subscription_repository() override;
    Subs_history_repository* get_subs_history_repository() override;

    ~File_repository_uow() override
    {
        delete pool_repository_;
        delete subscription_repository_;
        delete pool_subscription_repository_;
        delete subs_history_repository_;
        delete location_repository_;
    };
};

#endif /* File_repository_uow_h */
