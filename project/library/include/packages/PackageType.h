#ifndef PARCELLOCKERPROJECT_PACKAGETYPE_H
#define PARCELLOCKERPROJECT_PACKAGETYPE_H

#include <string>

class PackageType {
public:
    PackageType();
    virtual ~PackageType();
    virtual double getPackagePrice() = 0;
    virtual std::string getPackageInfo();
    virtual std::string getPackageInfoRoot() = 0;
};


#endif //PARCELLOCKERPROJECT_PACKAGETYPE_H
