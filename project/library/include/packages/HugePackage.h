#ifndef PARCELLOCKERPROJECT_HUGEPACKAGE_H
#define PARCELLOCKERPROJECT_HUGEPACKAGE_H

#include "PackageType.h"


class HugePackage : public PackageType{
public:
    HugePackage();
    virtual ~HugePackage();
    std::string getPackageInfo() override;
    double getPackagePrice() override;
    std::string getPackageInfoRoot() override;
};


#endif //PARCELLOCKERPROJECT_HUGEPACKAGE_H
