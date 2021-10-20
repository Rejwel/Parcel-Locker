#ifndef PARCELLOCKERPROJECT_CLIENT_H
#define PARCELLOCKERPROJECT_CLIENT_H

#include <string>
#include "typedefs.h"

class Client {
public:
    Client(std::string login, std::string password, const std::string &firstName, const std::string &lastName, const std::string &personalId,
           const ClientTypePtr &clientType);
    virtual ~Client();
    double applyDiscount(double price);
    void setClientType(ClientTypePtr type);
    const ClientTypePtr &getClientType() const;
    const std::string getClientTypeRoot() const;
    const std::string getInfo() const;
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;
    bool isArchive() const;
    void setArchive(bool a);
    const std::string &getLogin() const;
    const std::string &getPassword() const;


private:
    std::string login;
    std::string password;
    const std::string firstName;
    const std::string lastName;
    const std::string personalID;
    bool archive;
    ClientTypePtr clientType;
};


#endif //PARCELLOCKERPROJECT_CLIENT_H
