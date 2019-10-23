#include <fstream>
#include <vector>
#include <iomanip> //setw
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(){
    std::ifstream is("i_data.json");
    json i_data;
    is >> i_data;

    std::vector<std::string> ids = i_data["id"];
    std::vector<int> counts = i_data["count"];

    json o_data;
    o_data["id"] = ids;
    o_data["count"] = counts;

    std::ofstream os("o_data.json");
    os << std::setw(4) << o_data << std::endl;
    std::cout << "write complete" << std::endl;
    return 0;
}

/* the content of i_data.json:
{
    "count": [
        1,
        7,
        10,
        1,
        5,
        8,
        10
    ],
    "id": [
        "f75045bc-077a-40d1-90d8-1a9b902c2350",
        "231a6c61-86db-4d19-b491-b5dedd284fcf",
        "6a58f656-ee20-11e9-b358-531a71ed02aa",
        "2a65ef3a-ee21-11e9-9668-45cb6e7d2d2f",
        "d474a044-fd50-4ab4-bf34-5186520d0ff6",
        "69359f4d-bd95-4f77-aae2-35f423eeea82",
        "42b6a822-a97a-4a97-9732-aecba6fbb890"
    ]
}
*/
