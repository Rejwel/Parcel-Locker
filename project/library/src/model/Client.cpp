#include "model/Client.h"
#include "clientTypes/ClientType.h"
#include "exceptions/ClientTypeException.h"

Client::Client(std::string login, std::string password, const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const ClientTypePtr &clientType) : login(login), password(password), firstName(firstName), lastName(lastName), personalID(personalId),
                                                  clientType(clientType) {
    archive = false;
}

Client::~Client() {

}

double Client::applyDiscount(double price) {
    return clientType->applyDiscount(price);
}

void Client::setClientType(ClientTypePtr type) {
    if(type != nullptr) Client::clientType = std::move(type);
}

const std::string Client::getInfo() const {
    return firstName + " " + lastName + "[" + personalID + "]" + ", " + clientType->getTypeInfo();
}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getPersonalId() const {
    return personalID;
}

bool Client::isArchive() const {
    return archive;
}

void Client::setArchive(bool a) {
    Client::archive = a;
}

const std::string &Client::getLogin() const {
    return login;
}

const std::string &Client::getPassword() const {
    return password;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

const std::string Client::getClientTypeRoot() const {
    return clientType->getTypeInfoRoot();
}
