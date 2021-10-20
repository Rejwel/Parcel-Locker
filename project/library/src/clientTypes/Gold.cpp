#include "clientTypes/Gold.h"

Gold::Gold() {}

Gold::~Gold() {

}

double Gold::applyDiscount(double price) {
    return price * 0.1;
}

const std::string Gold::getTypeInfo() const {
    return "Gold" + ClientType::getTypeInfo();
}

const std::string Gold::getTypeInfoRoot() const {
    return "gold";
}
