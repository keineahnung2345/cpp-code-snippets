#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Class1 {
private:
    std::string s;
    int         i;
    float       f;
};

#define YourClass Class1

void speedTest() {
    std::ofstream ps_file("../../pointer_speed.csv");
    ps_file << "raw create"
            << ","
            << "raw total"
            << ","
            << "unqiue create"
            << ","
            << "unqiue total"
            << ","
            << "shared create"
            << ","
            << "shared total"
            << ","
            << "obj create"
            << ","
            << "obj total"
            << ","
            << "total" << std::endl;
    for(size_t t = 0; t < 100; ++t) {
        int times = 100000;

        auto start_total = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point start_raw;
        std::chrono::system_clock::time_point created_raw;
        std::chrono::system_clock::time_point end_raw;
        {
            std::vector<YourClass*> yourClasses(times);
            start_raw = std::chrono::system_clock::now();

            for(size_t i = 0; i < times; ++i) {
                yourClasses[i] = new YourClass();
            }
            created_raw = std::chrono::system_clock::now();

            for(size_t i = 0; i < times; ++i) {
                delete yourClasses[i];
            }
            end_raw = std::chrono::system_clock::now();
        }
        auto diff_create_raw =
            std::chrono::duration_cast<std::chrono::microseconds>(created_raw -
                                                                  start_raw);
        auto diff_raw = std::chrono::duration_cast<std::chrono::microseconds>(
            end_raw - start_raw);
        std::cout << "raw create/total: " << diff_create_raw << "/" << diff_raw
                  << std::endl;
        ps_file << diff_create_raw.count() << "," << diff_raw.count() << ",";

        std::chrono::system_clock::time_point start_unique;
        std::chrono::system_clock::time_point created_unique;
        std::chrono::system_clock::time_point end_unique;
        {
            std::vector<std::unique_ptr<YourClass>> yourClasses(times);
            start_unique = std::chrono::system_clock::now();

            for(size_t i = 0; i < times; ++i) {
                yourClasses[i] = std::make_unique<YourClass>();
            }

            created_unique = std::chrono::system_clock::now();
            yourClasses.clear();
            end_unique = std::chrono::system_clock::now();
        }
        auto diff_create_unique =
            std::chrono::duration_cast<std::chrono::microseconds>(
                created_unique - start_unique);
        auto diff_unique =
            std::chrono::duration_cast<std::chrono::microseconds>(end_unique -
                                                                  start_unique);
        std::cout << "unique create/total: " << diff_create_unique << "/"
                  << diff_unique << std::endl;
        ps_file << diff_create_unique.count() << "," << diff_unique.count()
                << ",";

        std::chrono::system_clock::time_point start_shared;
        std::chrono::system_clock::time_point created_shared;
        std::chrono::system_clock::time_point end_shared;
        {
            std::vector<std::shared_ptr<YourClass>> yourClasses(times);

            start_shared = std::chrono::system_clock::now();
            for(size_t i = 0; i < times; ++i) {
                yourClasses[i] =
                    std::make_shared<YourClass>();
            }
            created_shared = std::chrono::system_clock::now();
            yourClasses.clear();
            end_shared = std::chrono::system_clock::now();
        }
        auto diff_create_shared =
            std::chrono::duration_cast<std::chrono::microseconds>(
                created_shared - start_shared);
        auto diff_shared =
            std::chrono::duration_cast<std::chrono::microseconds>(end_shared -
                                                                  start_shared);
        std::cout << "shared create/total: " << diff_create_shared << "/"
                  << diff_shared << std::endl;
        ps_file << diff_create_shared.count() << "," << diff_shared.count()
                << ",";

        std::chrono::system_clock::time_point start_obj;
        std::chrono::system_clock::time_point created_obj;
        std::chrono::system_clock::time_point end_obj;
        {
            std::vector<YourClass> yourClasses;
            yourClasses.reserve(times);
            start_obj = std::chrono::system_clock::now();

            for(size_t i = 0; i < times; ++i) {
                yourClasses.emplace_back();
            }
            created_obj = std::chrono::system_clock::now();
            yourClasses.clear();
            end_obj = std::chrono::system_clock::now();
        }
        auto diff_create_obj =
            std::chrono::duration_cast<std::chrono::microseconds>(created_obj -
                                                                  start_obj);
        auto diff_obj = std::chrono::duration_cast<std::chrono::microseconds>(
            end_obj - start_obj);
        std::cout << "obj create/total: " << diff_create_obj << "/" << diff_obj
                  << std::endl;
        ps_file << diff_create_obj.count() << "," << diff_obj.count() << ",";

        auto end_total  = std::chrono::system_clock::now();
        auto diff_total = std::chrono::duration_cast<std::chrono::microseconds>(
            end_total - start_total);
        std::cout << "Total " << diff_total << std::endl;
        ps_file << diff_total.count() << std::endl;
    }
    ps_file.close();
}

int main(int argc, char** argv) {
    speedTest();
    return 0;
}
