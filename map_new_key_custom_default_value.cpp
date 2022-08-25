#include <iostream>
#include <map>

#ifdef PCL_INSTALLED
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#endif

// https://stackoverflow.com/questions/2333728/stdmap-default-value
// https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
// https://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
// https://stackoverflow.com/questions/21569483/c-overloading-dereference-operators

struct IntWithDefaultValue {
    int  i = -1;
         operator int() const { return i; }
    int &operator=(const int &i_in) {
        i = i_in;
        return i;
    }
};

struct StringWithDefaultValue {
    std::string  s = "defaultstring";
                 operator std::string() const { return s; }
    std::string &operator=(const std::string &s_in) {
        s = s_in;
        return s;
    }
    friend std::ostream &operator<<(std::ostream &                os,
                                    const StringWithDefaultValue &swdv) {
        os << swdv.s;
        return os;
    }
};

#ifdef PCL_INSTALLED

struct CloudPtrDefaultedToEmpty {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud =
        pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    operator pcl::PointCloud<pcl::PointXYZ>::Ptr() const { return cloud; }
    pcl::PointCloud<pcl::PointXYZ> &     operator*() { return *cloud; }
    pcl::PointCloud<pcl::PointXYZ>::Ptr  operator->() { return cloud; }
    pcl::PointCloud<pcl::PointXYZ>::Ptr &operator=(
        const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud_in) {
        cloud = cloud_in;
        return cloud;
    }
};

struct CloudIPtrDefaultedToEmpty {
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud =
        pcl::PointCloud<pcl::PointXYZI>::Ptr(
            new pcl::PointCloud<pcl::PointXYZI>);
    operator pcl::PointCloud<pcl::PointXYZI>::Ptr() const { return cloud; }
    pcl::PointCloud<pcl::PointXYZI> &     operator*() { return *cloud; }
    pcl::PointCloud<pcl::PointXYZI>::Ptr  operator->() { return cloud; }
    pcl::PointCloud<pcl::PointXYZI>::Ptr &operator=(
        const pcl::PointCloud<pcl::PointXYZI>::Ptr &cloud_in) {
        cloud = cloud_in;
        return cloud;
    }
};
#endif

int main() {
    std::map<std::string, IntWithDefaultValue> intmap;
    std::cout << intmap["hello"] << std::endl;  // -1
    intmap["bye"] = 2;
    std::cout << intmap["bye"] << std::endl;  // 2

    std::map<std::string, StringWithDefaultValue> strmap;
    std::cout << strmap["a"] << std::endl;  // defaultstring

#ifdef PCL_INSTALLED
    CloudPtrDefaultedToEmpty cloud1, cloud2;
    std::cout << cloud1->size() << std::endl;

    for(size_t i = 0; i < 10; ++i) {
        cloud1->push_back(pcl::PointXYZ(1.0f * i, 2.0f * i, 3.0f * i));
    }
    std::cout << cloud1->size() << std::endl;

    for(size_t i = 0; i < 10; ++i) {
        cloud2->push_back(pcl::PointXYZ(-1.0f * i, -2.0f * i, -3.0f * i));
    }
    std::cout << cloud2->size() << std::endl;

    *cloud1 += *cloud2;
    std::cout << cloud1->size() << std::endl;
#endif
    return 0;
}

/*
-1
2
defaultstring
0
10
10
20
*/
