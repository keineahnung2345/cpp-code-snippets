#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// https://stackoverflow.com/questions/12133379/c-using-ifstream-with-getline
// https://stackoverflow.com/questions/16446665/c-read-from-csv-file
// https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
// https://cplusplus.com/reference/string/string/getline/

int main() {
    std::string fname = "abc.csv";

    std::ofstream outfile(fname);
    for(size_t i = 0; i < 10; ++i) {
        outfile << i << "," << i + 3.14 << "," << std::string(1, ('a' + i))
                << "\n";
    }
    outfile.close();

    std::ifstream infile(fname);
    int           i;
    float         f;
    std::string   s;
    for(std::string line; std::getline(infile, line);) {
        std::string        i_str, f_str;
        std::istringstream ss(line);
        std::getline(ss, i_str, ',');
        std::getline(ss, f_str, ',');
        std::getline(ss, s, ',');
        if(i_str.empty() || f_str.empty() || s.empty()) continue;
        i = std::stoi(i_str);
        f = std::stof(f_str);
        std::cout << i << ", " << f << ", " << s << std::endl;
    }
    return 0;
}

/*
0, 3.14, a
1, 4.14, b
2, 5.14, c
3, 6.14, d
4, 7.14, e
5, 8.14, f
6, 9.14, g
7, 10.14, h
8, 11.14, i
9, 12.14, j
*/
