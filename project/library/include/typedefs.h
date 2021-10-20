#ifndef PARCELLOCKERPROJECT_TYPEDEFS_H
#define PARCELLOCKERPROJECT_TYPEDEFS_H

#include <memory>
#include <functional>

class PackageType;
class Address;
class ClientType;
class Client;
class Package;
class ParcelLocker;
class Order;
class ClientManager;
class OrderManager;
class PackageManager;
class ParcelLockerManager;
class SaveFilesManager;

typedef std::shared_ptr<PackageType> PackageTypePtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Package> PackagePtr;
typedef std::shared_ptr<ParcelLocker> ParcelLockerPtr;
typedef std::shared_ptr<Order> OrderPtr;

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(PackagePtr)> PackagePredicate;
typedef std::function<bool(ParcelLockerPtr)> ParcelLockerPredicate;
typedef std::function<bool(OrderPtr)> OrderPredicate;

typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<OrderManager> OrderManagerPtr;
typedef std::shared_ptr<PackageManager> PackageManagerPtr;
typedef std::shared_ptr<ParcelLockerManager> ParcelLockerManagerPtr;
typedef std::shared_ptr<SaveFilesManager> SaveFilesManagerPtr;

#endif //PARCELLOCKERPROJECT_TYPEDEFS_H