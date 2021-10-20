#ifndef PARCELLOCKERPROJECT_CLIENTTYPEEXCEPTION_H
#define PARCELLOCKERPROJECT_CLIENTTYPEEXCEPTION_H

#include <string>
#include <stdexcept>

class ClientTypeException : public std::logic_error {
public:
    explicit ClientTypeException(const char* msg) throw();
    virtual const char* what() const throw();
};


#endif //PARCELLOCKERPROJECT_CLIENTTYPEEXCEPTION_H
