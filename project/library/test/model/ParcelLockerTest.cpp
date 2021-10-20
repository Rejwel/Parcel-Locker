#include <boost/test/unit_test.hpp>
#include <model/ParcelLocker.h>
#include "typedefs.h"
#include "model/Address.h"
#include "model/Package.h"
#include "exceptions/ModelException.h"

struct TestSuiteParcelLockerFixture {

    ParcelLockerPtr parcelLocker;
    ParcelLockerPtr parcelLocker2;
    AddressPtr address;


    TestSuiteParcelLockerFixture() {
        address = std::make_shared<Address>("Sydney","Phillip St","50");
        parcelLocker = std::make_shared<ParcelLocker>(address, "1", 25);
        parcelLocker2 = std::make_shared<ParcelLocker>(nullptr, "2", 0);
    }

    ~TestSuiteParcelLockerFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteParcelLocker, TestSuiteParcelLockerFixture)

    BOOST_AUTO_TEST_CASE(ParcelLockerConstructorTest) {
        BOOST_TEST_REQUIRE(parcelLocker->getAddress() == address);
        BOOST_TEST_REQUIRE(parcelLocker->getLockerId() == "1");
        BOOST_TEST_REQUIRE(parcelLocker->getFreePlaces() == 25);
    }
    BOOST_AUTO_TEST_CASE(ParcelLockerPlacesTest) {
        BOOST_TEST_REQUIRE(parcelLocker->areAvailablePlaces() == true);
        BOOST_TEST_REQUIRE(parcelLocker2->areAvailablePlaces() == false);
    }

    BOOST_AUTO_TEST_CASE(ParcelLockerPackPackageTest) {
        BOOST_TEST_REQUIRE(parcelLocker->getFreePlaces() == 25);
        BOOST_TEST_REQUIRE(parcelLocker->areAvailablePlaces() == true);
        parcelLocker->packPackage();
        BOOST_TEST_REQUIRE(parcelLocker->getFreePlaces() == 24);
        parcelLocker->setFreePlaces(0);
        BOOST_TEST_REQUIRE(parcelLocker->getFreePlaces() == 0);
        BOOST_REQUIRE_THROW(parcelLocker->packPackage(), ModelException::exception);
    }

    BOOST_AUTO_TEST_CASE(ParcelLockersetArchiveTest) {
        BOOST_TEST_REQUIRE(parcelLocker->isArchive() == false);
        parcelLocker->setArchive(true);
        BOOST_TEST_REQUIRE(parcelLocker->isArchive() == true);
    }


BOOST_AUTO_TEST_SUITE_END()