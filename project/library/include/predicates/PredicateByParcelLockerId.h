#ifndef PARCELLOCKERPROJECT_PREDICATEBYPARCELLOCKERID_H
#define PARCELLOCKERPROJECT_PREDICATEBYPARCELLOCKERID_H

#include "typedefs.h"

class PredicateByParcelLockerId {
public:
    explicit PredicateByParcelLockerId(const std::string &Id);
    bool operator()(ParcelLockerPtr ptr);

private:
    std::string Id;
};


#endif //PARCELLOCKERPROJECT_PREDICATEBYPARCELLOCKERID_H
