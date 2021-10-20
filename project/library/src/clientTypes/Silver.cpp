#include "clientTypes/Silver.h"

Silver::Silver() {}

Silver::~Silver() {

}

double Silver::applyDiscount(double price) {
    (void) price;
    return 6;
}

const std::string Silver::getTypeInfo() const {
    return "Silver" + ClientType::getTypeInfo();
}

const std::string Silver::getTypeInfoRoot() const {
    return "silver";
}
