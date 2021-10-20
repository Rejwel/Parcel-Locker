#ifndef PARCELLOCKERPROJECT_DIAMOND_H
#define PARCELLOCKERPROJECT_DIAMOND_H

#include "ClientType.h"

class Diamond : public ClientType {
public:
    Diamond();
    virtual ~Diamond();
    double applyDiscount(double price) override;
    const std::string getTypeInfo() const override;
    const std::string getTypeInfoRoot() const override;
};


#endif //PARCELLOCKERPROJECT_DIAMOND_H
