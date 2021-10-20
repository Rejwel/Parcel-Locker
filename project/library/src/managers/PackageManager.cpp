#include <functions.h>
#include "managers/PackageManager.h"
#include "predicates/PredicateByPackageId.h"
#include "model/Package.h"
#include "exceptions/PackageException.h"

PackagePtr PackageManager::registerPackage(boost::uuids::uuid id, double weight, int priority, bool fragile,bool paid,
                                           PackageTypePtr PackageType) {
    if(getPackage(id).size() > 0) throw PackageException("This package already exist");
    if(weight <= 0) throw PackageException("Weight is less than 0");
    if(priority < 1 || priority > 5 ) throw PackageException("Out of range priority");
    if(PackageType == nullptr) throw PackageException("Packaging type not selected");
    std::shared_ptr<Package> package = std::make_shared<Package>(id,weight,priority,fragile,paid,PackageType);
    PackageRepository.add(package);
    return package;
}

std::vector<PackagePtr> PackageManager::getPackage(boost::uuids::uuid id) {
    return PackageRepository.findBy(PredicateByPackageId(boost::uuids::to_string(id)));
}

std::vector<PackagePtr> PackageManager::findPackage(PackagePredicate predicate) {
    return PackageRepository.findBy(predicate);
}

std::vector<PackagePtr> PackageManager::findAllPackages() {
    auto function = [&](const PackagePtr &ptr) -> bool { (void)ptr; return true; };
    return findPackage(function);
}

void PackageManager::payForPackage(PackagePtr package) {
    package->setPaid(true);
}

int PackageManager::getSize() {
    return PackageRepository.getSize();
}

PackageManager::PackageManager() {}

PackageManager::~PackageManager() {

}
