#ifndef PARCELLOCKERPROJECT_MODELEXCEPTION_H
#define PARCELLOCKERPROJECT_MODELEXCEPTION_H

#include <string>
#include <stdexcept>

class ModelException : public std::logic_error {
public:
    explicit ModelException(const char* msg) throw();
    virtual const char* what() const throw();
};


#endif //PARCELLOCKERPROJECT_MODELEXCEPTION_H
