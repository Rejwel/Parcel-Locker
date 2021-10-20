#ifndef PARCELLOCKERPROJECT_DEFAULT_H
#define PARCELLOCKERPROJECT_DEFAULT_H

#include "ClientType.h"

class Default : public ClientType {
public:
    Default();
    virtual ~Default();
    double applyDiscount(double price) override;
    const std::string getTypeInfo() const override;
    const std::string getTypeInfoRoot() const override;
};


#endif //PARCELLOCKERPROJECT_DEFAULT_H
