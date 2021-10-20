#include "clientTypes/Default.h"

Default::Default() {}

Default::~Default() {

}

double Default::applyDiscount(double price) {
    (void) price;
    return 0;
}

const std::string Default::getTypeInfo() const {
    return "Default" + ClientType::getTypeInfo();
}

const std::string Default::getTypeInfoRoot() const {
    return "default";
}
