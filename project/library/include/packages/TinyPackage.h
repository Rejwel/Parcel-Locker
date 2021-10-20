#ifndef PARCELLOCKERPROJECT_TINYPACKAGE_H
#define PARCELLOCKERPROJECT_TINYPACKAGE_H

#include "PackageType.h"

class TinyPackage : public PackageType{
public:
    TinyPackage();
    virtual ~TinyPackage();

    std::string getPackageInfo() override;
    double getPackagePrice() override;
    std::string getPackageInfoRoot() override;
};


#endif //PARCELLOCKERPROJECT_TINYPACKAGE_H
