#include "predicates/PredicateByLogin.h"
#include "model/Client.h"

PredicateByLogin::PredicateByLogin(const std::string &login): login(login) {

}

bool PredicateByLogin::operator()(ClientPtr ptr) {
    return login == ptr->getLogin();
}
