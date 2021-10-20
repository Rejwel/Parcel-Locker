#ifndef PARCELLOCKERPROJECT_SAVEFILESMANAGER_H
#define PARCELLOCKERPROJECT_SAVEFILESMANAGER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time.hpp>
#include "ClientManager.h"
#include "PackageManager.h"
#include "ParcelLockerManager.h"
#include "OrderManager.h"
#include "typedefs.h"

class SaveFilesManager {
public:
    SaveFilesManager(ClientManagerPtr clientManager, PackageManagerPtr packageManager,
                     OrderManagerPtr orderManager, ParcelLockerManagerPtr parcelLockerManager);
    virtual ~SaveFilesManager();
    void save();
    void load();

private:
    ClientManagerPtr clientManager;
    PackageManagerPtr packageManager;
    OrderManagerPtr orderManager;
    ParcelLockerManagerPtr parcelLockerManager;
};


#endif //PARCELLOCKERPROJECT_SAVEFILESMANAGER_H
