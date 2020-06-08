#pragma once
#ifndef test_data_h
#define test_data_h

#include "Repository_uow.h"

class test_data
{
private:
    Repository_uow* uow_;
    
public:
    test_data (Repository_uow* uow);
    
    void run_test ();
    void run ();
    void thanks ();
    void run_location ();
    void run_subscription ();
    void run_pool ();
    void run_pool_subscription ();
    void run_subs_history ();
    
    void show ();
    void show_all_locations ();
    void show_all_subscriptions ();
    void show_all_pools ();
    void show_all_pool_subscriptions ();
    void show_all_subs_histories ();
    
private:
    void init_location (Location* location);
    void init_subscription (Customer_Subscription* subscription);
    void init_pool (Pool* pool);
    void init_pool_subscription (Pool_subscription* pool_sub);
    void init_subs_history (Subs_history* subs_history);
    
    void add_location (Location const& location) const;
    void add_subscription (Customer_Subscription const& subscription) const;
    void add_pool (Pool const& pool) const;
    void add_pool_subscription (Pool_subscription const& pool_sub) const;
    void add_subs_history (Subs_history const& subs_history) const;
    
    Pool_Shape* get_pool_shape ();
    date_time& get_date ();
    bool add_confirm ();
};

#endif /* test_data_h */
