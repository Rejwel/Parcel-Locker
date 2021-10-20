#ifndef PARCELLOCKERPROJECT_PREDICATEBYLOGIN_H
#define PARCELLOCKERPROJECT_PREDICATEBYLOGIN_H

#include "typedefs.h"
#include <string>

class PredicateByLogin {

public:
    explicit PredicateByLogin(const std::string &login);
    bool operator()(ClientPtr ptr);

private:
    std::string login;

};


#endif //PARCELLOCKERPROJECT_PREDICATEBYLOGIN_H
