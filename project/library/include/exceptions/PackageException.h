#ifndef PARCELLOCKERPROJECT_PACKAGEEXCEPTION_H
#define PARCELLOCKERPROJECT_PACKAGEEXCEPTION_H

#include <string>
#include <stdexcept>

class PackageException : public std::logic_error {
public:
    explicit PackageException(const char* msg) throw();
    virtual const char* what() const throw();
};


#endif //PARCELLOCKERPROJECT_PACKAGEEXCEPTION_H
