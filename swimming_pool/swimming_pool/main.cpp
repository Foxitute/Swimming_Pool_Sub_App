#include <iostream>

#include "app_setting_manager.h"
#include "app_settings_initializer.h"
#include "Pool_repository.h"
#include "File_repository_uow.h"
#include "Repository_uow.h"
#include "Pool_serializer.h"
#include "test_data.h"


void init_test_data()
{
    // create an instance of Repository Unit_Of_Work
    Repository_uow* repositories = new File_repository_uow;

    // Create an instance of test_data class.
    // The test_data class takes the instance of repository_uow in constructor.
    test_data test(repositories);

    // Populate default values if no data
    test.run();
}

int main()
{
    // CHECK APP SETTINGS
    // add default values for required app settings if they are missed
    app_settings_initializer app_settings_initializer;
    app_settings_initializer.check_and_init_settings();

    // For testing purposes.
    // The method sets default values for all existing collections
    init_test_data();
}

