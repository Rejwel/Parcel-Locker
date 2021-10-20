#ifndef PARCELLOCKERPROJECT_PREDICATEBYORDERID_H
#define PARCELLOCKERPROJECT_PREDICATEBYORDERID_H

#include "typedefs.h"
#include <string>
#include <boost/uuid/uuid.hpp>

class PredicateByOrderId {
public:
    explicit PredicateByOrderId(const std::string &tempId);
    bool operator()(OrderPtr ptr);

private:
    std::string tempId;
    boost::uuids::uuid id;
};


#endif //PARCELLOCKERPROJECT_PREDICATEBYORDERID_H
