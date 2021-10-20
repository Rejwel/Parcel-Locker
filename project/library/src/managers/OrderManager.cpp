#include "managers/OrderManager.h"
#include "exceptions/ModelException.h"
#include <predicates/PredicateByOrderId.h>
#include "model/Order.h"
#include "model/Client.h"
#include "clientTypes/Silver.h"
#include "clientTypes/Gold.h"
#include "clientTypes/Diamond.h"
#include "clientTypes/Default.h"
#include "clientTypes/ClientType.h"


OrderPtr OrderManager::makeOrder(boost::uuids::uuid id, const ClientPtr &client, const PackagePtr &package, const ParcelLockerPtr &parcelLocker,
                        std::string desc) {


    if(client == nullptr) throw ModelException("Client not set");
    if(package == nullptr) throw ModelException("package not set");
    if(parcelLocker == nullptr) throw ModelException("parcelLocker not set");

    std::shared_ptr<Order> order = std::make_shared<Order>(id, desc, client, package, parcelLocker);
    currentOrders.add(order);
    return order;
}

std::vector<OrderPtr> OrderManager::getClientOrder(std::string orderId) {
    return currentOrders.findBy(PredicateByOrderId(orderId));
}

std::vector<OrderPtr> OrderManager::getAllClientOrders(ClientPtr client) {
    std::vector<OrderPtr> allClientOrders;
    for(auto x : currentOrders.findAll())
    {
        if(x->getClient() == client) allClientOrders.push_back(x);
    }
    for(auto x : archiveOrders.findAll())
    {
        if(x->getClient() == client) allClientOrders.push_back(x);
    }
    return allClientOrders;
}

void OrderManager::updateOrder(OrderPtr order, Order::segment orderState) {
    order->updateOrder(orderState);
}

void OrderManager::changeOrderParcelLocker(ParcelLockerPtr parcelLock,OrderPtr order) {
    if(order->getOrderState() > 2) throw ModelException("Package is already on the way");
    order->setParcelLocker(parcelLock);
}

double OrderManager::checkClientOrderBalance(ClientPtr client) {
    double value = 0;
    for(auto x:currentOrders.findAll()){
        if(x->getClient() == client){
            value += x->getOrderCost();
        }
    }
    for(auto x:archiveOrders.findAll()){
        if(x->getClient() == client){
            value += x->getOrderCost();
        }
    }
    return value;
}

void OrderManager::changeClientType(ClientPtr client) {
    std::shared_ptr<Default> clientDefault = std::make_shared<Default>();
    std::shared_ptr<Silver> clientSilver = std::make_shared<Silver>();
    std::shared_ptr<Gold> clientGold = std::make_shared<Gold>();
    std::shared_ptr<Diamond> clientDiamond = std::make_shared<Diamond>();
    if(checkClientOrderBalance(client) > 500){
        client->setClientType(clientDiamond);
    } else if(checkClientOrderBalance(client) > 100)
    {
        client->setClientType(clientGold);
    } else if (checkClientOrderBalance(client) > 25)
    {
        client->setClientType(clientSilver);
    } else
    {
        client->setClientType(clientDefault);
    }
}

std::vector<OrderPtr> OrderManager::findOrders(OrderPredicate predicate) {
    return currentOrders.findBy(predicate);
}

std::vector<OrderPtr> OrderManager::findAllOrders() {
    auto function = [&](const OrderPtr &ptr) -> bool { (void)ptr; return true; };
    return findOrders(function);
}

OrderManager::OrderManager() {}

OrderManager::~OrderManager() {

}

int OrderManager::getSize() {
    return currentOrders.getSize();
}

