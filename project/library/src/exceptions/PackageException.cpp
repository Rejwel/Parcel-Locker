#include "exceptions/PackageException.h"

PackageException::PackageException(const char *msg) throw(): logic_error(msg) {

}

const char *PackageException::what() const throw() {
    return logic_error::what();
}
