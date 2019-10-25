#include <iostream>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

int main(){
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::cout << boost::uuids::to_string(uuid) << std::endl;
    # fc60577b-23ef-4921-bc36-f0453ae2c755
    return 0;
}
