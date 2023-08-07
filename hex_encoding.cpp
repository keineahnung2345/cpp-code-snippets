#include <iomanip>
#include <iostream>
#include <sstream>

// https://stackoverflow.com/questions/5760252/how-can-i-print-0x0a-instead-of-0xa-using-cout
// https://stackoverflow.com/questions/673240/how-do-i-print-an-unsigned-char-as-hex-in-c-using-ostream
// https://www.geeksforgeeks.org/convert-hex-string-to-signed-integer-in-cpp/

std::string to_hex(const std::string& str) {
    std::stringstream ss;
    for(unsigned char c : str) {
        ss << std::hex << std::setfill('0') << std::setw(2) << (0xFF & c);
    }
    return ss.str();
}

std::string un_hex(const std::string& str) {
    std::string strUnhex(str.size() / 2, ' ');
    for(size_t i = 0; i < strUnhex.size(); ++i) {
        strUnhex[i] =
            (unsigned char)std::stoul(str.substr(i * 2, 2), nullptr, 16);
    }
    return strUnhex;
}

int main() {
    unsigned char arr[4] = { 0, 10, 100, 127 };
    std::string   str(reinterpret_cast<char*>(arr), 4);

    std::string strHex = to_hex(str);
    std::cout << strHex << std::endl;

    std::string strUnhex = un_hex(strHex);
    for(const char& c : strUnhex) {
        std::cout << (unsigned int)c << ", ";
    }
    std::cout << std::endl;

    return 0;
}
