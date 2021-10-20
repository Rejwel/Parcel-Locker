#ifndef PARCELLOCKERPROJECT_MEDIUMPACKAGE_H
#define PARCELLOCKERPROJECT_MEDIUMPACKAGE_H
#include "PackageType.h"

class MediumPackage : public PackageType{
public:
    MediumPackage();
    virtual ~MediumPackage();

    double getPackagePrice() override;
    std::string getPackageInfo() override;
    std::string getPackageInfoRoot() override;
};


#endif //PARCELLOCKERPROJECT_MEDIUMPACKAGE_H
