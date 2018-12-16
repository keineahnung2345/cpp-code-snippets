#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <vector>

int main() {
    std::vector<std::pair<std::string, int> > scores;
    scores.push_back(std::make_pair("Emily", 99));
    scores.push_back(std::make_pair("Nick", 80));
    scores.push_back(std::make_pair("Steven", 75));

    for(std::pair<std::string, int> p : scores){
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}
