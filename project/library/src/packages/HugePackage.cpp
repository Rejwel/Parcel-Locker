#include "packages/HugePackage.h"

std::string HugePackage::getPackageInfo() {
    return "Huge Package, price: " + std::to_string((int)getPackagePrice());
}

double HugePackage::getPackagePrice() {
    double wynik;
    wynik = 30;
    return wynik;
}

HugePackage::HugePackage() {}

HugePackage::~HugePackage() {

}

std::string HugePackage::getPackageInfoRoot() {
    return "hugePackage";
}
