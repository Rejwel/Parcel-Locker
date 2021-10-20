#include "packages/LargePackage.h"

std::string LargePackage::getPackageInfo() {
    return "Large Package, price: " + std::to_string((int)getPackagePrice());
}

double LargePackage::getPackagePrice() {
    double wynik;
    wynik = 20;
    return wynik;
}

LargePackage::LargePackage() {}

LargePackage::~LargePackage() {

}

std::string LargePackage::getPackageInfoRoot() {
    return "largePackage";
}
