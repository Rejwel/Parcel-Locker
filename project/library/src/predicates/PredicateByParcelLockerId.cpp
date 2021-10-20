#include "predicates/PredicateByParcelLockerId.h"
#include "model/ParcelLocker.h"

PredicateByParcelLockerId::PredicateByParcelLockerId(const std::string &Id) : Id(Id) {

}

bool PredicateByParcelLockerId::operator()(ParcelLockerPtr ptr) {
    return ptr->getLockerId() == Id;
}
