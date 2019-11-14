#include "crow_all.h"

//export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<boost_installation_dir>/lib
//g++ main.cpp -I <crow_dir>/amalgamate -L <boost_installation_dir>/lib -lboost_system -lboost_thread -lpthread -std=c++11

//https://github.com/ipkn/crow/blob/master/examples/example.cpp

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/test").methods("POST"_method)([](){
        return "Hello world";
    });
    
    // enables all log
    app.loglevel(crow::LogLevel::DEBUG);
    app.port(18080).multithreaded().run();
}
