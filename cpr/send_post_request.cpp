#include "cpr/cpr.h"
#include <nlohmann/json.hpp>
#include <iostream>

int main(){
    nlohmann::json req_body;
    std::string s = "abc";
    bool b = false;
    int i = 1234;
    req_body["s"] = s;
    req_body["b"] = b;
    req_body["i"] = i;
    auto response = cpr::Post(cpr::Url{"http://0.0.0.0:8182/mysubpage"},
                            cpr::Body{req_body.dump()},
                            cpr::Header{{"Content-Type", "application/json"}});
    if(response.status_code == 200){
        std::cout << "Parse response..." << std::endl;
        auto result = nlohmann::json::parse(response.text);
        std::cout << result["r"] << std::endl;
    }
    return 0;
}
