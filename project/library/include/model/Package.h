#ifndef PARCELLOCKERPROJECT_PACKAGE_H
#define PARCELLOCKERPROJECT_PACKAGE_H

#include <boost/uuid/uuid.hpp>
#include "../packages/PackageType.h"
#include "../typedefs.h"

class Package {
private:
    boost::uuids::uuid id;
    double weight; // weight cannot be a negative value
    int priority; // priority from 1 - 5 where 5 is highest value
    bool fragile;
    bool paid;
    PackageTypePtr packageType;

public:
    Package(boost::uuids::uuid id, double weight, int priority, bool fragile, bool paid, const PackageTypePtr &packageType);
    virtual ~Package();
    double getPackagePrice();
    const std::string getInfo() const;

    void setPaid(bool paidd);

    const boost::uuids::uuid &getId() const;

    double getWeight() const;

    int getPriority() const;

    bool isFragile() const;

    bool isPaid() const;

    const PackageTypePtr &getPackageType() const;
    const std::string getPackageTypeRoot() const;
};


#endif //PARCELLOCKERPROJECT_PACKAGE_H
