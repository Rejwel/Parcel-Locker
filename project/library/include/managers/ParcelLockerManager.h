#ifndef PARCELLOCKERPROJECT_PARCELLOCKERMANAGER_H
#define PARCELLOCKERPROJECT_PARCELLOCKERMANAGER_H

#include <vector>
#include "typedefs.h"
#include "model/Repository.h"
class ParcelLocker;


class ParcelLockerManager {
public:
    ParcelLockerManager();

    virtual ~ParcelLockerManager();

    ParcelLockerPtr registerParcelLocker(std::string id, int freePlaces, AddressPtr address);
    AddressPtr createNewAddress(std::string city, std::string street, std::string number);
    void unregisterParcelLocker(ParcelLockerPtr parcelLocker);
    std::vector<ParcelLockerPtr> getParcelLocker(std::string lockerId);
    std::vector<ParcelLockerPtr> findParcelLockers(ParcelLockerPredicate predicate);
    std::vector<ParcelLockerPtr> findAllParcelLockers();
    int getSize();


private:
    Repository<ParcelLocker> ParcelLockerRepository;
};


#endif //PARCELLOCKERPROJECT_PARCELLOCKERMANAGER_H
