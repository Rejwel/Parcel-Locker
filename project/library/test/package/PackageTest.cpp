#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Package.h"
#include "packages/PackageType.h"
#include "packages/LargePackage.h"
#include "packages/SmallPackage.h"
#include "packages/TinyPackage.h"
#include "packages/MediumPackage.h"
#include "packages/HugePackage.h"
#include "functions.h"

struct TestSuitePackageFixture {
    boost::uuids::uuid packageUUID1;
    boost::uuids::uuid packageUUID2;
    boost::uuids::uuid packageUUID3;
    boost::uuids::uuid packageUUID4;
    boost::uuids::uuid packageUUID5;
    PackageTypePtr typPaczki1;
    PackageTypePtr typPaczki2;
    PackageTypePtr typPaczki3;
    PackageTypePtr typPaczki4;
    PackageTypePtr typPaczki5;
    PackagePtr package1;
    PackagePtr package2;
    PackagePtr package3;
    PackagePtr package4;
    PackagePtr package5;

    TestSuitePackageFixture() {
        packageUUID1 = generateUUID();
        packageUUID1 = generateUUID();
        packageUUID1 = generateUUID();
        packageUUID1 = generateUUID();
        packageUUID1 = generateUUID();

        typPaczki1 = std::make_shared<LargePackage>();
        typPaczki2 = std::make_shared<HugePackage>();
        typPaczki3 = std::make_shared<SmallPackage>();
        typPaczki4 = std::make_shared<TinyPackage>();
        typPaczki5 = std::make_shared<MediumPackage>();
        package1 = std::make_shared<Package>(packageUUID1,100,1,true,true,typPaczki1);
        package2 = std::make_shared<Package>(packageUUID2,200,1,false,false,typPaczki2);
        package3 = std::make_shared<Package>(packageUUID3,300,1,true,true,typPaczki3);
        package4 = std::make_shared<Package>(packageUUID4,400,1,true,true,typPaczki4);
        package5 = std::make_shared<Package>(packageUUID5,500,1,true,true,typPaczki5);
    }

    ~TestSuitePackageFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuitePackage, TestSuitePackageFixture)

    BOOST_AUTO_TEST_CASE(PackageTypeConstructorTest) {
        BOOST_TEST_REQUIRE(typPaczki1->getPackagePrice() == 20);
        BOOST_TEST_REQUIRE(typPaczki2->getPackagePrice() == 30);
        BOOST_TEST_REQUIRE(typPaczki3->getPackagePrice() == 10);
        BOOST_TEST_REQUIRE(typPaczki4->getPackagePrice() == 5);
        BOOST_TEST_REQUIRE(typPaczki5->getPackagePrice() == 15);
        BOOST_TEST_REQUIRE(typPaczki1->getPackageInfo() == "Large Package, price: 20");
        BOOST_TEST_REQUIRE(typPaczki2->getPackageInfo() == "Huge Package, price: 30");
        BOOST_TEST_REQUIRE(typPaczki3->getPackageInfo() == "Small Package, price: 10");
        BOOST_TEST_REQUIRE(typPaczki4->getPackageInfo() == "Tiny Package, price: 5");
        BOOST_TEST_REQUIRE(typPaczki5->getPackageInfo() == "Medium Package, price: 15");
    }

    BOOST_AUTO_TEST_CASE(PackageConstructorTest) {
        BOOST_TEST_REQUIRE(package1->getWeight() == 100);
        BOOST_TEST_REQUIRE(package1->getId() == packageUUID1);
        BOOST_TEST_REQUIRE(package1->getPriority() == 1);
        BOOST_TEST_REQUIRE(package1->isFragile() == true);
        BOOST_TEST_REQUIRE(package2->isFragile() == false);
        BOOST_TEST_REQUIRE(package1->isPaid() == true);
        BOOST_TEST_REQUIRE(package2->isPaid() == false);
        BOOST_TEST_REQUIRE(package1->getPackageType() == typPaczki1);


    }

BOOST_AUTO_TEST_SUITE_END()
