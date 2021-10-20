#ifndef PARCELLOCKERPROJECT_PREDICATEBYCLIENTID_H
#define PARCELLOCKERPROJECT_PREDICATEBYCLIENTID_H

#include "typedefs.h"
#include <string>

class PrediaceByClientId {

public:
    explicit PrediaceByClientId(const std::string &personalId);
    bool operator()(ClientPtr ptr);

private:
    std::string personalId;

};

#endif //PARCELLOCKERPROJECT_PREDICATEBYCLIENTID_H
