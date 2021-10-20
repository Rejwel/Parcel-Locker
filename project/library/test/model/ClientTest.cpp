#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Package.h"
#include "clientTypes/Default.h"
#include "clientTypes/Diamond.h"
#include "functions.h"

struct TestSuiteClientFixture {

    ClientPtr client;
    ClientTypePtr clientType;


    TestSuiteClientFixture() {
        clientType = std::make_shared<Default>();
        client = std::make_shared<Client>("login", "password", "Adam", "Nowak", "0022002200", clientType);
    }

    ~TestSuiteClientFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        BOOST_TEST_REQUIRE(client->getFirstName().empty() == false);
        BOOST_TEST_REQUIRE(client->getLastName().empty() == false);
        BOOST_TEST_REQUIRE(client->getPersonalId().empty() == false);
        BOOST_TEST_REQUIRE(client->getLogin().empty() == false);
        BOOST_TEST_REQUIRE(client->getPassword().empty() == false);
        BOOST_TEST_REQUIRE(client->getClientType() == clientType);
        BOOST_TEST_REQUIRE(client->isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(ClientArchiveTest) {
        BOOST_TEST_REQUIRE(client->isArchive() == false);
        client->setArchive(true);
        BOOST_TEST_REQUIRE(client->isArchive() == true);
    }

BOOST_AUTO_TEST_SUITE_END()