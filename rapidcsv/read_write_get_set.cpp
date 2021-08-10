#include "rapidcsv.h"
#include <filesystem>
#include <iostream>

int main() {
    //read
    rapidcsv::Document doc("test.csv", rapidcsv::LabelParams(0, 0));

    //get
    int kevin_grade, jack_grade;
    std::string steven_parent;

    kevin_grade = doc.GetCell<int>("grade", "Kevin");
    jack_grade = doc.GetCell<int>("grade", "Jack");
    steven_parent = doc.GetCell<std::string>("parent", "Steven");

    std::cout << "Kevin's grade: " << kevin_grade << std::endl;
    std::cout << "Jack's grade: " << jack_grade << std::endl;
    std::cout << "Steven's parent: " << steven_parent << std::endl;

    //set
    doc.SetCell<int>("grade", "Marry", 80);
    doc.SetCell<std::string>("parent", "Apple", "Antony");

    //write
    std::string outfolder = std::filesystem::current_path().string();
    if (!outfolder.empty()) outfolder += "\\";
    std::string outpath = outfolder + "overwrite.csv";
    std::cout << "output to: " << outpath << std::endl;
    std::ofstream ostream;
    ostream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    ostream.open(outpath, std::ios::binary | std::ios::ate);
    doc.Save(ostream);
    ostream.close();

    return 0;
}
