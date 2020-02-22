#include <string>
#include <vector>
#include <iostream>

//https://stackoverflow.com/questions/15619696/convert-vectorstring-to-vectorint-c-win32

int main(){
    std::vector<std::string> vs = {"2018", "3", "11"};
    std::vector<int> vi;

    std::transform(vs.begin(), vs.end(), std::back_inserter(vi),
        [](const std::string& s) { return std::stoi(s); });

    std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}

//2018 3 11
