#include "exceptions/ModelException.h"

ModelException::ModelException(const char *msg) throw(): logic_error(msg) {

}

const char *ModelException::what() const throw() {
    return logic_error::what();
}
