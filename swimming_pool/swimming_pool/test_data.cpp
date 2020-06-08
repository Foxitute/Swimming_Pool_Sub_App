#include "test_data.h"
#include <iostream>
#include <limits>

test_data::test_data (Repository_uow* uow)
    : uow_(uow) {}

void test_data::run_test ()
{
    // ADD TEST LOCATION
    Location test_location;
    test_location.name = "Poseidon"; // name
    test_location.address = "Ivano-Frankivsk Halytzka Street";
    
    add_location(test_location);

    // ADD TEST SUBSCRIPTION
    Customer_Subscription test_subscription;
    test_subscription.name = "Elena Kazenelson"; // name
    test_subscription.type = "PayAsYouGo";       // type
    test_subscription.effective_from = &date_time::parse("2020/06/07 TIME/11:08:14"); // from
    test_subscription.effective_to = &date_time::parse("2020/08/23 TIME/03:59:59"); // to
    test_subscription.hours = 12;  // hours
    test_subscription.max_unit_count = 10; // max_unit_count
    test_subscription.unit_title = "day";  // unit_title
    
    add_subscription(test_subscription);

    // ADD TEST POOL
    Pool test_pool;
    test_pool.serial_number_ = "1234567890"; // serial_number
    test_pool.pshape_ = new Pool_Shape(50.35, 20.1, 3.2, Shapes::Shape::Rectangle); // pool_shape
    
    add_pool(test_pool);

    // ADD TEST POOL_SUBSCRIPTION
    Pool_subscription test_pool_subscription;
    
    test_pool_subscription.pool_id = 1;  // pool_id
    test_pool_subscription.sub_id = 1;  // subscription_id
    test_pool_subscription.effective_from = &date_time::now();  // from
    test_pool_subscription.effective_to = &date_time::parse("2022/04/10 TIME/12:00:00");  // to
    test_pool_subscription.created_at = &date_time::now();  // created_at
    test_pool_subscription.unit_count = 4;  // unit_count
    
    add_pool_subscription(test_pool_subscription);

    // ADD TEST SUBS_HISTORY
    Subs_history test_sub_history;
    
    test_sub_history.pool_subscription_id = 31;  // pool_subscription_id
    test_sub_history.created_at = &date_time::now(); // created_at
    test_sub_history.units_used = 5;   // units_used
    
    add_subs_history(test_sub_history);
}

void test_data::thanks()
{
    std::cout << std::endl << "Thanks for using application!" << std::endl;
    std::cout << "Wish you stay healthy!" << std::endl << std::endl;
}

void test_data::run()
{
    std::cout << "Welcome to Swimming Pool Subscription App! \n\n";
    int choice = 0;
    do {
        std::cout << "Enter : \n";
        std::cout << "1  - to add location \n";
        std::cout << "2  - to add subscription \n";
        std::cout << "3  - to add pool \n";
        std::cout << "4  - to add pool subscription \n";
        std::cout << "5  - to add subscription history \n\n";
        std::cout << "6  - to show all repositories \n";
        std::cout << "7  - to show all locations \n";
        std::cout << "8  - to show all subscriptions \n";
        std::cout << "9  - to show all pools \n";
        std::cout << "10 - to show all pool subscriptions \n";
        std::cout << "11 - to show all subscription histories \n\n";
        std::cout << "12 - to enter test data \n";
        std::cout << "0  - to exit \n\n";
        
        std::cin >> choice;
        while (std::cin.fail()) // to avoid data_types and size errors
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cerr << "Invalid Input.  Enter a NUMBER: ";
            std::cin >> choice;
        }
        
        try {
            (choice == 1) ? run_location() :
            (choice == 2) ? run_subscription() :
            (choice == 3) ? run_pool() :
            (choice == 4) ? run_pool_subscription() :
            (choice == 5) ? run_subs_history() :
            (choice == 6) ? show() :
            (choice == 7) ? show_all_locations() :
            (choice == 8) ? show_all_subscriptions() :
            (choice == 9) ? show_all_pools() :
            (choice == 10) ? show_all_pool_subscriptions() :
            (choice == 11) ? show_all_subs_histories() :
            (choice == 12) ? run_test() : thanks();
        }
        catch (std::exception const& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    } while (choice != 0);
    std::cin.ignore();
}


void test_data::run_location()
{
    Location location;
    init_location(&location);
    
    if (add_confirm()) {
        add_location(location);
    }
}

