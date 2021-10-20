#include "model/ParcelLocker.h"
#include "model/Address.h"
#include "exceptions/ModelException.h"


ParcelLocker::ParcelLocker(AddressPtr address, const std::string &lockerId, int freePlaces) : address(address),
                                                                                                     lockerID(lockerId),
                                                                                                     freePlaces(freePlaces) {
    archive = false;
}

ParcelLocker::~ParcelLocker() {

}

bool ParcelLocker::areAvailablePlaces() {
    if(freePlaces > 0) return true;
    return false;
}

const std::string ParcelLocker::getInfo() const {
    return "[" + lockerID + "] " + address->getInfo() + ", Available places: " + std::to_string(freePlaces);
}

AddressPtr ParcelLocker::getAddress() {
    return address;
}

const std::string &ParcelLocker::getLockerId() const {
    return lockerID;
}

int ParcelLocker::getFreePlaces() const {
    return freePlaces;
}

void ParcelLocker::setAddress(const AddressPtr &add) {
    ParcelLocker::address = add;
}

void ParcelLocker::setFreePlaces(int places) {
    if(places >= 0) ParcelLocker::freePlaces = places;
}

void ParcelLocker::packPackage() {
    if(areAvailablePlaces() > 0) freePlaces--;
    else throw ModelException("There is no available places.");
}

void ParcelLocker::setArchive(bool a) {
    ParcelLocker::archive = a;
}

bool ParcelLocker::isArchive() const {
    return archive;
}



