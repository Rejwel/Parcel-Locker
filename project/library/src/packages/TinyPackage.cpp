#include "packages/TinyPackage.h"

std::string TinyPackage::getPackageInfo() {
    return "Tiny Package, price: " + std::to_string((int)getPackagePrice());
}

double TinyPackage::getPackagePrice() {
    double wynik;
    wynik = 5;
    return wynik;;
}

TinyPackage::TinyPackage() {}

TinyPackage::~TinyPackage() {

}

std::string TinyPackage::getPackageInfoRoot() {
    return "tinyPackage";
}
