#include "predicates/PredicateByPersonalName.h"
#include <boost/regex.hpp>
#include "model/Client.h"

PredicateByPersonalName::PredicateByPersonalName(const std::string &str) {
    expr = str + "*";
}

bool PredicateByPersonalName::operator()(ClientPtr ptr) {
    boost::regex e(expr);
    boost::smatch what;
    boost::regex_search(ptr->getFirstName(),what,e);
    return what[0].matched;
}