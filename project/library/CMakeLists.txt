cmake_minimum_required(VERSION 3.4)
project(ParcelLockerLib)

# source files general
set(SOURCE_FILES
        include/functions.h src/model/Order.cpp include/model/Order.h src/packages/PackageType.cpp include/packages/PackageType.h src/packages/TinyPackage.cpp include/packages/TinyPackage.h src/packages/LargePackage.cpp include/packages/LargePackage.h src/packages/SmallPackage.cpp include/packages/SmallPackage.h src/packages/HugePackage.cpp include/packages/HugePackage.h src/packages/MediumPackage.cpp include/packages/MediumPackage.h src/packages/Package.cpp include/model/Package.h include/model/Repository.h src/model/Address.cpp include/model/Address.h src/model/ParcelLocker.cpp include/model/ParcelLocker.h src/model/Client.cpp include/model/Client.h src/clientTypes/ClientType.cpp include/clientTypes/ClientType.h src/clientTypes/Default.cpp include/clientTypes/Default.h src/clientTypes/Silver.cpp include/clientTypes/Silver.h src/clientTypes/Gold.cpp include/clientTypes/Gold.h src/clientTypes/Diamond.cpp include/clientTypes/Diamond.h src/exceptions/ModelException.cpp include/exceptions/ModelException.h src/exceptions/PackageException.cpp include/exceptions/PackageException.h src/exceptions/ClientTypeException.cpp include/exceptions/ClientTypeException.h src/managers/ClientManager.cpp include/managers/ClientManager.h src/predicates/PredicateByClientId.cpp include/predicates/PredicateByClientId.h src/predicates/PredicateByPersonalName.cpp include/predicates/PredicateByPersonalName.h src/predicates/PredicateTrue.cpp include/predicates/PredicateTrue.h src/functions.cpp test/package/PackageTest.cpp src/managers/PackageManager.cpp include/managers/PackageManager.h src/predicates/PredicateByPackageId.cpp include/predicates/PredicateByPackageId.h src/predicates/PredicateByLogin.cpp include/predicates/PredicateByLogin.h src/managers/ParcelLockerManager.cpp include/managers/ParcelLockerManager.h src/predicates/PredicateByParcelLockerId.cpp include/predicates/PredicateByParcelLockerId.h src/managers/OrderManager.cpp include/managers/OrderManager.h src/predicates/PredicateByOrderId.cpp include/predicates/PredicateByOrderId.h src/managers/SaveFilesManager.cpp include/managers/SaveFilesManager.h)

# lib for tests etc
add_library(ParcelLockerLib ${SOURCE_FILES})

target_include_directories(ParcelLockerLib PUBLIC include)
enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
#find_package(nlohmann_json 3.2.0 REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

# source files for tests only
set(SOURCE_TEST_FILES
        test/Master.cpp
        test/model/OrderTest.cpp test/model/ParcelLockerTest.cpp test/model/ClientTest.cpp test/model/AddressTest.cpp test/managers/ClientManagerTest.cpp test/package/PackageTest.cpp test/managers/PackageManagerTest.cpp test/managers/OrderManagerTest.cpp test/managers/ParcelLockerManagerTest.cpp)

add_executable (ParcelLockerLibTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
#target_link_libraries(jsonParser PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries (ParcelLockerLibTest
        ParcelLockerLib
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(ParcelLockerLibTests ParcelLockerLibTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )


add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})