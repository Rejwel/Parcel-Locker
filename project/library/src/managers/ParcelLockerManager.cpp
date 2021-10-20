#include "managers/ParcelLockerManager.h"
#include "exceptions/ModelException.h"
#include "predicates/PredicateByParcelLockerId.h"
#include "model/ParcelLocker.h"
#include "model/Address.h"

ParcelLockerPtr ParcelLockerManager::registerParcelLocker(std::string id, int freePlaces, AddressPtr address) {
    for(auto x : ParcelLockerRepository.findAll())
    {
        if(x->getLockerId() == id) throw ModelException("There is already locker with this id");
    }
    if(id.empty()) throw ModelException("Empty id");
    if(freePlaces <= 0) throw ModelException("Available places cannot be value 0 or less");
    if(address == nullptr) throw ModelException("Address nullptr");

    std::shared_ptr<ParcelLocker> parcelLocker = std::make_shared<ParcelLocker>(address, id, freePlaces);
    ParcelLockerRepository.add(parcelLocker);
    return parcelLocker;
}

AddressPtr ParcelLockerManager::createNewAddress(std::string city, std::string street, std::string number) {
    if(city.empty()) throw ModelException("Empty city");
    if(street.empty()) throw ModelException("Empty street");
    if(number.empty()) throw ModelException("Empty number");

    std::shared_ptr<Address> address = std::make_shared<Address>(city, street, number);
    return address;
}

void ParcelLockerManager::unregisterParcelLocker(ParcelLockerPtr parcelLocker) {
    if(parcelLocker->isArchive()) throw ModelException("Parcel locker is already archived");
    else parcelLocker->setArchive(true);
}

std::vector<ParcelLockerPtr> ParcelLockerManager::getParcelLocker(std::string lockerId) {
    return ParcelLockerRepository.findBy(PredicateByParcelLockerId(lockerId));
}

std::vector<ParcelLockerPtr> ParcelLockerManager::findParcelLockers(ParcelLockerPredicate predicate) {
    return ParcelLockerRepository.findBy(predicate);
}

std::vector<ParcelLockerPtr> ParcelLockerManager::findAllParcelLockers() {
    auto function = [&](const ParcelLockerPtr &ptr) -> bool { (void)ptr; return true; };
    return findParcelLockers(function);
}

int ParcelLockerManager::getSize() {
    return ParcelLockerRepository.getSize();
}

ParcelLockerManager::ParcelLockerManager() {}

ParcelLockerManager::~ParcelLockerManager() {

}
