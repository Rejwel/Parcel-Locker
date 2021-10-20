
#include <functions.h>
#include "predicates/PredicateByPackageId.h"
#include "model/Package.h"

bool PredicateByPackageId::operator()(PackagePtr ptr) {
    return personalId == boost::uuids::to_string(ptr->getId());
}

PredicateByPackageId::PredicateByPackageId(std::string personalId) : personalId(personalId){

}
