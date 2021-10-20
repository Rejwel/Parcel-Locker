#include "managers/ClientManager.h"
#include "exceptions/ModelException.h"
#include "model/Client.h"
#include "clientTypes/Default.h"
#include "predicates/PredicateByClientId.h"
#include "predicates/PredicateTrue.h"

ClientPtr ClientManager::registerClient(std::string login, std::string password, std::string firstName, std::string lastName, std::string personalId,
                                        ClientTypePtr clientType) {
    for(auto x : findAllClients())
    {
        if(x->getLogin() == login) throw ModelException("this login is already in use");
    }
    if(login == password) throw ModelException("login same as password");
    if(firstName.empty()) throw ModelException("Empty first name");
    if(lastName.empty()) throw ModelException("Empty last name");
    if(personalId.empty()) throw ModelException("Empty personalId");
    if(clientType == nullptr) clientType = std::make_shared<Default>();

    std::shared_ptr<Client> client = std::make_shared<Client>(login, password, firstName, lastName, personalId, clientType);
    ClientRepository.add(client);
    return client;
}

void ClientManager::unregisterClient(ClientPtr client) {
    if(client->isArchive()) throw ModelException("Client is already archived");
    else client->setArchive(true);
}

std::vector<ClientPtr> ClientManager::getClient(std::string id) {
    return ClientRepository.findBy(PrediaceByClientId(id));
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    return ClientRepository.findBy(predicate);
}

std::vector<ClientPtr> ClientManager::findAllClients() {
    auto function = [&](const ClientPtr &ptr) -> bool { return !ptr->isArchive(); };
    return findClients(function);
}

int ClientManager::getSize() {
    return ClientRepository.getSize();
}

const std::string ClientManager::getReport(ClientPtr client) const{
    return ClientRepository.getReport(client);
}

const std::string ClientManager::getAllReport() const {
    return ClientRepository.getAllReport();
}

ClientManager::ClientManager() {}

ClientManager::~ClientManager() {

}
