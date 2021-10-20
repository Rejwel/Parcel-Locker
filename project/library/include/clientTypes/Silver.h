#ifndef PARCELLOCKERPROJECT_SILVER_H
#define PARCELLOCKERPROJECT_SILVER_H

#include "ClientType.h"

class Silver : public ClientType{
public:
    Silver();
    virtual ~Silver();
    double applyDiscount(double price) override;
    const std::string getTypeInfo() const override;
    const std::string getTypeInfoRoot() const override;
};


#endif //PARCELLOCKERPROJECT_SILVER_H
