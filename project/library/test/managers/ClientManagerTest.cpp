#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <model/ParcelLocker.h>
#include "typedefs.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Package.h"
#include "model/ParcelLocker.h"
#include "model/Order.h"
#include "packages/PackageType.h"
#include "clientTypes/ClientType.h"
#include "clientTypes/Diamond.h"
#include "packages/SmallPackage.h"
#include "exceptions/ModelException.h"
#include "exceptions/ClientTypeException.h"
#include "exceptions/PackageException.h"
#include "managers/ClientManager.h"
#include "predicates/PredicateByClientId.h"

struct TestSuiteClientManagerFixture {
    ClientManagerPtr clientManager;
    ClientTypePtr clientType;

    TestSuiteClientManagerFixture() {
        clientManager = std::make_shared<ClientManager>();
        clientType = std::make_shared<Diamond>();
    }

    ~TestSuiteClientManagerFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ClientManagerConstructorTest) {
        BOOST_TEST_REQUIRE(clientManager->getSize() == 0);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerAddClientTest) {
        clientManager->registerClient("login", "password", "Filip","Grzelak","123",clientType);
        BOOST_REQUIRE_THROW(clientManager->registerClient("login", "password", "","Grzelak","123",clientType), ClientTypeException::exception);
        BOOST_TEST_REQUIRE(clientManager->getSize() == 1);
    }

    BOOST_AUTO_TEST_CASE(NegativeClientManagerAddClientTest) {
        clientManager->registerClient("login", "password", "Filip","Grzelak","123",clientType);
        BOOST_TEST_REQUIRE(clientManager->getSize() == 1);
        BOOST_REQUIRE_THROW(clientManager->registerClient("login1", "login1", "Paweł","Dera","321",clientType), ClientTypeException::exception);
        BOOST_REQUIRE_THROW(clientManager->registerClient("login2", "password", "","Dera","321",clientType), ClientTypeException::exception);
        BOOST_REQUIRE_THROW(clientManager->registerClient("login3", "password", "Paweł","","321",clientType), ClientTypeException::exception);
        BOOST_REQUIRE_THROW(clientManager->registerClient("login4", "password", "Paweł","Dera","",clientType), ClientTypeException::exception);
        BOOST_TEST_REQUIRE(clientManager->getSize() == 1);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerGetClientTest) {
        clientManager->registerClient("login", "password", "Filip","Grzelak","123",clientType);
        BOOST_TEST_REQUIRE(clientManager->getClient("123").size() == 1);

    }

    BOOST_AUTO_TEST_CASE(ClientManagerFindClientTest) {
        clientManager->registerClient("login", "password", "Filip","Grzelak","123",clientType);
        clientManager->registerClient("login2", "password", "Filip","Grzelak","1234",clientType);

        PrediaceByClientId functor("123");
        BOOST_TEST_REQUIRE(clientManager->findClients(functor).size() == 1);
        BOOST_TEST_REQUIRE(clientManager->findAllClients().size() == 2);

    }

    BOOST_AUTO_TEST_CASE(ClientManagerGetSizeTest) {
        clientManager->registerClient("login1", "password", "Filip","Grzelak","123",clientType);
        clientManager->registerClient("login2", "password", "Filip","Grzelak","1234",clientType);
        clientManager->registerClient("login3", "password", "Filip","Grzelak","1235",clientType);
        BOOST_TEST_REQUIRE(clientManager->getSize() == 3);

    }

    BOOST_AUTO_TEST_CASE(ClientManagerUnregisterTest) {
        clientManager->registerClient("login1", "password", "Filip","Grzelak","123",clientType);
        BOOST_TEST_REQUIRE(clientManager->getClient("123")[0]->isArchive() == false);
        clientManager->unregisterClient(clientManager->getClient("123")[0]);
        BOOST_TEST_REQUIRE(clientManager->getClient("123")[0]->isArchive() == true );

    }


BOOST_AUTO_TEST_SUITE_END()