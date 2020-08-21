#include <iostream>
#include <vector>

using namespace std;

//https://stackoverflow.com/questions/6399090/c-convert-vectorint-to-vectordouble

int main()
{
    vector<int> vi = {1,2,3};
    vector<double> vd(vi.begin(), vi.end());
    
    for(double& d: vd){
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
