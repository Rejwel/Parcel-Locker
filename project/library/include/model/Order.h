#ifndef PARCELLOCKERPROJECT_ORDER_H
#define PARCELLOCKERPROJECT_ORDER_H

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time.hpp>
#include "typedefs.h"

class Order {
public:
    enum segment {order_placed = 0, during_packing = 1, waiting_for_courier = 2, on_the_way = 3, at_location = 4};
    Order(const boost::uuids::uuid &id, const std::string &clientDesc, ClientPtr client,
          PackagePtr package, ParcelLockerPtr parcelLocker);
    virtual ~Order();
    std::string getInfo() const;
    void updateOrder(segment state);
    const boost::uuids::uuid &getId() const;
    const boost::posix_time::ptime &getBeginTime() const;


    double getOrderCost() const;
    const std::string &getClientDesc() const;       // desc can be size of 0-100
    segment getOrderState() const;
    const boost::posix_time::ptime &getEndTime() const;
    const ClientPtr &getClient() const;
    const PackagePtr &getAPackage() const;
    const ParcelLockerPtr &getParcelLocker() const;
    void setParcelLocker(const ParcelLockerPtr &parcelLocker);

private:
    boost::uuids::uuid id;
    boost::posix_time::ptime beginTime;
    boost::posix_time::ptime endTime;
    double orderCost;
    const std::string clientDesc;
    segment orderState;
    ClientPtr client;
    PackagePtr package;
    ParcelLockerPtr parcelLocker;
};


#endif //PARCELLOCKERPROJECT_ORDER_H