void test_data::run_subscription()
{
    std::cin.ignore();
    Customer_Subscription subscription;
    init_subscription(&subscription);
    
    if (add_confirm()) {
        add_subscription(subscription);
    }
}

void test_data::run_pool()
{
    Pool pool;
    init_pool(&pool);
    
    if (add_confirm()) {
        add_pool(pool);
    }
}

void test_data::run_pool_subscription()
{
    Pool_subscription pool_sub;
    init_pool_subscription(&pool_sub);
    
    if (add_confirm()) {
        add_pool_subscription(pool_sub);
    }
}

void test_data::run_subs_history()
{
    Subs_history subs_history;
    init_subs_history(&subs_history);
    
    if (add_confirm()) {
        add_subs_history(subs_history);
    }
}

void test_data::show ()
{
    show_all_locations();
    show_all_subscriptions();
    show_all_pools();
    show_all_pool_subscriptions();
    show_all_subs_histories();
}

    // METHODS FOR SHOW FUNCTION
void test_data::show_all_locations ()
{
    // shows all LOCATIONS in the console output
    try
    {
        auto entities = uow_->get_location_repository()->get_collection();

        std::cout << std::endl << "       Locations        " << std::endl
                               << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
        for (auto const& entity : entities)
        {
            std::cout << "ID:         " << entity->id_     << std::endl;
            std::cout << "Name:       " << entity->name    << std::endl;
            std::cout << "Address:    " << entity->address << std::endl;
            std::cout << std::endl;
        }
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while showing LOCATION elements" << std::endl;
    }
}

void test_data::show_all_subscriptions ()
{
    // shows all SUBSCRIPTIONS in the console output
    try
    {
        auto entities = uow_->get_subscription_repository()->get_collection();

        std::cout << std::endl << "     Subscriptions      " << std::endl
                               << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
        for (auto const& entity : entities)
        {
            std::cout << "ID:         " << entity->id_  << std::endl;
            std::cout << "Name:       " << entity->name << std::endl;
            std::cout << "Type:       " << entity->type << std::endl;
            std::cout << "Since:      " << entity->effective_from->to_string() << std::endl;
            std::cout << "Expires:    " << entity->effective_to->to_string() << std::endl;
            std::cout << "Hours:      " << entity->hours << std::endl;
            std::cout << "Unit Title: " << entity->type << std::endl;
            std::cout << std::endl;
        }
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while showing SUBSCRIPTION elements" << std::endl << std::endl;
    }
}

void test_data::show_all_pools ()
{
    // shows all POOLS in the console output
    try
    {
        auto entities = uow_->get_pool_repository()->get_collection();

        std::cout << std::endl << "         Pools          " << std::endl
                               << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
        for (auto const& entity : entities)
        {
            std::cout << "ID:         " << entity->id_            << std::endl;
            std::cout << "Number:     " << entity->serial_number_ << std::endl;
            std::cout << "Shape:      " << entity->pshape_->shape_to_string()       << std::endl;
            std::cout << "Length:     " << std::to_string(entity->pshape_->length_) << std::endl;
            std::cout << "Width:      " << std::to_string(entity->pshape_->width_)  << std::endl;
            std::cout << "Depth:      " << std::to_string(entity->pshape_->depth_)  << std::endl;
            std::cout << "Volume:     " << std::to_string(entity->pshape_->calc_volume()) << " m^3 \n";
            std::cout << std::endl;
        }
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what() << " ->while showing POOL elements" << std::endl << std::endl;
    }
}

void test_data::show_all_pool_subscriptions ()
{
    // shows all POOL_SUBSCRIPTIONS in the console output
    try
    {
        auto entities = uow_->get_pool_subscription_repository()->get_collection();

        std::cout << std::endl << "   Pool Subscriptions   " << std::endl
                               << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
        for (auto const& entity : entities)
        {
            std::cout << "ID:         " << entity->id_                         << std::endl;
            std::cout << "Created at: " << entity->created_at->to_string()     << std::endl;
            std::cout << "Pool ID:    " << entity->pool_id                     << std::endl;
            std::cout << "Subs ID:    " << entity->sub_id                      << std::endl;
            std::cout << "Since:      " << entity->effective_from->to_string() << std::endl;
            std::cout << "Expires:    " << entity->effective_to->to_string()   << std::endl;
            std::cout << "Unit Count: " << entity->unit_count                  << std::endl;
            std::cout << std::endl;
        }
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while showing POOL_SUBSCRIPTION elements" << std::endl;
    }
}

