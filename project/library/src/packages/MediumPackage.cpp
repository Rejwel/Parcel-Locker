#include "packages/MediumPackage.h"

MediumPackage::MediumPackage() {}

MediumPackage::~MediumPackage() {

}

double MediumPackage::getPackagePrice() {
    double wynik;
    wynik = 15;
    return wynik;
}

std::string MediumPackage::getPackageInfo() {
    return "Medium Package, price: " + std::to_string((int)getPackagePrice());
}

std::string MediumPackage::getPackageInfoRoot() {
    return "mediumPackage";
}
