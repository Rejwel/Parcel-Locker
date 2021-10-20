//
// Created by student on 02.06.2021.
//

#ifndef PARCELLOCKERPROJECT_PACKAGEMANAGER_H
#define PARCELLOCKERPROJECT_PACKAGEMANAGER_H

#include <vector>
#include <boost/uuid/uuid.hpp>
#include "typedefs.h"
#include "model/Repository.h"
class Package;

class PackageManager {
private:
    Repository<Package> PackageRepository;
public:
    PackageManager();

    virtual ~PackageManager();

    PackagePtr registerPackage(boost::uuids::uuid id,double weight, int priority,bool fragile,bool paid,PackageTypePtr PackageType);
    std::vector<PackagePtr> getPackage(boost::uuids::uuid id);
    std::vector<PackagePtr> findPackage(PackagePredicate predicate);
    std::vector<PackagePtr> findAllPackages();
    void payForPackage(PackagePtr package);
    int getSize();
};


#endif //PARCELLOCKERPROJECT_PACKAGEMANAGER_H