void test_data::show_all_subs_histories ()
{
    // shows all SUBS_HISTORIES in the console output
    try
    {
        auto entities = uow_->get_subs_history_repository()->get_collection();

        std::cout << std::endl << "  Subscription History  " << std::endl
                               << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
        for (auto const& entity : entities)
        {
            std::cout << "ID:         " << entity->id_                     << std::endl;
            std::cout << "Created at: " << entity->created_at->to_string() << std::endl;
            std::cout << "Ticket ID:  " << entity->pool_subscription_id    << std::endl;
            std::cout << "Used:       " << entity->units_used              << std::endl;
            std::cout << std::endl;
        }
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while showing SUB_HISTORY elements" << std::endl;
    }
}



            // METHODS FOR INITIATING OBJECTS (FROM USER)

void test_data::init_location (Location* location)
{
    std::cout << "    LOCATION OF POOL CREATION    " << std::endl;
    std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl << std::endl;
    std::cout << "Name of Swimming Pool : ";
    std::cin.ignore();      getline(std::cin, location->name);
    std::cout << "Address of Pool : ";
    getline(std::cin, location->address);
}

void test_data::init_subscription (Customer_Subscription* subscription)
{
    try {
        std::cout << "    SUBSCRIPTION UNIT CREATION    " << std::endl;
        std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl << std::endl;
        std::cout << "Customer's name : ";
        std::cin.ignore();      getline(std::cin, subscription->name);
        std::cout << "Type of Subscription : ";
        std::cin.ignore();      getline(std::cin, subscription->type);
        std::cout << "Date the subscription activates" << std::endl;
        subscription->effective_from = &get_date();
        std::cout << "Date the subscription expires" << std::endl;
        subscription->effective_to = &get_date();
        std::cout << "Hours subscription will be valid : ";
        std::cin >> subscription->hours;
        std::cout << "Max Unit Count : ";
        std::cin >> subscription->max_unit_count;
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR (init_subscription func) : " << ex.what() << std::endl;
    }
}

void test_data::init_pool (Pool* pool)
{
    try {
        std::cout << "       POOL UNIT CREATION        " << std::endl;
        std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl << std::endl;
        std::cout << "Serial Number of Pool : ";
        std::cin.ignore();      getline(std::cin, pool->serial_number_);
        std::cout << "Shape of Pool : ";
        pool->pshape_ = get_pool_shape();
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR (init_pool func) : " << ex.what() << std::endl;
    }
}

void test_data::init_pool_subscription(Pool_subscription* pool_sub)
{
    try {
        std::cout << "   POOL SUBSCRIPTION CREATION    " << std::endl;
        std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl << std::endl;
        std::cout << "Pool ID : ";
        std::cin >> pool_sub->pool_id;
        std::cout << "Subscription ID : ";
        std::cin >> pool_sub->sub_id;
        std::cout << "Date the subscription activates" << std::endl;
        pool_sub->effective_from = &get_date();
        std::cout << "Date the pool subscription expires" << std::endl;
        pool_sub->effective_to = &get_date();
        std::cout << "Date the subscription was created" << std::endl;
        pool_sub->created_at = &get_date();
        std::cout << "Unit Count : ";
        std::cin >> pool_sub->unit_count;
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR (init_pool_subscription func) : " << ex.what() << std::endl;
    }
    
}

void test_data::init_subs_history (Subs_history* subs_history)
{
    try {
        std::cout << "  SUBSCRIPTION HISTORY CREATION  " << std::endl;
        std::cout << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl << std::endl;
        std::cout << "Pool subscription ID : ";
        std::cin >> subs_history->pool_subscription_id;
        std::cout << "Date subscription was created at : ";
        subs_history->created_at = &get_date();
        std::cout << "Times subscription was used : ";
        std::cin >> subs_history->units_used;
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR (init_pool_subscription func) : " << ex.what() << std::endl;
    }
}


         // METHODS FOR ADDING OBJECTS IN REPOSITORIES

