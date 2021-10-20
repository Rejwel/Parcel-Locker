#ifndef PARCELLOCKERPROJECT_ADDRESS_H
#define PARCELLOCKERPROJECT_ADDRESS_H

#include <string>

class Address {
public:
    Address(const std::string &city, const std::string &street, const std::string &number);
    virtual ~Address();
    const std::string getInfo() const;
    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;
    void setCity(const std::string &c);
    void setStreet(const std::string &s);
    void setNumber(const std::string &n);


private:
    std::string city;
    std::string street;
    std::string number;
};


#endif //PARCELLOCKERPROJECT_ADDRESS_H
