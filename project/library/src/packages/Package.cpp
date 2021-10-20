#include "model/Package.h"
#include "math.h"

double Package::getPackagePrice() {
    return packageType->getPackagePrice();
}

Package::Package(boost::uuids::uuid id, double weight, int priority, bool fragile, bool paid, const PackageTypePtr &packageType) : id(
        id), weight(weight), priority(priority), fragile(fragile), paid(paid), packageType(packageType) {}

Package::~Package() {

}

const std::string Package::getInfo() const {
    std::string temp1, temp2;
    if(fragile) temp1 = "yes";
    else temp1 = "no";
    if(paid) temp2 = "yes";
    else temp2 = "no";
    return "Priority: "+ std::to_string(priority) + ", Weight: " + std::to_string((int)(weight)) + ", fragile?: " + temp1 + ", paid?: " + temp2 + ", Package type: " + packageType->getPackageInfo();
}

const boost::uuids::uuid &Package::getId() const {
    return id;
}

double Package::getWeight() const {
    return weight;
}

int Package::getPriority() const {
    return priority;
}

bool Package::isFragile() const {
    return fragile;
}

bool Package::isPaid() const {
    return paid;
}

const PackageTypePtr &Package::getPackageType() const {
    return packageType;
}

void Package::setPaid(bool paidd) {
    Package::paid = paidd;
}

const std::string Package::getPackageTypeRoot() const {
    return packageType->getPackageInfoRoot();
}
