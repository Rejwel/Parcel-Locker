#include "predicates/PredicateByClientId.h"
#include "model/Client.h"

PrediaceByClientId::PrediaceByClientId(const std::string &personalId) : personalId(personalId) {}

bool PrediaceByClientId::operator()(ClientPtr ptr) {
    return personalId == ptr->getPersonalId();
}

