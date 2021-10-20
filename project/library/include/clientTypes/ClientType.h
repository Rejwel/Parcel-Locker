#ifndef PARCELLOCKERPROJECT_CLIENTTYPE_H
#define PARCELLOCKERPROJECT_CLIENTTYPE_H

#include <string>

class ClientType {
public:
    ClientType();
    virtual ~ClientType() = 0;
    virtual double applyDiscount(double price) = 0;
    virtual const std::string getTypeInfo() const;
    virtual const std::string getTypeInfoRoot() const = 0;
};


#endif //PARCELLOCKERPROJECT_CLIENTTYPE_H
