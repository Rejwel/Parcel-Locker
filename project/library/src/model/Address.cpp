#include "model/Address.h"

const std::string Address::getInfo() const {
    return street + " " + number + " " + city;
}

Address::Address(const std::string &city, const std::string &street, const std::string &number) : city(city),
                                                                                                  street(street),number(number) {
}

Address::~Address() {

}

const std::string &Address::getCity() const {
    return city;
}

const std::string &Address::getStreet() const {
    return street;
}

const std::string &Address::getNumber() const {
    return number;
}

void Address::setCity(const std::string &c) {
    Address::city = c;
}

void Address::setStreet(const std::string &s) {
    Address::street = s;
}

void Address::setNumber(const std::string &n) {
    Address::number = n;
}
