#include "predicates/PredicateTrue.h"

PredicateTrue::PredicateTrue() {

}

bool PredicateTrue::operator()() {
    return true;
}
