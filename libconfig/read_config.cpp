#include <iostream>
#include <iomanip>
#include <libconfig.h++>

int main(int argc, char** argv) {
    libconfig::Config cfg;
    cfg.readFile("config.txt");
    std::cout << "==============================" << std::endl;
    std::cout << "configs: " << std::endl;
    constlibconfig::Setting& root = cfg.getRoot();
    for (libconfig::SettingConstIterator it = root.begin(); it != root.end(); ++it) {
        switch (it->getType()) {
        case libconfig::Setting::TypeInt: {
            int val = root.lookup(it->getName());
            std::cout << std::setw(25) << it->getName() << std::setw(20) << " (TypeInt) : " << val << std::endl;
            break;
        }
        case libconfig::Setting::TypeInt64: {
            long long val = root.lookup(it->getName());
            std::cout << std::setw(25) << it->getName() << std::setw(20) << " (TypeInt64) : " << val << std::endl;
            break;
        }
        case libconfig::Setting::TypeFloat: {
            float val = root.lookup(it->getName());
            std::cout << std::setw(25) << it->getName() << std::setw(20) << " (TypeFloat) : " << val << std::endl;
            break;
        }
        case libconfig::Setting::TypeString: {
            std::string val = root.lookup(it->getName());
            std::cout << std::setw(25) << it->getName() << std::setw(20) << " (TypeString) : " << val << std::endl;
            break;
        }
        case libconfig::Setting::TypeBoolean: {
            bool val = root.lookup(it->getName());
            std::cout << std::setw(25) << it->getName() << std::setw(20) << " (TypeBoolean) : " << (val ? "true" : "false") << std::endl;
            break;
        }
        case libconfig::Setting::TypeGroup:
        case libconfig::Setting::TypeArray:
        case libconfig::Setting::TypeList:
            std::cout << std::setw(25) << it->getName() << " (TypeGroup, TypeArray or TypeList)" << std::endl;
            break;
        default:
            std::cout << std::setw(25) << it->getName() << " (None)" << std::endl;
        }
    }
}
