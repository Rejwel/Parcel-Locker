#ifndef PARCELLOCKERPROJECT_CLIENTMANAGER_H
#define PARCELLOCKERPROJECT_CLIENTMANAGER_H

#include <vector>
#include "typedefs.h"
#include "model/Repository.h"
class Client;

class ClientManager {
public:
    ClientManager();
    virtual ~ClientManager();

    ClientPtr registerClient(std::string login, std::string password, std::string firstName, std::string lastName, std::string personalId,
                        ClientTypePtr clientType);
    void unregisterClient(ClientPtr client);
    int getSize();
    const std::string getReport(ClientPtr client) const;
    const std::string getAllReport() const;
    std::vector<ClientPtr> getClient(std::string id);
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
    std::vector<ClientPtr> findAllClients();

private:
    Repository<Client> ClientRepository;

};


#endif //PARCELLOCKERPROJECT_CLIENTMANAGER_H
