#include "exceptions/ClientTypeException.h"

ClientTypeException::ClientTypeException(const char *msg) throw(): logic_error(msg) { }

const char *ClientTypeException::what() const throw() {
    return logic_error::what();
}
