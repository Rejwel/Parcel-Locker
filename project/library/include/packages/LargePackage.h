#ifndef PARCELLOCKERPROJECT_LARGEPACKAGE_H
#define PARCELLOCKERPROJECT_LARGEPACKAGE_H

#include "PackageType.h"

class LargePackage : public PackageType{
public:
    LargePackage();
    virtual ~LargePackage();

    std::string getPackageInfo() override;
    double getPackagePrice() override;
    std::string getPackageInfoRoot() override;
};



#endif //PARCELLOCKERPROJECT_LARGEPACKAGE_H
