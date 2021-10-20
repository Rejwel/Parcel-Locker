#include <boost/test/unit_test.hpp>
#include "managers/OrderManager.h"
#include "exceptions/ModelException.h"
#include <predicates/PredicateByOrderId.h>
#include "model/Order.h"
#include "model/Client.h"
#include "clientTypes/Silver.h"
#include "clientTypes/Gold.h"
#include "clientTypes/Diamond.h"
#include "clientTypes/ClientType.h"
#include "clientTypes/Default.h"
#include "functions.h"
#include "model/Address.h"
#include "model/ParcelLocker.h"
#include "model/Package.h"
#include "packages/LargePackage.h"


struct TestSuiteOrderManagerFixture {
    OrderManagerPtr orderManager;
    ClientTypePtr clientType1;
    ClientTypePtr clientType2;
    OrderPtr order;
    ClientPtr client;
    boost::uuids::uuid packageUUID1;
    boost::uuids::uuid packageUUID2;
    boost::uuids::uuid OrderUUID1;
    boost::uuids::uuid OrderUUID2;
    ParcelLockerPtr parcelLocker1;
    ParcelLockerPtr parcelLocker2;
    AddressPtr address;
    PackagePtr package1;
    PackagePtr package2;
    PackageTypePtr typPaczki1;


    TestSuiteOrderManagerFixture() {
        typPaczki1 = std::make_shared<LargePackage>();
        packageUUID1 = generateUUID();
        packageUUID2 = generateUUID();
        package1 = std::make_shared<Package>(packageUUID1,100,1,true,true,typPaczki1);
        package2 = std::make_shared<Package>(packageUUID2,100,1,true,true,typPaczki1);
        address = std::make_shared<Address>("Sydney","Phillip St","50");
        parcelLocker1 = std::make_shared<ParcelLocker>(address, "1", 25);
        parcelLocker2 = std::make_shared<ParcelLocker>(address, "3", 253);
        OrderUUID1 = generateUUID();
        OrderUUID2 = generateUUID();
        clientType1 = std::make_shared<Silver>();
        clientType2 = std::make_shared<Default>();
        orderManager = std::make_shared<OrderManager>();
        client = std::make_shared<Client>("login", "password", "Adam", "Nowak", "0022002200", clientType2);
        order = std::make_shared<Order>(OrderUUID1, "Prosze zostawic przed drzwiami", client, package1, parcelLocker1);
    }

    ~TestSuiteOrderManagerFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteOrderManager,TestSuiteOrderManagerFixture)

BOOST_AUTO_TEST_CASE(OrderManagerConstructorTest) {
        BOOST_TEST_REQUIRE(orderManager->getSize() == 0);
}

    BOOST_AUTO_TEST_CASE(OrderManagerGetSizeTest) {
        BOOST_TEST_REQUIRE(orderManager->getSize() == 0);
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        orderManager->makeOrder(OrderUUID2,client,package2,parcelLocker1,"Fajne info");
        BOOST_TEST_REQUIRE(orderManager->getSize() == 2);

    }

    BOOST_AUTO_TEST_CASE(OrderManagerRegisterTest) {
        BOOST_TEST_REQUIRE(orderManager->getSize() == 0);
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        BOOST_TEST_REQUIRE(orderManager->getSize() == 1);
    }

    BOOST_AUTO_TEST_CASE(NegativeOrderManagerRegisterTest) {
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        BOOST_TEST_REQUIRE(orderManager->getSize() == 1);
        BOOST_REQUIRE_THROW(orderManager->makeOrder(OrderUUID2,nullptr,package1,parcelLocker1,"Fajne info"), ModelException::exception);
        BOOST_TEST_REQUIRE(orderManager->getSize() == 1);
        BOOST_REQUIRE_THROW(orderManager->makeOrder(OrderUUID2,client,nullptr,parcelLocker1,"Fajne info"), ModelException::exception);
        BOOST_TEST_REQUIRE(orderManager->getSize() == 1);
        BOOST_REQUIRE_THROW(orderManager->makeOrder(OrderUUID2,client,package1,nullptr,"Fajne info"), ModelException::exception);
        BOOST_TEST_REQUIRE(orderManager->getSize() == 1);
    }

    BOOST_AUTO_TEST_CASE(OrderManagerCheckCLientBalanceTest) {
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        BOOST_TEST_REQUIRE(orderManager->getSize() == 1);
        BOOST_TEST_REQUIRE(orderManager->checkClientOrderBalance(client) == 20);
    }

    BOOST_AUTO_TEST_CASE(OrderManagerSettingClientTypeTest) {
        BOOST_TEST_REQUIRE(orderManager->getSize() == 0);
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        orderManager->makeOrder(OrderUUID2,client,package2,parcelLocker1,"Hello");
        BOOST_TEST_REQUIRE(orderManager->checkClientOrderBalance(client) == 40);
        BOOST_TEST_REQUIRE(client->getClientType()->getTypeInfo() == "Default Client Type");
        orderManager->changeClientType(client);

        BOOST_TEST_REQUIRE(client->getClientType()->getTypeInfo() == "Silver Client Type");
    }

    BOOST_AUTO_TEST_CASE(OrderManagerFindOrderTest) {
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        orderManager->makeOrder(OrderUUID2,client,package2,parcelLocker1,"Fajne info");
        PredicateByOrderId functor(boost::uuids::to_string(OrderUUID1));
        BOOST_TEST_REQUIRE(orderManager->findOrders(functor).size() == 1);
        BOOST_TEST_REQUIRE(orderManager->findAllOrders().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(OrderManagerChangingParcelLockerTest) {
        orderManager->makeOrder(OrderUUID1,client,package1,parcelLocker1,"Fajne info");
        PredicateByOrderId functor(boost::uuids::to_string(OrderUUID1));
        orderManager->changeOrderParcelLocker(parcelLocker2,orderManager->findOrders(functor)[0]);

        BOOST_TEST_REQUIRE(orderManager->findOrders(functor)[0]->getParcelLocker() == parcelLocker2);
    }


BOOST_AUTO_TEST_SUITE_END()