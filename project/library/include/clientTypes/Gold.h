#ifndef PARCELLOCKERPROJECT_GOLD_H
#define PARCELLOCKERPROJECT_GOLD_H

#include "ClientType.h"

class Gold : public ClientType {
public:
    Gold();
    virtual ~Gold();
    double applyDiscount(double price) override;
    const std::string getTypeInfo() const override;
    const std::string getTypeInfoRoot() const override;
};


#endif //PARCELLOCKERPROJECT_GOLD_H
