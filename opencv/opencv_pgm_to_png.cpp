#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

inline void readPGMFile(const std::string& fileName, uint8_t* buffer, int inH, int inW)
{
    std::ifstream infile(fileName, std::ifstream::binary);
    assert(infile.is_open() && "Attempting to read from a file that is not open.");
    std::string magic, w, h, max;
    infile >> magic >> w >> h >> max;
    assert(std::stoi(w) == inW);
    assert(std::stoi(h) == inH);
    std::cout << "magic: " << magic << std::endl;
    std::cout << "w: " << w << std::endl;
    std::cout << "h: " << h << std::endl;
    std::cout << "max: " << max << std::endl;
    infile.seekg(1, infile.cur);
    infile.read(reinterpret_cast<char*>(buffer), inH * inW);
}

//g++ read_pgm.cpp `pkg-config --cflags --libs opencv4` -std=c++11
//https://people.sc.fsu.edu/~jburkardt/data/pgmb/pgmb.html
//https://answers.opencv.org/question/81831/convert-stdvectordouble-to-mat-and-show-the-image/

int main(){
    std::string fname = "feep";
    int w = 24, h = 7, maxVal = 15;
    std::vector<uint8_t> buffer(h*w);
    readPGMFile(fname + ".pgm", buffer.data(), h, w);
    // Print ASCII representation of digit
    std::cout << "Input:\n";
    for (int i = 0; i < h * w; i++)
    {
        //(x+9)/10: round up
        std::cout << (" .:-=+*#%@"[buffer[i]/((maxVal+9)/10)]) << (((i + 1) % w) ? "" : "\n");
    }
    std::cout << std::endl;

    // scale the maxVal to 255 for better visualization
    for(int i = 0; i < h * w; i++){
        buffer[i] = buffer[i] * 255/maxVal;
    }

    if(buffer.size() == w * h) // check that the rows and cols match the size of your vector
    {
        cv::Mat m = cv::Mat(h, w, CV_8UC1); // initialize matrix of uchar of 1-channel where you will store vec data
        //copy vector to mat
        memcpy(m.data, buffer.data(), buffer.size()*sizeof(uint8_t)); // change uchar to any type of data values that you want to use instead
        cv::imwrite(fname + ".png", m);
    }

    return 0;
}

/*
magic: P5
w: 24
h: 7
max: 15
Input:
                        
 ....  ----  ++++  #### 
 .     -     +     #  # 
 ...   ---   +++   #### 
 .     -     +     #    
 .     ----  ++++  #    
                        

*/
