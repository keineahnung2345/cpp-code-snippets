#include <iostream>

#include <Eigen/Dense>

// https://stackoverflow.com/questions/2573726/how-to-use-boostcrc
// https://stackoverflow.com/questions/5100718/integer-to-hex-string-in-c
std::string getCrc32(const std::string& str) {
    boost::crc_32_type result;
    result.process_bytes(str.data(), str.length());
    return (std::stringstream() << std::hex << result.checksum()).str();
}

template <typename T>
std::string getCrc32(const T& value) {
    return getCrc32((std::stringstream() << value).str());
}

int main() {
    Eigen::Matrix4f m = Eigen::Matrix4f::Zero();
    std::cout << getCrc32(m) << std::endl; // 9e4d0581
    return 0;
}
