#ifndef PARCELLOCKERPROJECT_ORDERMANAGER_H
#define PARCELLOCKERPROJECT_ORDERMANAGER_H

#include <vector>
#include "typedefs.h"
#include "model/Repository.h"
#include <boost/uuid/uuid.hpp>
#include "model/Order.h"

class OrderManager {
public:
    OrderManager();
    virtual ~OrderManager();

    OrderPtr makeOrder(boost::uuids::uuid id, const ClientPtr &client, const PackagePtr &package, const ParcelLockerPtr &parcelLocker, std::string desc);
    void updateOrder(OrderPtr order, Order::segment orderState);
    void changeOrderParcelLocker(ParcelLockerPtr parcelLock,OrderPtr order);
    std::vector<OrderPtr> getAllClientOrders(ClientPtr client);
    std::vector<OrderPtr> getClientOrder(std::string orderId);
    double checkClientOrderBalance(ClientPtr client);
    void changeClientType(ClientPtr client);
    std::vector<OrderPtr> findOrders(OrderPredicate predicate);
    std::vector<OrderPtr> findAllOrders();
    int getSize();

private:
    Repository<Order> currentOrders;
    Repository<Order> archiveOrders;
};


#endif //PARCELLOCKERPROJECT_ORDERMANAGER_H
