#ifndef PARCELLOCKERPROJECT_FUNCTIONS_H
#define PARCELLOCKERPROJECT_FUNCTIONS_H

#include <string>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time.hpp>

// generating testTime for tests
std::string getTestTime();

// generating random UUID
boost::uuids::uuid generateUUID();


#endif //PARCELLOCKERPROJECT_FUNCTIONS_H
