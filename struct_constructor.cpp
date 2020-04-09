#include <vector>
#include <string>

using namespace std;

struct Kernel{
    string name;
    vector<float> arr;
    float coef;
    int kernelSize;
    int kernelMiddle;

    Kernel(string n, vector<float> a, float c) : name(n), arr(a), coef(c){
        kernelSize = (int)(sqrt(a.size()));
        kernelMiddle = kernelSize/2;
    };
};

vector<Kernel*> kernels = {
    new Kernel("SmoothAvg", {1,1,1,1,1,1,1,1,1}, 1.0/9)
    , new Kernel("SmoothGauss", {1,2,1,2,4,2,1,2,1}, 1.0/16)
    , new Kernel("VerticalSoble", {-1,0,1, -2,0,2, -1,0,1}, 1.0)
    , new Kernel("HorizontalSobel", {-1,-2,-1, 0,0,0, -1,-2,-1}, 1.0)
    , new Kernel("LogEdgeDetection", {0,0,-1,0,0, 0,-1,-2,-1,0, -1,-2,16,-2,-1, 0,-1,-2,-1,0, 0,0,-1,0,0}, 1.0)
    , new Kernel("LaplacianEdgeDetection1", {0,-1,0, -1,4,-1, 0,-1,0}, 1.0)
    , new Kernel("LaplacianEdgeDetection2", {-1,-1,-1, -1,8,-1, -1,-1,-1}, 1.0)
};
