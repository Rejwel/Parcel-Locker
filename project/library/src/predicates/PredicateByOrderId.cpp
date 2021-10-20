#include "predicates/PredicateByOrderId.h"
#include "model/Order.h"
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>

PredicateByOrderId::PredicateByOrderId(const std::string &tempId): tempId(tempId) {

}

bool PredicateByOrderId::operator()(OrderPtr ptr) {
    return boost::lexical_cast<std::string>(ptr->getId()) == tempId;
}
