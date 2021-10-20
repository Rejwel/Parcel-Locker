#include <packages/LargePackage.h>
#include "exceptions/PackageException.h"
#include "managers/PackageManager.h"
#include "model/Package.h"
#include "packages/PackageType.h"
#include "typedefs.h"
#include <boost/test/unit_test.hpp>
#include "functions.h"
#include "predicates/PredicateByPackageId.h"

struct TestSuitePackageManagerFixture {
    PackageManagerPtr packageManager;
    PackageTypePtr packageType;
    PackagePtr package;
    boost::uuids::uuid packageUUID1;
    boost::uuids::uuid packageUUID2;

    TestSuitePackageManagerFixture() {
        packageUUID1 = generateUUID();
        packageUUID2 = generateUUID();
        packageManager = std::make_shared<PackageManager>();
        packageType = std::make_shared<LargePackage>();
        package = std::make_shared<Package>(packageUUID1,20,2,true,false,packageType);
    }

    ~TestSuitePackageManagerFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuitePackageManager,TestSuitePackageManagerFixture)

    BOOST_AUTO_TEST_CASE(PackageManagerConstructorTest) {
            BOOST_TEST_REQUIRE(packageManager->getSize() == 0);
    }

    BOOST_AUTO_TEST_CASE(PackageManagerAddPackageTest) {
        packageManager->registerPackage(packageUUID1,20,2,true,true,packageType);
        BOOST_TEST_REQUIRE(packageManager->getSize() == 1);
        packageManager->registerPackage(packageUUID2,20,2,true,true,packageType);
        BOOST_TEST_REQUIRE(packageManager->getSize() == 2);
    }

    BOOST_AUTO_TEST_CASE(NegativePackageManagerAddPackageTest){
        packageManager->registerPackage(packageUUID1,20,2,true,true,packageType);

        BOOST_REQUIRE_THROW(packageManager->registerPackage(packageUUID1,20,2,true,true,packageType), PackageException::exception);
        BOOST_TEST_REQUIRE(packageManager->getSize() == 1);

        BOOST_REQUIRE_THROW(packageManager->registerPackage(packageUUID2,-20,2,true,true,packageType), PackageException::exception);
        BOOST_TEST_REQUIRE(packageManager->getSize() == 1);

        BOOST_REQUIRE_THROW(packageManager->registerPackage(packageUUID2,20,6,true,true,packageType), PackageException::exception);
        BOOST_TEST_REQUIRE(packageManager->getSize() == 1);

        BOOST_REQUIRE_THROW(packageManager->registerPackage(packageUUID2,20,2,true,true,nullptr), PackageException::exception);
        BOOST_TEST_REQUIRE(packageManager->getSize() == 1);
}

    BOOST_AUTO_TEST_CASE(PackageManagerPaidTest) {
        packageManager->registerPackage(packageUUID1,20,2,true,false,packageType);
        BOOST_TEST_REQUIRE(packageManager->getPackage(packageUUID1)[0]->isPaid() == false);
        packageManager->payForPackage(packageManager->getPackage(packageUUID1)[0]);
        BOOST_TEST_REQUIRE(packageManager->getPackage(packageUUID1)[0]->isPaid() == true);
    }

    BOOST_AUTO_TEST_CASE(PackageManagerGetPackageTest) {
        packageManager->registerPackage(packageUUID1,20,2,true,false,packageType);
        BOOST_TEST_REQUIRE(packageManager->getPackage(packageUUID1).size() == 1);
        PredicateByPackageId functor(boost::uuids::to_string(packageUUID1));
        BOOST_TEST_REQUIRE(packageManager->findPackage(functor).size() == 1);

    }

    BOOST_AUTO_TEST_CASE(PackageManagerGetSizeTest) {
        BOOST_TEST_REQUIRE(packageManager->getSize() == 0);
        packageManager->registerPackage(packageUUID1,20,2,true,false,packageType);;
        BOOST_TEST_REQUIRE(packageManager->getSize() == 1);
    }


BOOST_AUTO_TEST_SUITE_END()

