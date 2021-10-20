#ifndef PARCELLOCKERPROJECT_PARCELLOCKER_H
#define PARCELLOCKERPROJECT_PARCELLOCKER_H

#include <string>
#include "typedefs.h"

class ParcelLocker {
public:
    ParcelLocker(AddressPtr address, const std::string &lockerId, int freePlaces);
    virtual ~ParcelLocker();
    bool areAvailablePlaces();
    const std::string getInfo() const;
    AddressPtr getAddress();
    const std::string &getLockerId() const;
    int getFreePlaces() const;
    void setAddress(const AddressPtr &address);
    void setFreePlaces(int freePlaces);
    void packPackage();
    bool isArchive() const;
    void setArchive(bool a);

private:
    AddressPtr address;
    const std::string lockerID;
    int freePlaces;
    bool archive;

};


#endif //PARCELLOCKERPROJECT_PARCELLOCKER_H
