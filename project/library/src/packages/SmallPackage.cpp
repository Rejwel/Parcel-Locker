#include "packages/SmallPackage.h"

double SmallPackage::getPackagePrice() {
    double wynik;
    wynik = 10;
    return wynik;
}

std::string SmallPackage::getPackageInfo() {
    return "Small Package, price: " + std::to_string((int)getPackagePrice());
}

SmallPackage::SmallPackage() {}

SmallPackage::~SmallPackage() {

}

std::string SmallPackage::getPackageInfoRoot() {
    return "smallPackage";
}
