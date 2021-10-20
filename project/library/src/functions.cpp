#include "functions.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time.hpp>

std::string getTestTime(){
    std::stringstream ss;
    ss << boost::posix_time::second_clock::local_time() << " not-a-date-time";
    return ss.str();
}

boost::uuids::uuid generateUUID()
{
    return boost::uuids::random_generator()();
}