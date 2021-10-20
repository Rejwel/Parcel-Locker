#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <model/ParcelLocker.h>
#include "typedefs.h"
#include "functions.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Package.h"
#include "model/ParcelLocker.h"
#include "model/Order.h"
#include "packages/PackageType.h"
#include "clientTypes/ClientType.h"
#include "clientTypes/Default.h"
#include "packages/SmallPackage.h"
#include "exceptions/ModelException.h"
#include "exceptions/ClientTypeException.h"
#include "exceptions/PackageException.h"

struct TestSuiteOrderFixture {

    OrderPtr order;
    OrderPtr orderNegative;
    ParcelLockerPtr parcelLocker;
    ParcelLockerPtr parcelLocker2;
    PackagePtr package;
    ClientPtr client;
    AddressPtr address;
    AddressPtr address2;
    PackageTypePtr packageType;
    ClientTypePtr clientType;

    boost::uuids::uuid packageUUID;
    boost::uuids::uuid orderUUID;


    TestSuiteOrderFixture() {
        packageUUID = generateUUID();
        orderUUID = generateUUID();

        address = std::make_shared<Address>("Sydney","Phillip St","50");
        address2 = std::make_shared<Address>("NYC","Amazon Street","11");
        packageType = std::make_shared<SmallPackage>();
        clientType = std::make_shared<Default>();

        parcelLocker = std::make_shared<ParcelLocker>(address, "1", 25);
        parcelLocker2 = std::make_shared<ParcelLocker>(address2, "2", 50);
        package = std::make_shared<Package>(packageUUID, 5, 5, true, false, packageType);
        client = std::make_shared<Client>("login", "password", "Adam", "Nowak", "0022002200", clientType);
        order = std::make_shared<Order>(orderUUID, "Prosze zostawic przed drzwiami", client, package, parcelLocker);
    }

    ~TestSuiteOrderFixture() {   }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteOrder, TestSuiteOrderFixture)

    BOOST_AUTO_TEST_CASE(OrderConstructorTest) {
        BOOST_TEST_REQUIRE(order->getId() == orderUUID);
        BOOST_TEST_CHECK(order->getClientDesc().empty() == false);
        BOOST_TEST_REQUIRE(order->getClient() == client);
        BOOST_TEST_REQUIRE(order->getAPackage() == package);
        BOOST_TEST_REQUIRE(order->getParcelLocker() == parcelLocker);
        BOOST_TEST_REQUIRE(order->getOrderState() == Order::segment::order_placed);
        BOOST_TEST_REQUIRE(order->getBeginTime() == boost::posix_time::second_clock::local_time());
        BOOST_TEST_REQUIRE(order->getEndTime() == boost::posix_time::not_a_date_time);
    }

    BOOST_AUTO_TEST_CASE(OrderParcelLockerSetTest) {
        BOOST_TEST_REQUIRE(order->getParcelLocker() == parcelLocker);
        order->setParcelLocker(parcelLocker2);
        BOOST_TEST_REQUIRE(order->getParcelLocker() == parcelLocker2);
    }

    BOOST_AUTO_TEST_CASE(OrderParcelLockerNegativeSetTest) {
        order->updateOrder(Order::segment::on_the_way);
        BOOST_TEST_REQUIRE(order->getParcelLocker() == parcelLocker);
        order->setParcelLocker(parcelLocker2);
        BOOST_TEST_REQUIRE(order->getParcelLocker() == parcelLocker);
    }


BOOST_AUTO_TEST_SUITE_END()