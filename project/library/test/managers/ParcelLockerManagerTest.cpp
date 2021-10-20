#include <boost/test/unit_test.hpp>
#include "managers/OrderManager.h"
#include "managers/ParcelLockerManager.h"
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
#include "predicates/PredicateByParcelLockerId.h"


struct TestSuiteParcelLockerManagerFixture {
    OrderManagerPtr orderManager;
    ParcelLockerManagerPtr parcelLockerManager;
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
    AddressPtr address1;
    PackagePtr package1;
    PackagePtr package2;
    PackageTypePtr typPaczki1;


    TestSuiteParcelLockerManagerFixture() {
        typPaczki1 = std::make_shared<LargePackage>();
        package1 = std::make_shared<Package>(packageUUID1,100,1,true,true,typPaczki1);
        package2 = std::make_shared<Package>(packageUUID2,100,1,true,true,typPaczki1);
        address1 = std::make_shared<Address>("Sydney","Phillip St","50");
        parcelLocker1 = std::make_shared<ParcelLocker>(address1, "1", 25);
        parcelLocker2 = std::make_shared<ParcelLocker>(address1, "3", 253);
        packageUUID1 = generateUUID();
        packageUUID2 = generateUUID();
        OrderUUID1 = generateUUID();
        OrderUUID2 = generateUUID();
        clientType1 = std::make_shared<Silver>();
        clientType2 = std::make_shared<Default>();
        orderManager = std::make_shared<OrderManager>();
        parcelLockerManager = std::make_shared<ParcelLockerManager>();

        client = std::make_shared<Client>("login", "password", "Adam", "Nowak", "0022002200", clientType2);
    }

    ~TestSuiteParcelLockerManagerFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteParcelLockerManager,TestSuiteParcelLockerManagerFixture)

    BOOST_AUTO_TEST_CASE(ParcelLockerManagerConstructorTest){
        BOOST_TEST_REQUIRE(parcelLockerManager->getSize() == 0);
        parcelLockerManager->registerParcelLocker("1",2,address1);
        BOOST_TEST_REQUIRE(parcelLockerManager->getSize() == 1);
    }

    BOOST_AUTO_TEST_CASE(ParcelLockerManagerUnregisterParcelLockerTest){

        BOOST_TEST_REQUIRE( parcelLocker1->isArchive() == false);
        parcelLockerManager->unregisterParcelLocker(parcelLocker1);
        BOOST_TEST_REQUIRE( parcelLocker1->isArchive() == true);

    }

    BOOST_AUTO_TEST_CASE(NegativeParcelLockerManagerRegisterTest){
        parcelLockerManager->registerParcelLocker("1",2,address1);
        BOOST_REQUIRE_THROW(parcelLockerManager->registerParcelLocker("1",2,address1), ModelException::exception);
        BOOST_TEST_REQUIRE(parcelLockerManager->getSize() == 1);
        BOOST_REQUIRE_THROW(parcelLockerManager->registerParcelLocker("",2,address1), ModelException::exception);
        BOOST_TEST_REQUIRE(parcelLockerManager->getSize() == 1);
        BOOST_REQUIRE_THROW(parcelLockerManager->registerParcelLocker("1",-2,address1), ModelException::exception);
        BOOST_TEST_REQUIRE(parcelLockerManager->getSize() == 1);
        BOOST_REQUIRE_THROW(parcelLockerManager->registerParcelLocker("1",2,nullptr), ModelException::exception);
        BOOST_TEST_REQUIRE(parcelLockerManager->getSize() == 1);

    }

    BOOST_AUTO_TEST_CASE(NegativeParcelLockerManagerAdressTest){
        parcelLockerManager->createNewAddress("Lodz","Michala","666");
        BOOST_REQUIRE_THROW(parcelLockerManager->createNewAddress("","Michala","666"), ModelException::exception);

        BOOST_REQUIRE_THROW(parcelLockerManager->createNewAddress("Poznan","","333"), ModelException::exception);

        BOOST_REQUIRE_THROW(parcelLockerManager->createNewAddress("Poznan","Aniola",""), ModelException::exception);

    }

    BOOST_AUTO_TEST_CASE(ParcelLockerManagerFindParcelLockerTest) {
        parcelLockerManager->registerParcelLocker("1",2,address1);
        parcelLockerManager->registerParcelLocker("2",3,address1);
        PredicateByParcelLockerId functor("1");
        BOOST_TEST_REQUIRE(parcelLockerManager->findParcelLockers(functor).size() == 1);
        BOOST_TEST_REQUIRE(parcelLockerManager->findAllParcelLockers().size() == 2);

    }


BOOST_AUTO_TEST_SUITE_END()