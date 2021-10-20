#ifndef PARCELLOCKERPROJECT_SMALLPACKAGE_H
#define PARCELLOCKERPROJECT_SMALLPACKAGE_H
#include "PackageType.h"


class SmallPackage : public PackageType{
public:
    SmallPackage();
    virtual ~SmallPackage();

    double getPackagePrice() override;
    std::string getPackageInfo() override;
    std::string getPackageInfoRoot() override;
};


#endif //PARCELLOCKERPROJECT_SMALLPACKAGE_H
