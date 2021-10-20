#include "managers/SaveFilesManager.h"
#include <nlohmann/json.hpp>
#include <model/ParcelLocker.h>
#include <model/Order.h>
#include <model/Client.h>
#include <model/Package.h>
#include <packages/PackageType.h>
#include <model/Address.h>
#include <typedefs.h>

SaveFilesManager::SaveFilesManager(ClientManagerPtr clientManager, PackageManagerPtr packageManager,
                                   OrderManagerPtr orderManager,
                                   ParcelLockerManagerPtr parcelLockerManager) : clientManager(clientManager),
                                                                                        packageManager(packageManager),
                                                                                        orderManager(orderManager),
                                                                                        parcelLockerManager(
                                                                                                parcelLockerManager) {}

SaveFilesManager::~SaveFilesManager() {

}

void SaveFilesManager::save() {
    std::stringstream ss;
    std::ofstream outFile("savedFiles.json", std::ios_base::out);
    namespace pt = boost::property_tree;
    pt::ptree root;
    pt::write_json(std::cout, root);

    //saving parcelLockers
    pt::ptree parcelLockersNode;
    for(auto x : parcelLockerManager->findAllParcelLockers()) {
        pt::ptree parcelLockerNode;
        parcelLockerNode.put("city", x->getAddress()->getCity());
        parcelLockerNode.put("street", x->getAddress()->getStreet());
        parcelLockerNode.put("number", x->getAddress()->getNumber());
        parcelLockerNode.put("id", x->getLockerId());
        parcelLockerNode.put("freePlaces", x->getFreePlaces());
        parcelLockersNode.push_back(std::make_pair("", parcelLockerNode));
    }
    root.add_child("lockers", parcelLockersNode);

    //saving clients
    pt::ptree clientsNode;
    for(auto x : clientManager->findAllClients()) {
        pt::ptree clientNode;
        clientNode.put("login", x->getLogin());
        clientNode.put("password", x->getPassword());
        clientNode.put("firstName", x->getFirstName());
        clientNode.put("lastName", x->getLastName());
        clientNode.put("id", x->getPersonalId());
        clientNode.put("clientType", x->getClientTypeRoot());
        clientsNode.push_back(std::make_pair("", clientNode));
    }
    root.add_child("clients", clientsNode);

    //saving clients
    pt::ptree packagesNode;
    for(auto x : packageManager->findAllPackages()) {
        pt::ptree packageNode;
       packageNode.put("id", boost::lexical_cast<std::string>(x->getId()));
       packageNode.put("weight", x->getWeight());
       packageNode.put("priority", x->getPriority());
       packageNode.put("fragile", x->isFragile());
       packageNode.put("paid", x->isPaid());
       packageNode.put("packageType", x->getPackageTypeRoot());
       packagesNode.push_back(std::make_pair("", packageNode));
    }
    root.add_child("package", packagesNode);

//    pt::ptree ordersNode;
//    for(auto x : orderManager->findAllOrders()) {
//        pt::ptree orderNode;
//        orderNode.put("orderId", boost::lexical_cast<std::string>(x->getId()));
//        orderNode.put("packageId", x->getAPackage()->getId());
//        orderNode.put("parcelLockerId", x->getParcelLocker()->getLockerId());
//        orderNode.put("desc", x->getClientDesc());
//        ordersNode.push_back(std::make_pair("", orderNode));
//    }
//    root.add_child("orders", ordersNode);

//    std::string j("{ \"Object1\" : { \"param1\" : 10.0, \"initPos\" : { \"\":1.0, \"\":2.0, \"\":5.0 }, \"initVel\" : [ 0.0, 0.0, 0.0 ] } }");
//    std::istringstream iss(j);
//    pt::ptree temp;
//    boost::property_tree::json_parser::read_json(iss, temp);

//    pt::ptree &pos = temp.get_child("Object1.initPos");
//    std::for_each(std::begin(pos), std::end(pos), [](pt::ptree::value_type& kv) {
//        std::cout << "K: " << kv.first << std::endl;
//        std::cout << "V: " << kv.second.get<std::string>("") << std::endl;
//    });


    pt::write_json(ss, root);
    outFile << ss.rdbuf();
    outFile.close();
}

void SaveFilesManager::load() {
//    namespace pt = boost::property_tree;
//    pt::ptree root;
//    pt::read_json("savedFiles.json", root);
//    if(root.empty()) std::cout << ":(";
//    else std::cout << ":)";
//
//
//    std::string city,street,number,id,freePlaces;
//    for (auto x : root.get_child("lockers"))
//    {
////        x.
////        std::cout << "a" << x.second.data() << "a";
//        if(x.first == "city") city = x.second.data();
//        if(x.first == "street") street = x.second.data();
//        if(x.first == "number") number = x.second.data();
//        if(x.first == "id") id = x.second.data();
//        if(x.first == "freePlaces") freePlaces = x.second.data();
//    }
//    std::cout << city << " " << street << " " << number << " " << id << " " << freePlaces;
////    parcelLockerManager->registerParcelLocker(id, std::stoi(freePlaces), parcelLockerManager->createNewAddress(city,street,number));

}
