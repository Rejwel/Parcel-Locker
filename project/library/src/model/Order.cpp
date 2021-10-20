#include "model/Order.h"
#include "model/Client.h"
#include "model/Package.h"
#include "model/ParcelLocker.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "exceptions/ModelException.h"
#include "math.h"

Order::~Order() {

}

Order::Order(const boost::uuids::uuid &id, const std::string &clientDesc, ClientPtr client,
             PackagePtr package, ParcelLockerPtr parcelLocker) : id(id), clientDesc(clientDesc),
                                                                                client(client), package(package),
                                                                                parcelLocker(parcelLocker) {
    orderState = segment::order_placed;
    beginTime = boost::posix_time::second_clock::local_time();
    endTime = boost::posix_time::not_a_date_time;
    orderCost = package->getPackagePrice() - client->applyDiscount(package->getPackagePrice());
}



std::string Order::getInfo() const {
    std::stringstream ss1;
    std::stringstream ss2;
    ss1 << beginTime;
    ss2 << endTime;
    if(ss2.str() == "not-a-date-time")
    {
        ss2.str("");
        ss2 << "Not delivered yet";
    }
    return "Order placed at: " + ss1.str() + "\nOrder delivered at: " + ss2.str() + "\nCost of order: " + std::to_string((int)(orderCost)) +
           "\nYour package: " + package->getInfo() + "\nYour description: " + clientDesc + "\nYour Parcel locker: " + parcelLocker->getInfo();
}

void Order::updateOrder(Order::segment state) {
    if(state == Order::segment::at_location) {
        Order::orderState = state;
        endTime = boost::posix_time::second_clock::local_time();
    }
    Order::orderState = state;
}

const boost::uuids::uuid &Order::getId() const {
    return id;
}

const boost::posix_time::ptime &Order::getBeginTime() const {
    return beginTime;
}

double Order::getOrderCost() const {
    return package->getPackagePrice() - client->applyDiscount(package->getPackagePrice());
}

const std::string &Order::getClientDesc() const {
    return clientDesc;
}

Order::segment Order::getOrderState() const {
    return orderState;
}

const boost::posix_time::ptime &Order::getEndTime() const {
    return endTime;
}

const ClientPtr &Order::getClient() const {
    return client;
}

const PackagePtr &Order::getAPackage() const {
    return package;
}

const ParcelLockerPtr &Order::getParcelLocker() const {
    return parcelLocker;
}

void Order::setParcelLocker(const ParcelLockerPtr &locker) { // implement exceptions in manager
    if(orderState < 3) Order::parcelLocker = locker;
}

