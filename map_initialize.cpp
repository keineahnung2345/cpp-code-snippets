#include <map>
#include <unordered_map>

using namespace std;

//https://stackoverflow.com/questions/138600/initializing-a-static-stdmapint-int-in-c

int main()
{
    map<int, char> m = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
    unordered_map<int, char> um = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};

    return 0;
}