void test_data::add_location (Location const& location) const
{
    // adds 1 LOCATION and keeps it in repository
    try {
        auto repository = uow_->get_location_repository();
        auto new_location = new Location;
        
        new_location->name = location.name;
        new_location->address = location.address;
        
        repository->add(new_location);
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while adding LOCATION element" << std::endl;
    }
}

void test_data::add_subscription (Customer_Subscription const& subscription) const
{
    // adds 1 SUBSCRIPTION and keeps it in repository
    try {
        auto repository = uow_->get_subscription_repository();
        auto new_subscription = new Customer_Subscription;
        
        new_subscription->name = subscription.name;  // name
        new_subscription->type = subscription.type;  // type
        new_subscription->effective_from = subscription.effective_from; // from
        new_subscription->effective_to   = subscription.effective_to;   // to
        new_subscription->hours = subscription.hours;    // hours
        new_subscription->max_unit_count = subscription.max_unit_count; // max_unit_count
        new_subscription->unit_title = subscription.unit_title;  // unit_title

        repository->add(new_subscription);
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while adding SUBSCRIPTION element" << std::endl;
    }
}

void test_data::add_pool (Pool const& pool) const
{
    // adds 1 POOL and keeps it in repository
    try {
        auto repository = uow_->get_pool_repository();
        auto new_pool = new Pool;
        
        new_pool->serial_number_ = pool.serial_number_; // serial number
        new_pool->pshape_ = pool.pshape_;  // Pool_Shape

        repository->add(new_pool);
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while adding POOL element" << std::endl;
    }
}

void test_data::add_pool_subscription (Pool_subscription const& pool_sub) const
{
    // adds 1 POOL_SUBSCRIPTION and keeps it in repository
    try {
        auto repository = uow_->get_pool_subscription_repository();
        auto new_pool_sub = new Pool_subscription;
        
        new_pool_sub->pool_id = pool_sub.pool_id;  // pool_id
        new_pool_sub->sub_id = pool_sub.sub_id;    // subscription_id
        new_pool_sub->effective_from = pool_sub.effective_from;  // from
        new_pool_sub->effective_to = pool_sub.effective_to;      // to
        new_pool_sub->created_at = pool_sub.created_at;    // created_at
        new_pool_sub->unit_count = pool_sub.unit_count;    // unit_count

        repository->add(new_pool_sub);
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while adding POOL_SUBSCRIPTION element" << std::endl;
    }
}

void test_data::add_subs_history (Subs_history const& subs_history) const
{
    // adds 1 SUBS_HISTORY and keeps it in repository
    try {
        auto repository = uow_->get_subs_history_repository();
        auto new_sub_history = new Subs_history;
        
        new_sub_history->pool_subscription_id = subs_history.pool_subscription_id; // pool_subscription_id
        new_sub_history->created_at = subs_history.created_at; // created_at
        new_sub_history->units_used = subs_history.units_used; // units_used
        
        repository->add(new_sub_history);
    }
    catch (std::exception const& ex) {
        std::cerr << "ERROR: " << ex.what();
        std::cerr << " ->while adding SUBS_HISTORY element" << std::endl;
    }
}

        // FUNCTIONS HELPERS
Pool_Shape* test_data::get_pool_shape ()
{
    auto pshape = new Pool_Shape;
    
    std::cout << "(1 - Rectangle, 2 - Square, 3 - Round, 4 - Undefined) : ";
    size_t shape_choice;                std::cin >> shape_choice;
    pshape->choice_to_shape(shape_choice);
    std::cout << "Length, Width, Depth of Pool (divide by space) : ";
    std::cin >> pshape->length_ >> pshape->width_ >> pshape->depth_;
    
    return pshape;
}

date_time& test_data::get_date ()
{
    std::cout << "Enter 0 - to set current time, 1 - to set it manualy : ";
    bool set_manually;              std::cin >> set_manually;
    if (!set_manually) {
        return date_time::now();
    }   else {
        std::cout << "Format of Date -> { Y/M/D TIME/H:M:S }";
        std::cout << "Enter Date here : ";
        std::string eff_to;     std::cin.ignore();     getline(std::cin, eff_to);
        return date_time::parse(eff_to);
    }
}

bool test_data::add_confirm ()
{
    std::cout << "Are you sure you want to add this object to repository?\n";
    std::cout << "1 - YES, 0 - NO" << std::endl << "Make your choice : ";
    bool confirm;        std::cin >> confirm;       std::cout << std::endl;
    return confirm;
}

