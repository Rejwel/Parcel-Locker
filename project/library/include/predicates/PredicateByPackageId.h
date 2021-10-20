//
// Created by student on 02.06.2021.
//

#ifndef PARCELLOCKERPROJECT_PREDICATEBYPACKAGEID_H
#define PARCELLOCKERPROJECT_PREDICATEBYPACKAGEID_H
#include "typedefs.h"
#include <string>
#include <boost/uuid/uuid.hpp>

class PredicateByPackageId {
public:
    explicit PredicateByPackageId(std::string personalId);
    bool operator()(PackagePtr ptr);

private:
    std::string personalId;
};


#endif //PARCELLOCKERPROJECT_PREDICATEBYPACKAGEID_H
