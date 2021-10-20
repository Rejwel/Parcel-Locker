#ifndef PARCELLOCKERPROJECT_PREDICATEBYPERSONALNAME_H
#define PARCELLOCKERPROJECT_PREDICATEBYPERSONALNAME_H

#include <string>
#include "typedefs.h"

class PredicateByPersonalName {
public:
    explicit PredicateByPersonalName(const std::string &str);
    bool operator()(ClientPtr ptr);

private:
    std::string expr;
};


#endif //PARCELLOCKERPROJECT_PREDICATEBYPERSONALNAME_H
