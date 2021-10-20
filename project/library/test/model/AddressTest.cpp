#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Address.h"
#include "model/Package.h"


struct TestSuiteAddressFixture {
    AddressPtr address;

    TestSuiteAddressFixture() {
        address = std::make_shared<Address>("Sydney","Phillip St","50");
    }

    ~TestSuiteAddressFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest) {
        BOOST_TEST_REQUIRE(address->getCity().empty() == false);
        BOOST_TEST_REQUIRE(address->getStreet().empty() == false);
        BOOST_TEST_REQUIRE(address->getNumber().empty() == false);
    }

    BOOST_AUTO_TEST_CASE(AddressSetTest) {
        address->setCity("a");
        address->setStreet("b");
        address->setNumber("c");
        BOOST_TEST_REQUIRE(address->getCity() == "a");
        BOOST_TEST_REQUIRE(address->getStreet() == "b");
        BOOST_TEST_REQUIRE(address->getNumber() == "c");
    }

BOOST_AUTO_TEST_SUITE_END()