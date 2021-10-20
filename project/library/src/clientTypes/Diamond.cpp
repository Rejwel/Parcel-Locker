#include "clientTypes/Diamond.h"

Diamond::Diamond() {}

Diamond::~Diamond() {

}

double Diamond::applyDiscount(double price) {
    double multiplier;
    multiplier = price < 10 ? 0.1 :
                 price < 50 ? 0.2 :
                 price < 100 ? 0.3 :
                 price >= 200 ? 0.4 : 0;
    return multiplier * price;
}

const std::string Diamond::getTypeInfo() const {
    return "Diamond" + ClientType::getTypeInfo();
}

const std::string Diamond::getTypeInfoRoot() const {
    return "diamond";
}
